//////////
//
// /libsf/source/vjr/source/dbf/dbf_structs.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Dec.22.2014
//////
// Change log:
//     Dec.22.2014 - Initial creation
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




//////////
//
// Structures
//
//////
	struct _isSKeyFinds;
	struct SCdxHeader;
	struct SIdxHeader;
	struct SForClause;
	struct SCdxKeyOp;


	//////////////
	// Fixed DBF header portion
	//////
		struct STableHeader
		{
			u8		type;					// Offset  0, Length 1
			u8		lastUpdate[3];			// Offset  1, Length 3
			u32		records;				// Offset  4, Length 4
			u16		firstRecord;			// Offset  8, Length 2
			u16		recordLength;			// Offset 10, Length 2
			u8		reserved1[16];			// Offset 12, Length 16
			u8		flags;					// Offset 28, Length 1
			u8		codePage;				// Offset 29, Length 1
			u8		reserved2[2];			// Offset 30, Length 2
			// Total:  32 bytes
		};


	//////////
	// Field records within the variable portion of the DBF header
	//////
		struct SFieldRecord1
		{
			// Valid types:
			//		C?Character		Y?Currency	D?Date		T-DateTime
			//		B?Double		F?Float		G?General	I?Integer
			//		L?Logical		M?Memo		N?Numeric	P?Picture
			//		Q-Varbinary		V-Varchar (binary)

			u8		name[11];				// Offset  0, Length 11
			u8		type;					// offset 11, Length  1
			u32		offset;					// Offset 12, Length  4
			u8		length;					// Offset 16, Length  1
			u8		decimals;				// Offset 17, Length  1


			//////////
			// Flags:
			//		0x01 - System (not visible to user, such as null flags)
			//		0x02 - Can store NULLs
			//		0x04 - Binary (NOCPTRANS)
			//		0x0c - Auto-incrementing
			//////
				u8		flags;					// Offset 18, Length  1
				u32		autoIncNext;			// Offset 19, Length  4
				u8		autoIncStep;			// Offset 23, Length  1


			//////////
			// Miscellaneous/internal fields
			//////
				union {							// Offset 24, Length  1
					u8	reserved1;
					u8	field_name_length;
				};

				union {
					u8	reserved2;				// Offset 25, Length  1
					u8	fillChar;
				};

				u8		reserved3;				// Offset 26, Length  1

			//////////
			// Part of reserved space, used internally
			//////
				u8		indexFixup_lengthOverride;	// Offset 27, Length  1		// For numeric fields, for example, which index on f64 equivalents
				u32		indexFixup;					// Offset 28, Length  4		// For copying to index keys, what fixup operation is required on this field?

			// Total:  32 bytes
		};


	//////////
	// More or less a copy of the SFieldRecord, but stores longer
	// field names and additional fields used by VXB/VXB++
	//////
		struct SFieldRecord2
		{
			u8		name[11];				// Offset  0, Length 11
			u8		type;					// offset 11, Length  1
			u32		offset;					// Offset 12, Length  4
			u8		length;					// Offset 16, Length  1
			u8		decimals;				// Offset 17, Length  1
			u8		flags;					// Offset 18, Length  1
			u32		autoIncNext;			// Offset 19, Length  4
			u8		autoIncStep;			// Offset 23, Length  1
			s32		fieldName_length;		// Offset 24, Length  4
			u8		name2[129];				// Offset 28, Length 129

			// Used for index creation
			u8		fillChar;				// Offset 157, Length 1
			u32		dbcRecno;				// Offset 160, Length 4
			u32		indexFixup;				// Offset 251, Length 4
			// Total:  256 bytes
		};

	//////////
	// Internal work area structures, relates to SELECT() locations
	//////
		struct SWorkArea
		{
			// Internal flags
			u32				isUsed;						// _YES or _NO
			u32				thisWorkArea;				// Added to hold this entry's slot number
			bool			isDbc;						// true if this is a container
			bool			isIndexLoaded;				// true if an index is loaded
			bool			isCached;					// If the table's been cached, then it will be true, otherwise false
			bool			isVisualTable;				// Visual tables can have DBC backlinks

			// Names
			s8				tablePathname[256];			// Filename to get to the table
			s32				tablePathnameLength;		// Length of the table filename
			s8				alias[32];					// Alias associated with this
			u32				aliasLength;				// Length of the alias name


			// File handles for the related/opened table
			FILE*			fhDbf;						// File handle for the table
			SWorkArea*		dbc;						// The DBC this table relates to (if any)
			u32				dbc_parentRecno;			// in the DBC, the record number of the "Table" record
			u32				dbc_parentId;				// In the DBC, the parentId of the "Table" record
			u32				dbc_firstChildRecno;		// In the DBC, the record number of the first entry where the dbc_parentId is the parentId
			u32				dbc_firstFieldRecno;		// In the DBC, the record number of the first "Field" entry, which correlates to column 1 in the table, with each record after that sequentially being the next column


			// Header information
			STableHeader	header;						// Header for this table
			s8*				backlink;					// Pointer to the DBC backlink if any
			u32				backlinkLength;				// Length of the backlink filename
			u32				currentRecord;				// Current record pointed at


			// Fields
			SFieldRecord1*	fieldPtr1;					// Memory area holding the field listing (in raw FIELD_RECORD format)
			SFieldRecord2*	field2Ptr;					// Memory area holding the field listing (using a format suitable for long field names through containers)
			u32				fieldCount;					// Number of fields in the table


			// Memory for whatever
			union {
				uptr		_cachedTable;
				s8*			cachedTable;				// If isCached, then this holds the entire table contents as of when it was cached
			};
			union {
				uptr		_data;
				s8*			data;						// Pointer to this record's line of data if locality=_DISK, or the entire table if locality=_MEMORY
			};
			union {
				uptr		_odata;
				s8*			odata;						// Pointer to this record's original line data before any changes were made
			};
			union {
				uptr		_idata;
				s8*			idata;						// Pointer to a pseudo-record suitable for constructing an index key to find through manual input
			};

			// Memo field data
			union {
				uptr		_mdata;
				s8*			mdata;						// Pointer to this record's line of data
			};
			u32				dirty;						// (locality=_MEMORY only) A flag indicating whether or not the data here is dirty (has been changed) and is not written to disk yet


			//////////
			// Index support
			//////
				s8				indexPathname[_MAX_PATH];	// Filename to get to the index (either .cdx or .idx)
				u32				indexPathnameLength;		// Length of the index filename
				_isSKeyFinds	cdx_keyOps[_MAX_CDX_TAGS];	// Room for up to N tags
				bool			isCdx;						// Is it a CDX?  If no, then is IDX.
				bool			isIdxCompact;				// If it's IDX, is it a compact IDX?
				union {
					SCdxHeader*	cdx_root;					// Pointer to the start of the .CDX
					s8*			_cdx_header;
				};
				union {
					SIdxHeader*	idx_header;					// Pointer to the start of the .IDX
					s8*			_idx_header;
				};
				FILE*			fhIndex;					// File handle for the index
		};
