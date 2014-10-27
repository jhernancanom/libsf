//////////
//
// primes235.cpp
//
//////
//
// Formulas in search:
//
//		x = 2
//		y = 3
//		z = 5
//      __________________ _________________ _________________
//     |     a b      c   |    a b      c   |    a b      c   |
//     |    x y  +/- z    |   x z  +/- y    |   y z  +/- x    |
//     |__________________|_________________|_________________|
//
//




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long int s64;

#define _X		2
#define _Y		3
#define _Z		5

#define _XYZ	1
#define _XZY	2
#define _YZX	3

#define _MAX_PRIMES 3000000
#define _EXPONENT	100

int		gnFoundCount			= 0;
int		gnMaxUniques			= 0;
s64		gnLargestPrimeFound		= 0;
s64		primesFound[_MAX_PRIMES][2];



//////////
//
// Stores the found primes
//
//////
	void storeFoundPrime(s64 p, s64 a, s64 b, s64 c, s64 type, bool isPlus)
	{
		int lnI;


		// If this is the first find, initialize the primesFound
		if (gnFoundCount == 0)
			memset(&primesFound, 0, sizeof(primesFound));

		// Increase our counts
		++gnFoundCount;
		gnLargestPrimeFound = ((p > gnLargestPrimeFound) ? p : gnLargestPrimeFound);

		// Search for the prime found
		for (lnI = 0; lnI < _MAX_PRIMES && primesFound[lnI][0] != 0; lnI++)
		{
			if (primesFound[lnI][0] == p)
			{
				++primesFound[lnI][1];
				return;
			}
		}

		// If we get here, not found
		primesFound[lnI][0] = p;
		primesFound[lnI][1] = 1;

		// Set the unique count
		gnMaxUniques = lnI;

// 		switch (type)
// 		{
// 			case _XYZ:
// 				if (isPlus)		printf("%u = 2^%u * 3^%u + 5^%u\n", p, a, b, c);
// 				else			printf("%u = 2^%u * 3^%u - 5^%u\n", p, a, b, c);
// 				break;
// 
// 			case _XZY:
// 				if (isPlus)		printf("%u = 2^%u * 5^%u + 3^%u\n", p, a, b, c);
// 				else			printf("%u = 2^%u * 5^%u - 3^%u\n", p, a, b, c);
// 				break;
// 
// 			case _YZX:
// 				if (isPlus)		printf("%u = 3^%u * 5^%u + 2^%u\n", p, a, b, c);
// 				else			printf("%u = 3^%u * 5^%u - 2^%u\n", p, a, b, c);
// 				break;
// 		}
	}





//////////
//
// Called to check if the number is prime
//
//////
	bool isPrime(s64 tnValue)
	{
		s64 lnI, lnTarget;


		if (tnValue % 2 == 0 || tnValue % 3 == 0 || tnValue % 5 == 0)
			return(false);

		return(true);

		// Special case for negatives
		if (tnValue < 0)
			return(false);

		// Handle constants
		if (tnValue == 1 || tnValue == 2 || tnValue == 3 || tnValue == 5 || tnValue == 7)
			return(true);

		// Perform simple tests
		if (tnValue % 2 == 0 || tnValue % 5 == 0)
			return(false);

		// Iterate up to sqrt(tnValue)
		lnTarget = (int)(sqrt((double)tnValue));
		for (lnI = 3; lnI <= lnTarget; lnI += 2)
		{
			// Does it divide by this?
			if (tnValue % lnI == 0)
				return(false);
		}

		// If we get here, it's prime
		return(true);
	}




//////////
//
// Called to raise value to the indicated power
//
//////
	s64 pow(s64 value, s64 count)
	{
		s64 power;


		// Iterate to the power
		for (power = value; count > 1; count--)
			power *= value;

		// Return our result
		return(power);
	}




//////////
//
// Main program entry point
//
//////
	int main(int argc, char* argv[])
	{
		int		lnI, lnJ;
		s64		a, b, c, xn, yn, zn, p, m;
		bool	llFound;


		// Work for 1.._EXPONENT
		for (a = 1; a < _EXPONENT; a++)
		{
			for (b = 1; b < _EXPONENT; b++)
			{
				for (c = 1; c < _EXPONENT; c++)
				{
					//////////
					//  __________________ 
					// |     a b      c   |
					// |    x y  +/- z    |
					// |__________________|
					//////
						xn	= pow(_X, a);
						yn	= pow(_Y, b);
						zn	= pow(_Z, c);
						p	= (xn * yn) + zn;
						m	= (xn * yn) - zn;
						if (isPrime(p))		storeFoundPrime(p, a, b, c, _XYZ, true);
						if (isPrime(m))		storeFoundPrime(m, a, b, c, _XYZ, false);
						

					//////////
					//  _________________ 
					// |    a b      c   |
					// |   x z  +/- y    |
					// |_________________|
					//////
						xn	= pow(_X, a);
						zn	= pow(_Z, b);
						yn	= pow(_Y, c);
						p	= (xn * zn) + yn;
						m	= (xn * zn) - yn;
						if (isPrime(p))		storeFoundPrime(p, a, b, c, _XZY, true);
						if (isPrime(m))		storeFoundPrime(m, a, b, c, _XZY, false);
						

					//////////
					//  _________________
					// |    a b      c   |
					// |   y z  +/- x    |
					// |_________________|
					//////
						yn	= pow(_Y, a);
//						zn	= pow(_Z, b);
						xn	= pow(_X, c);
						p	= (yn * zn) + xn;
						m	= (yn * zn) - xn;
						if (isPrime(p))		storeFoundPrime(p, a, b, c, _YZX, true);
						if (isPrime(m))		storeFoundPrime(m, a, b, c, _YZX, false);
				}
			}
			printf("%u, found %u, unique %u, largest %d\n", a, gnFoundCount, gnMaxUniques, (int)gnLargestPrimeFound);
		}

		// Iterate through each prime
		for (lnI = 1; lnI <= 1000; lnI++)
		{
			if (isPrime(lnI))
			{
				llFound = false;
				for (lnJ = 0; lnJ < gnMaxUniques; lnJ++)
				{
					if (primesFound[lnJ][0] == (s64)lnI)
					{
						llFound = true;
//						printf("%d, %d\n", (int)primesFound[lnJ][0], (int)primesFound[lnJ][1]);
						break;
					}
				}
				if (!llFound)
					printf("%d, %d\n", lnI, 0);
			}
		}

		FILE* lfh = fopen("c:\\temp\\primes.txt", "wb+");
		fwrite(&primesFound, 16, gnMaxUniques, lfh);
		fclose(lfh);

		// All finished
		return 0;
	}
