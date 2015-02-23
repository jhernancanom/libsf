//////////
//
// /libsf/source/unsorted/dna_project_butterfly/butterfly/butterfly.cpp
//
//////
// Version 0.01
// Copyright (c) 2015 by Rick C. Hodgin
//////
// Last update:
//     Feb.22.2015 - ButterflyBlocks (analysis of generated data is interesting, but inconclusive ... pattern most likely needs tweaking)
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
#include <windows.h>
#include <io.h>
#include <string.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define max(a,b)					(((a) > (b)) ? (a) : (b))
#define min(a,b)					(((a) < (b)) ? (a) : (b))
#define debug_break					_asm int 3
#define _BUTTERFLY_BLOCK_SIZE		16 * 1024 * 1000

#include "/libsf/utils/common/cpp/common_types.h"
#include "/libsf/utils/common/cpp/builder.h"




//////////
// Structures
//////
	// dd dd II dd dd		(left to right across row:)
	struct SRowInstr
	{
		s8	data1;			// dd
		s8	data2;			// dd
		s8	instr;			// II
		s8	data3;			// dd
		s8	data4;			// dd
	};

	// dd dd AA dd dd		(left to right across row:)
	struct SRowAata
	{
		s8	data1;			// dd
		s8	data2;			// dd
		s8	aata;			// AA
		s8	data3;			// dd
		s8	data4;			// dd
	};

	// II AA II AA II		(left to right across row:)
	struct SRowInstrAata
	{
		s8	instr1;			// II
		s8	aata1;			// AA
		s8	instr2;			// II
		s8	aata2;			// AA
		s8	instr3;			// II
	};

	// The 40-byte block assemblage of these various components
	struct SButterflyBlock7
	{
		SRowInstr		top;			// dd dd II dd dd
		SRowAata		crown;			// dd dd AA dd dd
		SRowAata		head;			// dd dd AA dd dd
		SRowInstrAata	arms;			// II AA II AA II
		SRowAata		legs;			// dd dd AA dd dd
		SRowAata		feet;			// dd dd AA dd dd
		SRowAata		fallow;			// .. .. .. .. ..
		SRowInstr		bottom;			// dd dd II dd dd
	};

	// The 40-byte block assemblage of these various components
	struct SButterflyBlock8
	{
		SRowInstr		top;			// dd dd II dd dd
		SRowAata		head;			// dd dd AA dd dd
		SRowInstrAata	arms1;			// II AA II AA II
		SRowInstrAata	arms2;			// II AA II AA II
		SRowAata		legs1;			// dd dd AA dd dd
		SRowAata		legs2;			// dd dd AA dd dd
		SRowAata		feet;			// dd dd AA dd dd
		SRowInstr		bottom;			// dd dd II dd dd
	};


//////////
// Filenames used
//////
	cs8				cgcBaseDirectory[]						= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\";
	cs8				cgcGenomeFastaFile[]					= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\dp_genome_v3.fasta";
	cs8				cgcFastaFile[]							= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\fasta.txt";
	cs8				cgcAtFile[]								= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\at.txt";
	cs8				cgcCgFile[]								= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\cg.txt";
	cs8				cgcButterflyBlocks7File[]				= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\butterfly_blocks7.txt";
	cs8				cgcButterflyBlocks8File[]				= "\\libsf_offline\\source\\unsorted\\dna_project_butterfly\\butterfly\\data\\butterfly_blocks8.txt";


//////////
// Function prototype
//////
	bool			iConvert_fasta							(void);
	bool			iSearch_bitwidth						(s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg);
	bool			iSearch_bitspace						(s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg, u32 tnDataSize);
	s32				iiCountToNeedleInHaystack				(s8* haystack, s8 needle, s32 count);
	bool			iSearch_bitspaceAuto					(void);
	DWORD WINAPI	iSearch_bitspaceAuto_threadScheduler	(void* param);
	void			iSchedule_n_threads						(SBuilder* threadManager, s32 tnRunningCount);
	bool			iSearch_butterflyBlocks7				(void);
	void			iExtract_butterflyBlock7				(SBuilder* bld, SButterflyBlock7* bb7, u32 tnMaxSize);
	bool			iSearch_butterflyBlocks8				(void);
	void			iExtract_butterflyBlock8				(SBuilder* bld, SButterflyBlock8* bb8, u32 tnMaxSize);
	s8				iConvert_DNA_toBinary					(s8 ch);




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
			     if (_memicmp(argv[1], "fasta", 5) == 0)				llShowHelp = !iConvert_fasta();									// Convert dp_genome_v3.fasta file to outputs
			else if (_memicmp(argv[1], "bitwidth:", 9) == 0)			llShowHelp = !iSearch_bitwidth(argv[1] + 9, argv[2], argv[3]);	// Search for successive bits of the indicated size
			else if (_memicmp(argv[1], "bitspaceauto", 12) == 0)		llShowHelp = !iSearch_bitspaceAuto();							// Search for successive bits of the indicated size
			else if (_memicmp(argv[1], "butterflyblocks7", 16) == 0)	llShowHelp = !iSearch_butterflyBlocks7();
			else if (_memicmp(argv[1], "butterflyblocks8", 16) == 0)	llShowHelp = !iSearch_butterflyBlocks8();
			else														llShowHelp = true;

			// If we should show help...
			if (llShowHelp)
			{
				printf("Usage: butterfly [option]\n");
				printf("\n");
				printf("Options:\n");
				printf("\n");
				printf("\tfasta -- Converts dp_genome_v3.fasta to:\n");
				printf("\t             (1) fasta.txt, includes A,T and C,G together\n");
				printf("\t             (2) at.txt\n");
				printf("\t             (3) cg.txt\n");
				printf("\n");
				printf("\bitwidth:N output.txt [A|C] -- Searches for N-bit sequences.\n");
				printf("\t         bitwidth:N -- Number of bits to scan.\n");
				printf("\t         output.txt -- Output file for matches.\n");
				printf("\t         A or C     -- Scan the at.txt or cg.txt file\n");
				printf("\n");
				printf("\tbitspaceauto -- Searches for N-bit sequences w/M spaces.\n");
				printf("\n");
				printf("\tbutterflyblocks7 -- Generates butterfly block in 7-row format from fasta.txt.\n");
				printf("\n");
				printf("\tbutterflyblocks8 -- Generates butterfly block in 8-row format from fasta.txt.\n");
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
			lhFasta = _open(cgcGenomeFastaFile, _O_RDWR | _O_BINARY);
			if (lhFasta == -1)
			{
				printf("Error: Unable to open %s\n", cgcGenomeFastaFile);
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
		// Write and release original copy
		//////
			lhFasta = _open(cgcFastaFile, _O_WRONLY | _O_CREAT);
			if (lhFasta == -1)
			{
				printf("Error: Unable to open %s\n", cgcFastaFile);
				return(false);
			}
			_write(lhFasta, fasta_raw, lnFastaSize);
			_close(lhFasta);
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
			lhAt = _open(cgcAtFile, _O_WRONLY | _O_CREAT);
			if (lhAt == -1)
			{
				printf("Error: Unable to open %s\n", cgcAtFile);
				return(false);
			}
			_write(lhAt, at_raw, lnFastaSize);
			_close(lhAt);
			free(at_raw);


		//////////
		// Write the data//cg.txt
		//////
			lhCg = _open(cgcCgFile, _O_WRONLY | _O_CREAT);
			if (lhCg == -1)
			{
				printf("Error: Unable to open %s\n", cgcCgFile);
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
			if (llAt)		lhAtCg = _open(cgcAtFile, _O_RDONLY | _O_BINARY);
			else			lhAtCg = _open(cgcCgFile, _O_RDONLY | _O_BINARY);

			if (lhAtCg == -1)
			{
				if (llAt)	printf("Error: Unable to open %s\n", cgcAtFile);
				else		printf("Error: Unable to open %s\n", cgcCgFile);
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
				if (llAt)	printf("Error: Unable to allocate %d bytes to load %s\n", lnAtCgSize, cgcAtFile);
				else		printf("Error: Unable to allocate %d bytes to load %s\n", lnAtCgSize, cgcCgFile);
				return(false);
			}


		//////////
		// Read content
		//////
			lnReadSize = _read(lhAtCg, raw, lnAtCgSize);
			if (lnReadSize != lnAtCgSize)
			{
				if (llAt)	printf("Error: Unable to read %d bytes from %s\n", lnAtCgSize, cgcAtFile);
				else		printf("Error: Unable to read %d bytes from %s\n", lnAtCgSize, cgcCgFile);
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
			sprintf(filename, "%s%s", cgcBaseDirectory, tcOutputFile);
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
	s8* raw_fasta = NULL;
	s8* raw_cg = NULL;

	bool iSearch_bitspace(s8* tcBitWidth, s8* tcOutputFile, s8* tcAtCg, u32 tnDataSize)
	{
		s32			lnI, lnJ, lnILast, lnEnd, lnBits, lnSpaces, lnSpaceCount;
		u32			lnSuccessiveBitCount, lnSuccessiveBits;
		bool		llAt, llSkip;
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


		//////////
		// Grab the data pointer
		//////
			if (llAt)	raw = raw_fasta;
			else		raw = raw_cg;


		//////////
		// Iterate repeatedly until we exhaust our supply of bits
		//////
			iBuilder_createAndInitialize(&matches, -1);
			for (lnI = 0, lnILast = 0, lnEnd = tnDataSize - lnBits; lnI < lnEnd; lnI++)
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
			sprintf(filename, "%s%s", cgcBaseDirectory, tcOutputFile);
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
	struct SBitSpaceAuto
	{
		bool	isRunning;			// false until it begins, then true thereafter
		bool	isFinished;			// false until it is completed, then true

		// Parameters for this iteration
		s8		buffer1[64];
		s8		buffer2[64];
		s8		ac[2];
		u32		dataSize;

		// Access semaphore
		CRITICAL_SECTION cs;

		// Windows thread specific
		HANDLE	hThread;
		DWORD	threadId;
	};
	SBuilder* gsSpaceAutoThreads = NULL;

#define _AC_START			1
#define _BITS_START			48
#define _BITS_STOP			65
#define _SPACE_LOCATION		4

	bool iSearch_bitspaceAuto(void)
	{
		s32				lnAc, lnBits, lnSpaceLocation;
		SBitSpaceAuto*	bsa;
		s32				lhAt, lhCg, lnAtSize, lnCgSize, lnReadSize;


		//////////
		// Open the required files for preload
		//////
			lhAt = _open(cgcAtFile, _O_RDONLY | _O_BINARY);
			lhCg = _open(cgcCgFile, _O_RDONLY | _O_BINARY);

			if (lhAt == -1)
			{
				printf("Error: Unable to open %s\n", cgcAtFile);
				return(false);
			}
			if (lhCg == -1)
			{
				printf("Error: Unable to open %s\n", cgcCgFile);
				return(false);
			}


		//////////
		// Find out how big the file is
		//////
			lnAtSize = _lseek(lhAt, 0, SEEK_END);
			_lseek(lhAt, 0, SEEK_SET);

			lnCgSize = _lseek(lhCg, 0, SEEK_END);
			_lseek(lhCg, 0, SEEK_SET);


		//////////
		// Allocate memory
		//////
			// A,T
			if (!raw_fasta)
				raw_fasta	= (s8*)malloc(lnAtSize);

			// C,G
			if (!raw_cg)
				raw_cg	= (s8*)malloc(lnCgSize);

			if (!raw_fasta)
			{
				printf("Error: Unable to allocate %d bytes to load %s\n", lnAtSize, cgcAtFile);
				return(false);
			}

			if (!raw_cg)
			{
				printf("Error: Unable to allocate %d bytes to load %s\n", lnCgSize, cgcCgFile);
				return(false);
			}


		//////////
		// Read content
		//////
			lnReadSize = _read(lhAt, raw_fasta, lnAtSize);
			if (lnReadSize != lnAtSize)
			{
				printf("Error: Unable to read %d bytes from %s\n", lnAtSize, cgcAtFile);
				return(false);
			}
			_close(lhAt);

			lnReadSize = _read(lhCg, raw_cg, lnCgSize);
			if (lnReadSize != lnCgSize)
			{
				printf("Error: Unable to read %d bytes from %s\n", lnCgSize, cgcCgFile);
				return(false);
			}
			_close(lhCg);


		//////////
		// Iterate through bits, and space location
		//////
			iBuilder_createAndInitialize(&gsSpaceAutoThreads, -1);
			for (lnAc = _AC_START; lnAc < 2; lnAc++)
			{
				for (lnBits = _BITS_START; lnBits <= _BITS_STOP; lnBits++)
				{
					// Iterate for the space location
					for (lnSpaceLocation = _SPACE_LOCATION; lnSpaceLocation <= 32 && lnSpaceLocation <= lnBits / 2; lnSpaceLocation++)
					{
						//////////
						// Create this thread entry
						//////
							bsa = (SBitSpaceAuto*)iBuilder_appendData(gsSpaceAutoThreads, NULL, sizeof(SBitSpaceAuto));


						//////////
						// Build the expression like:  bitspace:32:1:5 at_32_1_5_bitspace.txt A
						//////
							sprintf(bsa->buffer1, "%d:1:%d\0",												lnBits, lnSpaceLocation);
							sprintf(bsa->buffer2, "%s_%d_1_%d_bitspace.txt\0", ((lnAc == 0) ? "at" : "cg"),	lnBits, lnSpaceLocation);


						//////////
						// Are we scheduling for A,T or C,G?
						//////
							bsa->ac[0]		= ((lnAc == 0) ? 'A' : 'C');
							bsa->ac[1]		= 0;
							bsa->dataSize	= ((lnAc == 0) ? lnAtSize : lnCgSize);


						//////////
						// Initialize
						//////
							InitializeCriticalSection(&bsa->cs);


						//////////
						// Schedule the thread
						//////
							bsa->isRunning	= false;
							bsa->isFinished	= false;
					}
				}
			}


		//////////
		// Wait for the last one to complete
		//////
			while (!bsa->isFinished)
			{
				iSchedule_n_threads(gsSpaceAutoThreads, -1);

				// Wait 1/3rd second and make sure the threads are running
				Sleep(333);
			}


		//////////
		// Indicate success
		//////
			return(true);
	}

	// Note: Upon entry, this bsa should already be locked
	DWORD WINAPI iSearch_bitspaceAuto_threadScheduler(void* param)
	{
		SBitSpaceAuto* bsa;


		//////////
		// Reclaim our pointer
		//////
			bsa				= (SBitSpaceAuto*)param;
			bsa->isRunning	= true;


		//////////
		// Dispatch
		//////
			iSearch_bitspace(bsa->buffer1, bsa->buffer2, bsa->ac, bsa->dataSize);
			bsa->isFinished	= true;


		//////////
		// Unlock
		//////
			LeaveCriticalSection(&bsa->cs);


		//////////
		// Fire off the next thread in sequence
		//////
			iSchedule_n_threads(gsSpaceAutoThreads, -1);


		//////////
		// If we get here, nothing left to schedule
		//////
			TerminateThread(bsa->hThread, 0);
			return(0);
	}




//////////
//
// Called to make sure the specified number of threads are running, if possible
//
//////
	void iSchedule_n_threads(SBuilder* threadManager, s32 tnRunningCount)
	{
		u32				lnI, lnRunningCount;
		SYSTEM_INFO		sysinfo;
		SBitSpaceAuto*	bsa;


		//////////
		// If they didn't provide a count, use the system processors
		//////
			if (tnRunningCount < 0)
			{
				// Find out how many 
				GetSystemInfo(&sysinfo);
				tnRunningCount = sysinfo.dwNumberOfProcessors;
			}


		//////////
		// Make sure at least two threads are still running
		//////
			for (lnI = 0, lnRunningCount = 0, bsa = (SBitSpaceAuto*)gsSpaceAutoThreads->buffer; lnI < gsSpaceAutoThreads->populatedLength && lnRunningCount < sysinfo.dwNumberOfProcessors; lnI += sizeof(SBitSpaceAuto), bsa++)
			{
				// If this one isn't yet finished...
				if (!bsa->isFinished)
				{
					// Is it currently running?
					if (bsa->isRunning)
					{
						// Yes
						++lnRunningCount;

					} else {
						// Go ahead and lock and schedule this one
						if (TryEnterCriticalSection(&bsa->cs))
						{
							// Increase our count
							++lnRunningCount;
							bsa->hThread = CreateThread(NULL, 0, &iSearch_bitspaceAuto_threadScheduler, bsa, 0, &bsa->threadId);
						}
					}
				}
			}

	}




//////////
//
// Called to process through butterfly blocks, writing them out to a text file
//
//////
	// Parse through the file 
	bool iSearch_butterflyBlocks7(void)
	{
		s32					lnI;
		s32					lhFasta, lnFastaSize, lnReadSize;
		SButterflyBlock7*	bb7;
		SBuilder*			butterfly_blocks;


		//////////
		// Open the required files for preload
		//////
			lhFasta = _open(cgcFastaFile, _O_RDONLY | _O_BINARY);
			if (lhFasta == -1)
			{
				printf("Error: Unable to open %s\n", cgcFastaFile);
				return(false);
			}


		//////////
		// Find out how big the file is
		//////
			lnFastaSize = _lseek(lhFasta, 0, SEEK_END);
			_lseek(lhFasta, 0, SEEK_SET);


		//////////
		// Allocate memory
		//////
			// A,T,C,G all combined
			if (!raw_fasta)
				raw_fasta	= (s8*)malloc(lnFastaSize);

			if (!raw_fasta)
			{
				printf("Error: Unable to allocate %d bytes to load %s\n", lnFastaSize, cgcFastaFile);
				return(false);
			}


		//////////
		// Read content
		//////
			lnReadSize = _read(lhFasta, raw_fasta, lnFastaSize);
			if (lnReadSize != lnFastaSize)
			{
				printf("Error: Unable to read %d bytes from %s\n", lnFastaSize, cgcFastaFile);
				return(false);
			}
			_close(lhFasta);


		//////////
		// Iterate through butterfly blocks
		//////
			iBuilder_createAndInitialize(&butterfly_blocks, _BUTTERFLY_BLOCK_SIZE);
			for (lnI = 0; lnI < lnFastaSize; lnI += sizeof(SButterflyBlock7))
			{
				//////////
				// Set the pointer
				//////
					bb7 = (SButterflyBlock7*)(raw_fasta + lnI);


				//////////
				// Extract the instruction, ata, and data
				//////
					iExtract_butterflyBlock7(butterfly_blocks, bb7, _BUTTERFLY_BLOCK_SIZE - (2 * sizeof(SButterflyBlock7)));
			}

			// Write the last portion
			iBuilder_asciiWriteOutFile(butterfly_blocks, (cu8*)cgcButterflyBlocks7File, true);


		//////////
		// Indicate success
		//////
			return(true);
	}

	//////////
	//
	// Format of the output line is:
	//
	//		IIIII[space]
	//		AAAAAA[space]
	//		dddddddddddddddddddddddd[cr+lf]
	//
	// Size:  5+1 + 6+1 + 24+2 = 39
	//
	//////
	void iExtract_butterflyBlock7(SBuilder* bld, SButterflyBlock7* bb7, u32 tnMaxSize)
	{
		s8 line[39];


		//////////
		// Instruction, space
		//////
			line[0] = iConvert_DNA_toBinary(bb7->top.instr);		// II
			line[1] = iConvert_DNA_toBinary(bb7->arms.instr1);		// II
			line[2] = iConvert_DNA_toBinary(bb7->arms.instr2);		// II
			line[3] = iConvert_DNA_toBinary(bb7->arms.instr3);		// II
			line[4] = iConvert_DNA_toBinary(bb7->bottom.instr);		// II
			line[5] = 32;


		//////////
		// Aata, space
		//////
			line[6]		= iConvert_DNA_toBinary(bb7->crown.aata);	// AA
			line[7]		= iConvert_DNA_toBinary(bb7->head.aata);	// AA
			line[8]		= iConvert_DNA_toBinary(bb7->arms.aata1);	// AA
			line[9]		= iConvert_DNA_toBinary(bb7->arms.aata2);	// AA
			line[10]	= iConvert_DNA_toBinary(bb7->legs.aata);	// AA
			line[11]	= iConvert_DNA_toBinary(bb7->feet.aata);	// AA
			line[12]	= 32;


		//////////
		// Data, cr+lf
		//////
			line[13]	= iConvert_DNA_toBinary(bb7->top.data1);	// dd
			line[14]	= iConvert_DNA_toBinary(bb7->top.data2);	// dd
			line[15]	= iConvert_DNA_toBinary(bb7->top.data3);	// dd
			line[16]	= iConvert_DNA_toBinary(bb7->top.data4);	// dd
			line[17]	= iConvert_DNA_toBinary(bb7->crown.data1);	// dd
			line[18]	= iConvert_DNA_toBinary(bb7->crown.data2);	// dd
			line[19]	= iConvert_DNA_toBinary(bb7->crown.data3);	// dd
			line[20]	= iConvert_DNA_toBinary(bb7->crown.data4);	// dd
			line[21]	= iConvert_DNA_toBinary(bb7->head.data1);	// dd
			line[22]	= iConvert_DNA_toBinary(bb7->head.data2);	// dd
			line[23]	= iConvert_DNA_toBinary(bb7->head.data3);	// dd
			line[24]	= iConvert_DNA_toBinary(bb7->head.data4);	// dd
			line[25]	= iConvert_DNA_toBinary(bb7->legs.data1);	// dd
			line[26]	= iConvert_DNA_toBinary(bb7->legs.data2);	// dd
			line[27]	= iConvert_DNA_toBinary(bb7->legs.data3);	// dd
			line[28]	= iConvert_DNA_toBinary(bb7->legs.data4);	// dd
			line[29]	= iConvert_DNA_toBinary(bb7->feet.data1);	// dd
			line[30]	= iConvert_DNA_toBinary(bb7->feet.data2);	// dd
			line[31]	= iConvert_DNA_toBinary(bb7->feet.data3);	// dd
			line[32]	= iConvert_DNA_toBinary(bb7->feet.data4);	// dd
			line[33]	= iConvert_DNA_toBinary(bb7->bottom.data1);	// dd
			line[34]	= iConvert_DNA_toBinary(bb7->bottom.data2);	// dd
			line[35]	= iConvert_DNA_toBinary(bb7->bottom.data3);	// dd
			line[36]	= iConvert_DNA_toBinary(bb7->bottom.data4);	// dd
			line[37]	= 13;	// cr
			line[38]	= 10;	// lf


		//////////
		// Append to the butterfly block data
		//////
			iBuilder_appendData(bld, (cu8*)&line[0], sizeof(line));


		//////////
		// If we've exceeded our maximum size, write it to disk
		//////
			if (bld->populatedLength >= tnMaxSize)
			{
				// Write out the current contents, appending to the butterfly blocks file
				iBuilder_asciiWriteOutFile(bld, (cu8*)cgcButterflyBlocks7File, true);

				// Reset for the next portion
				bld->populatedLength = 0;
			}
	}




//////////
//
// Generates butterfly blocks in the 8-row format
//
//////
	bool iSearch_butterflyBlocks8(void)
	{
		s32					lnI;
		s32					lhFasta, lnFastaSize, lnReadSize;
		SButterflyBlock8*	bb8;
		SBuilder*			butterfly_blocks;


		//////////
		// Open the required files for preload
		//////
			lhFasta = _open(cgcFastaFile, _O_RDONLY | _O_BINARY);
			if (lhFasta == -1)
			{
				printf("Error: Unable to open %s\n", cgcFastaFile);
				return(false);
			}


		//////////
		// Find out how big the file is
		//////
			lnFastaSize = _lseek(lhFasta, 0, SEEK_END);
			_lseek(lhFasta, 0, SEEK_SET);


		//////////
		// Allocate memory
		//////
			// A,T,C,G all combined
			if (!raw_fasta)
				raw_fasta	= (s8*)malloc(lnFastaSize);

			if (!raw_fasta)
			{
				printf("Error: Unable to allocate %d bytes to load %s\n", lnFastaSize, cgcFastaFile);
				return(false);
			}


		//////////
		// Read content
		//////
			lnReadSize = _read(lhFasta, raw_fasta, lnFastaSize);
			if (lnReadSize != lnFastaSize)
			{
				printf("Error: Unable to read %d bytes from %s\n", lnFastaSize, cgcFastaFile);
				return(false);
			}
			_close(lhFasta);


		//////////
		// Iterate through butterfly blocks
		//////
			iBuilder_createAndInitialize(&butterfly_blocks, _BUTTERFLY_BLOCK_SIZE);
			for (lnI = 0; lnI < lnFastaSize; lnI += sizeof(SButterflyBlock8))
			{
				//////////
				// Set the pointer
				//////
					bb8 = (SButterflyBlock8*)(raw_fasta + lnI);


				//////////
				// Extract the instruction, ata, and data
				//////
					iExtract_butterflyBlock8(butterfly_blocks, bb8, _BUTTERFLY_BLOCK_SIZE - (2 * sizeof(SButterflyBlock8)));
			}

			// Write the last portion
			iBuilder_asciiWriteOutFile(butterfly_blocks, (cu8*)cgcButterflyBlocks8File, true);


		//////////
		// Indicate success
		//////
			return(true);
	}

	//////////
	//
	// Format of the output line is:
	//
	//		IIIIIIII[space]
	//		AAAAAAAA[space]
	//		dddddddddddddddddddddddd[cr+lf]
	//
	// Size:  8+1 + 8+1 + 24+2 = 44
	//
	//////
	void iExtract_butterflyBlock8(SBuilder* bld, SButterflyBlock8* bb8, u32 tnMaxSize)
	{
		s8 line[44];


		//////////
		// Instruction, space
		//////
			line[0] = iConvert_DNA_toBinary(bb8->top.instr);		// II
			line[1] = iConvert_DNA_toBinary(bb8->arms1.instr1);		// II
			line[2] = iConvert_DNA_toBinary(bb8->arms1.instr2);		// II
			line[3] = iConvert_DNA_toBinary(bb8->arms1.instr3);		// II
			line[4] = iConvert_DNA_toBinary(bb8->arms2.instr1);		// II
			line[5] = iConvert_DNA_toBinary(bb8->arms2.instr2);		// II
			line[6] = iConvert_DNA_toBinary(bb8->arms2.instr3);		// II
			line[7] = iConvert_DNA_toBinary(bb8->bottom.instr);		// II
			line[8] = 32;


		//////////
		// Aata, space
		//////
			line[9]		= iConvert_DNA_toBinary(bb8->head.aata);	// AA
			line[10]	= iConvert_DNA_toBinary(bb8->arms1.aata1);	// AA
			line[11]	= iConvert_DNA_toBinary(bb8->arms1.aata2);	// AA
			line[12]	= iConvert_DNA_toBinary(bb8->arms2.aata1);	// AA
			line[13]	= iConvert_DNA_toBinary(bb8->arms2.aata2);	// AA
			line[14]	= iConvert_DNA_toBinary(bb8->legs1.aata);	// AA
			line[15]	= iConvert_DNA_toBinary(bb8->legs2.aata);	// AA
			line[16]	= iConvert_DNA_toBinary(bb8->feet.aata);	// AA
			line[17]	= 32;


		//////////
		// Data, cr+lf
		//////
			line[18]	= iConvert_DNA_toBinary(bb8->top.data1);	// dd
			line[19]	= iConvert_DNA_toBinary(bb8->top.data2);	// dd
			line[20]	= iConvert_DNA_toBinary(bb8->top.data3);	// dd
			line[21]	= iConvert_DNA_toBinary(bb8->top.data4);	// dd
			line[22]	= iConvert_DNA_toBinary(bb8->head.data1);	// dd
			line[23]	= iConvert_DNA_toBinary(bb8->head.data2);	// dd
			line[24]	= iConvert_DNA_toBinary(bb8->head.data3);	// dd
			line[25]	= iConvert_DNA_toBinary(bb8->head.data4);	// dd
			line[26]	= iConvert_DNA_toBinary(bb8->legs1.data1);	// dd
			line[27]	= iConvert_DNA_toBinary(bb8->legs1.data2);	// dd
			line[28]	= iConvert_DNA_toBinary(bb8->legs1.data3);	// dd
			line[29]	= iConvert_DNA_toBinary(bb8->legs1.data4);	// dd
			line[30]	= iConvert_DNA_toBinary(bb8->legs2.data1);	// dd
			line[31]	= iConvert_DNA_toBinary(bb8->legs2.data2);	// dd
			line[32]	= iConvert_DNA_toBinary(bb8->legs2.data3);	// dd
			line[33]	= iConvert_DNA_toBinary(bb8->legs2.data4);	// dd
			line[34]	= iConvert_DNA_toBinary(bb8->feet.data1);	// dd
			line[35]	= iConvert_DNA_toBinary(bb8->feet.data2);	// dd
			line[36]	= iConvert_DNA_toBinary(bb8->feet.data3);	// dd
			line[37]	= iConvert_DNA_toBinary(bb8->feet.data4);	// dd
			line[38]	= iConvert_DNA_toBinary(bb8->bottom.data1);	// dd
			line[39]	= iConvert_DNA_toBinary(bb8->bottom.data2);	// dd
			line[40]	= iConvert_DNA_toBinary(bb8->bottom.data3);	// dd
			line[41]	= iConvert_DNA_toBinary(bb8->bottom.data4);	// dd
			line[42]	= 13;	// cr
			line[43]	= 10;	// lf


		//////////
		// Append to the butterfly block data
		//////
			iBuilder_appendData(bld, (cu8*)&line[0], sizeof(line));


		//////////
		// If we've exceeded our maximum size, write it to disk
		//////
			if (bld->populatedLength >= tnMaxSize)
			{
				// Write out the current contents, appending to the butterfly blocks file
				iBuilder_asciiWriteOutFile(bld, (cu8*)cgcButterflyBlocks8File, true);

				// Reset for the next portion
				bld->populatedLength = 0;
			}
	}




//////////
//
// Converts A,C to 1, and T,G to 0
//
//////
	s8 iConvert_DNA_toBinary(s8 ch)
	{
		return(ch);

		     if (ch == 'A' || ch == 'C')		return('1');
		else if (ch == 'N')						return('-');
		else									return('0');
	}
