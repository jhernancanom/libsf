//////////
//
// /libsf/source/unsorted/dna_project_butterfly/butterfly/butterfly.cpp
//
//////
// Version 0.01
// Copyright (c) 2015 by Rick C. Hodgin
//////
// Last update:
//     Feb.15.2015
//////
// Change log:
//     Feb.15.2015 - Initial creation
//////
//
// This document is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// The PBL is a public domain license with a caveat:  self accountability unto God.
// You are free to use, copy, modify and share this software for any purpose, however,
// it is the desire of those working on this project that the software remain open.
// It is our request that you maintain it that way.  This is not a legal request unto
// our court systems, but rather a personal matter between you and God.  Our talents
// were received from God, and given to you through this forum.  And it is our wish
// that those talents reach out to as many as possible in a form allowing them to wield
// this content for their own betterment, as you are now considering doing.  And whereas
// we could've forced the issue through something like a copyleft-protected release, the
// truth is we are all giving an account of our lives unto God continually by the daily
// choices we make.  And here again is another case where you get to demonstrate your
// character unto God, and unto your fellow man.
//
// Jesus came to this Earth to set the captives free, to save men's eternal souls from
// the punishment demanded by our sin.  Each one of us is given the opportunity to
// receive Him in this world and be saved.  Whether we choose to receive Him, and follow
// Him, and purpose our lives on the goals He has for each of us (all of which are
// beneficial for all involved), is one way we reveal our character continually.  God
// sees straight through to the heart, bypassing all of the words, all of the facades.
// He is our Creator, and He knows who we are truly.
//
// Jesus is called "Christ" because He saves men from the eternal flames of Hell, the
// just punishment of rebellion against God (rebellion against truth) by eternal beings,
// which each of us are.
//
// Do not let His free gift escape you because of some desire to shortcut what is right
// in your life. Instead, do what is right, and do it because He is who He is, and what
// He has done to save us from such a fate.  Demonstrate to Him, to me, and to all of
// mankind, and to all of the Heavenly hosts, exactly who you are on the inside.  Receive
// Jesus Christ into your heart, learn of Him, of how He came here to guide us into that
// which is of His Kingdom and will be forever hereafter we leave this world.  Do this,
// and live.
//
// Every project released by Liberty Software Foundation will include a copy of the
// pbl.txt document, which can be found at http://www.libsf.org/licenses/.
//
// For additional information about this project, or to view the license, see:
//
//     http://www.libsf.org/
//     http://www.libsf.org/licenses/
//     http://www.visual-freepro.org/vjr/indexmain.html
//     http://www.visual-freepro.org/wiki/index.php/PBL
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//




#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#define debug_break	_asm int 3

#include "/libsf/utils/common/cpp/common_types.h"
#include "/libsf/utils/common/cpp/builder.h"


//////////
// Function prototype
//////
	bool		iConvert_fasta					(void);
	bool		iSearch_bitwidth				(s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg);
	bool		iSearch_bitspace				(s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg);
	s32			iiCountToNeedleInHaystack		(s8* haystack, s8 needle, s32 count);
	bool		iSearch_bitspaceAuto			(void);




//////////
//
// DNA Project Butterfly
//
//////
	int main(int argc, char **argv)
	{
		bool llShowHelp;


		//////////
		// Command line options
		//////
			printf("LibSF -- DNA Project Butterfly -- Feb.15.2015\n");
			printf("See Google Groups: https://groups.google.com/forum/#!forum/dnaprojectbutterfly\n");

			// Process the option
			     if (_memicmp(argv[1], "fasta", 5) == 0)			llShowHelp = !iConvert_fasta();									// Convert dp_genome_v3.fasta file to outputs
			else if (_memicmp(argv[1], "bitwidth:", 9) == 0)		llShowHelp = !iSearch_bitwidth(argv[1] + 9, argv[2], argv[3]);	// Search for successive bits of the indicated size
			else if (_memicmp(argv[1], "bitspace:", 9) == 0)		llShowHelp = !iSearch_bitspace(argv[1] + 9, argv[2], argv[3]);	// Search for successive bits of the indicated size
			else if (_memicmp(argv[1], "bitspaceauto", 12) == 0)	llShowHelp = !iSearch_bitspaceAuto();							// Search for successive bits of the indicated size
			else													llShowHelp = true;

			// If we should show help...
			if (llShowHelp)
			{
				printf("Usage: butterfly [option]\n");
				printf("\n");
				printf("Options:\n");
				printf("\n");
				printf("\tfasta -- Converts dp_genome_v3.fasta to:\n");
				printf("\t             (1) at.txt\n");
				printf("\t             (2) cg.txt\n");
				printf("\n");
				printf("\bitwidth:N output.txt [A|C] -- Searches for N-bit sequences.\n");
				printf("\t         bitwidth:N -- Number of bits to scan.\n");
				printf("\t         output.txt -- Output file for matches.\n");
				printf("\t         A or C     -- Scan the at.txt or cg.txt file\n");
				printf("\n");
				printf("\tbitspace:N:M output.txt [A|C] -- Searches for N-bit sequences w/M spaces.\n");
				printf("\t         bitspace:N:M:O -- N bits to scan with only M spaces within at offset O.\n");
				printf("\t         output.txt     -- Output file for matches.\n");
				printf("\t         A or C         -- Scan the at.txt or cg.txt file\n");
			}

// Added to let the output screen be examined during debugging
//_asm int 3;
		return 0;
	}

#include "/libsf/utils/common/cpp/builder.cpp"




//////////
//
// Converts the dp_genome_v3.fasta file to the outputs:
//
//		at.txt			-- A+T pairs as A,T = 1, and T,A = 0
//		cg.txt			-- C+T pairs as C,G = 1, and G,C = 0
//
//////
	bool iConvert_fasta(void)
	{
		s32		lnI, lnS, lnD, lnAtCount, lnCgCount;
		s32		lnFastaSize, lnReadSize;
		s32		lhFasta, lhAt, lhCg;
		s8*		fasta_raw;
		s8*		at_raw;
		s8*		cg_raw;


		//////////
		// Open dp_genome_v3.fasta
		//////
			lhFasta = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\dp_genome_v3.fasta", _O_RDWR | _O_BINARY);
			if (lhFasta == -1)
			{
				printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\dp_genome_v3.fasta\n");
				return(false);
			}


		//////////
		// Find out how big it is
		//////
			lnFastaSize = _lseek(lhFasta, 0, SEEK_END);
			_lseek(lhFasta, 0, SEEK_SET);


		//////////
		// Allocate that much memory
		//////
			fasta_raw = (s8*)malloc(lnFastaSize);
			if (!fasta_raw)
			{
				printf("Error: Unable to allocate %d bytes\n", lnFastaSize);
				return(false);
			}


		//////////
		// Read content
		//////
			lnReadSize = _read(lhFasta, fasta_raw, lnFastaSize);
			if (lnReadSize != lnFastaSize)
			{
				printf("Error: Unable to read %d bytes\n", lnFastaSize);
				return(false);
			}
			_close(lhFasta);


		//////////
		// Remove all lines which do not begin with A,C,T,G
		//////
			for (lnS = 0, lnD = 0; lnS < lnFastaSize; )
			{
				// Are we on a skippable character?
				if (fasta_raw[lnS] == '>' || fasta_raw[lnS] == 13 || fasta_raw[lnS] == 10)
				{
					// We've reached an unexpected character, continue until we reach eod, or the next 13 or 10

					//////////
					// Skip past contiguous carriage returns and line feeds
					//////
						for ( ; lnS < lnFastaSize && (fasta_raw[lnS] == 13 || fasta_raw[lnS] == 10); )
							++lnS;


					//////////
					// Skip forward until we reach eod, or the next carriage return or line feed
					//////
						for ( ; lnS < lnFastaSize && fasta_raw[lnS] != 13 && fasta_raw[lnS] != 10; )
							++lnS;


					//////////
					// Skip past contiguous carriage returns and line feeds
					//////
						for ( ; lnS < lnFastaSize && (fasta_raw[lnS] == 13 || fasta_raw[lnS] == 10); )
							++lnS;

				} else {
					//////////
					// Copy this character, and increase
					//////
						if (lnD != lnS)
							fasta_raw[lnD] = fasta_raw[lnS];


					//////////
					// Move forward
					//////
						++lnS;
						++lnD;
				}
			}
			// When we get here, lnD indicates how big we are now
			lnFastaSize = lnD;


		//////////
		// Create a copy for A,T
		//////
			at_raw = (s8*)malloc(lnFastaSize);
			if (!at_raw)
			{
				printf("Error: Unable to allocate %d bytes for A,T\n", lnFastaSize);
				return(false);
			}
			memcpy(at_raw, fasta_raw, lnFastaSize);


		//////////
		// Create a copy for C,G
		//////
			cg_raw = (s8*)malloc(lnFastaSize);
			if (!cg_raw)
			{
				printf("Error: Unable to allocate %d bytes for C,G\n", lnFastaSize);
				return(false);
			}
			memcpy(cg_raw, fasta_raw, lnFastaSize);


		//////////
		// Release original copy
		//////
			free(fasta_raw);


		//////////
		// A,T to 1,0
		//////
			for (lnI = 0, lnAtCount = 0; lnI < lnFastaSize; lnI++)
			{
				     if (at_raw[lnI] == 'A')	at_raw[lnI] = '1';
				else if (at_raw[lnI] == 'T')	at_raw[lnI] = '0';
				else							at_raw[lnI] = ' ';

				lnAtCount += ((at_raw[lnI] == ' ') ? 0 : 1);
			}
			printf("A,T occurred %d times\n", lnAtCount);


		//////////
		// C,G to 1,0
		//////
			for (lnI = 0, lnCgCount = 0; lnI < lnFastaSize; lnI++)
			{
				     if (cg_raw[lnI] == 'C')	cg_raw[lnI] = '1';
				else if (cg_raw[lnI] == 'G')	cg_raw[lnI] = '0';
				else							cg_raw[lnI] = ' ';

				lnCgCount += ((cg_raw[lnI] == ' ') ? 0 : 1);
			}
			printf("C,G occurred %d times\n", lnCgCount);


		//////////
		// Write the data//at.txt
		//////
			lhAt = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt", _O_WRONLY | _O_CREAT);
			if (lhAt == -1)
			{
				printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n");
				return(false);
			}
			_write(lhAt, at_raw, lnFastaSize);
			_close(lhAt);
			free(at_raw);


		//////////
		// Write the data//cg.txt
		//////
			lhCg = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt", _O_WRONLY | _O_CREAT);
			if (lhCg == -1)
			{
				printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n");
				return(false);
			}
			_write(lhCg, cg_raw, lnFastaSize);
			_close(lhCg);
			free(cg_raw);


		//////////
		// Indicate success
		//////
			return(true);
	}




//////////
//
// Search for the indicated sequential bit width values
//
//////
	bool iSearch_bitwidth (s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg)
	{
		s32			lnI, lnJ, lnILast, lnEnd, lhAtCg, lnAtCgSize, lnReadSize, lnBits;
		bool		llAt;
		s8*			raw;
		SBuilder*	matches;
		s8			filename[_MAX_PATH];
		s8			buffer[256];


		//////////
		// A,T or C,G ?
		//////
			llAt = (!tcAtCg || (tcAtCg[0] != 'C' && tcAtCg[0] != 'G'));


		//////////
		// Grab the number of bits, and open the file
		//////
			lnBits	= atoi(tcBitWidth);
			if (llAt)		lhAtCg = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt", _O_RDONLY | _O_BINARY);
			else			lhAtCg = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt", _O_RDONLY | _O_BINARY);

			if (lhAtCg == -1)
			{
				if (llAt)	printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n");
				else		printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n");
				return(false);
			}


		//////////
		// Find out how big the file is
		//////
			lnAtCgSize = _lseek(lhAtCg, 0, SEEK_END);
			_lseek(lhAtCg, 0, SEEK_SET);


		//////////
		// Allocate memory
		//////
			raw = (s8*)malloc(lnAtCgSize);
			if (!raw)
			{
				if (llAt)	printf("Error: Unable to allocate %d bytes to load \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n", lnAtCgSize);
				else		printf("Error: Unable to allocate %d bytes to load \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n", lnAtCgSize);
				return(false);
			}


		//////////
		// Read content
		//////
			lnReadSize = _read(lhAtCg, raw, lnAtCgSize);
			if (lnReadSize != lnAtCgSize)
			{
				if (llAt)	printf("Error: Unable to read %d bytes from \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n", lnAtCgSize);
				else		printf("Error: Unable to read %d bytes from \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n", lnAtCgSize);
				return(false);
			}
			_close(lhAtCg);


		//////////
		// Iterate repeatedly until we exhaust our supply of bits
		//////
			iBuilder_createAndInitialize(&matches, -1);
			for (lnI = 0, lnILast = 0, lnEnd = lnAtCgSize - lnBits; lnI < lnEnd; )
			{
				// If there's a space before, and a space after, and everything between is a 0 or 1...
				if ((lnI == 0 || raw[lnI - 1] == ' ') && raw[lnI + lnBits + 1] == ' ')
				{
					//////////
					// Is every bit between a 0 or 1?
					//////
						for (lnJ = 0; lnJ < lnBits; lnJ++)
						{
							// Is it not a number?
							if (raw[lnI + lnJ] == ' ')
								break;	// Yes, we're done
						}


					//////////
					// Did we find a match?
					//////
						if (lnJ >= lnBits)
						{
							// Yes
							memset(buffer, 0, sizeof(buffer));
							sprintf(buffer, "%010d -- %010d -- ", lnI, lnI - lnILast);
							memcpy(buffer + strlen(buffer), raw + lnI, lnBits);

							// Append
							iBuilder_appendData(matches, (u8*)buffer, strlen(buffer));
							iBuilder_appendCrLf(matches);

							// Save our last location
							lnILast = lnI;
							
							// Skip past this entire bit section
							lnI += lnBits + 2;

						} else {
							// No, skip forward to where we found the space which broke our hope :-)
							lnI += lnJ + 1;
						}

				} else {
					// Not a match, skip 
					++lnI;
				}
			}


		//////////
		// Write the output file
		//////
			sprintf(filename, "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\%s", tcOutputFile);
			iBuilder_asciiWriteOutFile(matches, (u8*)filename);
			iBuilder_freeAndRelease(&matches);


		//////////
		// Completed
		//////
			free(raw);
			return(true);
	}




//////////
//
// Searches for numbers of the indicated size with up to M spaces internally.
//
//////
	s8* raw_at = NULL;
	s8* raw_cg = NULL;
	bool iSearch_bitspace(s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg)
	{
		s32			lnI, lnJ, lnILast, lnEnd, lhAtCg, lnAtCgSize, lnReadSize, lnBits, lnSpaces, lnSpaceCount;
		u32			lnSuccessiveBitCount, lnSuccessiveBits;
		bool		llAt, llSkip, llLoad;
		s8*			raw;
		SBuilder*	matches;
		s8			filename[_MAX_PATH];
		s8			buffer[256];


		//////////
		// A,T or C,G ?
		//////
			llAt = (!tcAtCg || (tcAtCg[0] != 'C' && tcAtCg[0] != 'G'));


		//////////
		// Grab the number of bits, and open the file
		//////
			lnBits				= atoi(tcBitWidth);
			lnSpaces			= atoi(tcBitWidth + iiCountToNeedleInHaystack(tcBitWidth, ':', 1) + 1);
			lnSuccessiveBits	= atoi(tcBitWidth + iiCountToNeedleInHaystack(tcBitWidth, ':', 2) + 1);
			if (llAt)		lhAtCg = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt", _O_RDONLY | _O_BINARY);
			else			lhAtCg = _open("\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt", _O_RDONLY | _O_BINARY);

			if (lhAtCg == -1)
			{
				if (llAt)	printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n");
				else		printf("Error: Unable to open \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n");
				return(false);
			}


		//////////
		// Find out how big the file is
		//////
			lnAtCgSize = _lseek(lhAtCg, 0, SEEK_END);
			_lseek(lhAtCg, 0, SEEK_SET);


		//////////
		// Allocate memory
		//////
			llLoad = false;
			if (llAt)
			{
				// A,T
				if (!raw_at)
				{
					llLoad	= true;
					raw_at	= (s8*)malloc(lnAtCgSize);
				}
				raw = raw_at;

			} else {
				// C,G
				if (!raw_cg)
				{
					llLoad	= true;
					raw_cg	= (s8*)malloc(lnAtCgSize);
				}
				raw = raw_cg;
			}
			if (!raw)
			{
				if (llAt)	printf("Error: Unable to allocate %d bytes to load \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n", lnAtCgSize);
				else		printf("Error: Unable to allocate %d bytes to load \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n", lnAtCgSize);
				return(false);
			}


		//////////
		// Read content
		//////
			if (llLoad)
			{
				lnReadSize = _read(lhAtCg, raw, lnAtCgSize);
				if (lnReadSize != lnAtCgSize)
				{
					if (llAt)	printf("Error: Unable to read %d bytes from \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt\n", lnAtCgSize);
					else		printf("Error: Unable to read %d bytes from \\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt\n", lnAtCgSize);
					return(false);
				}
			}
			_close(lhAtCg);


		//////////
		// Iterate repeatedly until we exhaust our supply of bits
		//////
			iBuilder_createAndInitialize(&matches, -1);
			for (lnI = 0, lnILast = 0, lnEnd = lnAtCgSize - lnBits; lnI < lnEnd; lnI++)
			{
				//////////
				// Is every bit between a 0 or 1, except for lnSpaces spaces?
				//////
					for (lnJ = 0, lnSpaceCount = 0, lnSuccessiveBitCount = 0, llSkip = false; lnJ < lnBits && lnSpaceCount <= lnSpaces; lnJ++)
					{
						// Is it not a number?
						if (raw[lnI + lnJ] == ' ')
						{
							// If the first or last character is a space, we'll ignore this group
							if (lnJ == 0 || lnJ == lnBits - 1)
								break;

							// Skip this one
							if (lnSuccessiveBitCount != lnSuccessiveBits)
							{
								llSkip = true;
								break;
							}

							// Increase the space count
							++lnSpaceCount;

							// Reset the successive numbers
							lnSuccessiveBitCount = 0;

						} else {
							// It's a number
							++lnSuccessiveBitCount;
						}
					}


				//////////
				// Did we find a match?
				//////
					if (lnJ >= lnBits && lnSpaceCount == lnSpaces && !llSkip)
					{
						// Yes
						memset(buffer, 0, sizeof(buffer));
						sprintf(buffer, "%010d -- %010d -- ", lnI, lnI - lnILast);
						memcpy(buffer + strlen(buffer), raw + lnI, lnBits);

						// Append
						iBuilder_appendData(matches, (u8*)buffer, strlen(buffer));
						iBuilder_appendCrLf(matches);

						// Save our last location
						lnILast = lnI;
					}
			}


		//////////
		// Write the output file
		//////
			sprintf(filename, "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\%s", tcOutputFile);
			iBuilder_asciiWriteOutFile(matches, (u8*)filename);
			iBuilder_freeAndRelease(&matches);


		//////////
		// Completed
		//////
			return(true);
	}

	// Search for the needle in the haystack
	s32 iiCountToNeedleInHaystack(s8* haystack, s8 needle, s32 count)
	{
		s32 lnI, lnMatch;


		// Scan forward until we reach NULL or our character
		for (lnI = 0, lnMatch = 0; haystack[lnI] != 0; lnI++)
		{
			// Is this our character?
			if (haystack[lnI] == needle)
			{
				// Is this our match?
				++lnMatch;
				if (lnMatch == count)
					return(lnI);	// Yes

				// Still going
			}
		}

		// If we get here, it wasn't found
		return(0);
	}




//////////
//
// Automatically 
//
//////
	bool iSearch_bitspaceAuto(void)
	{
		s32		lnBits, lnSpaceLocation;
		s8		buffer1[256];
		s8		buffer2[256];


		//////////
		// Iterate through bits, and space location
		//////
			for (lnBits = 64; lnBits <= 65; lnBits++)
			{
				// Iterate for the space location
				for (lnSpaceLocation = 4; lnSpaceLocation <= 10 && lnSpaceLocation <= lnBits / 2; lnSpaceLocation++)
				{
					//////////
					// Build the expression like:  bitspace:32:1:5 at_32_1_5_bitspace.txt A
					//////
						sprintf(buffer1, "%d:1:%d\0",					lnBits, lnSpaceLocation);
						sprintf(buffer2, "at_%d_1_%d_bitspace.txt\0",	lnBits, lnSpaceLocation);
						printf("%s\n", buffer1);


					//////////
					// Do the work
					//////
						iSearch_bitspace(buffer1, buffer2, "A");
				}
			}


		//////////
		// Indicate success
		//////
			return(true);
	}
