//////////
//
// /libsf/source/vjr/dbf.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Nov.02.2014
//////
// Change log:
//     Nov.02.2014 - Initial creation
//////
//
// This software is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// You are free to use, copy, modify and share this software.  However, it can only
// be released under the PBL version indicated, and every project must include a copy
// of the pbl.txt document for its version as is at http://www.libsf.org/licenses/.
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
// Constants
//
/////
	#define 	_NO							0
	#define 	_YES						1
	#define		_MAX_DBF_SLOTS				512			// Up to 512 work areas can be opened simultaneously
	#define		_MAX_CDX_TAGS				128			// Up to 128 index tags are supported per CDX, per DBF

	// For field flags
	#define 	_DBF_FIELD_SYSTEM			0x01
	#define 	_DBF_FIELD_NULLS			0x02
	#define 	_DBF_FIELD_BINARY			0x04
	#define 	_DBF_FIELD_AUTO_INC			0x0c
	
	// Miscellaneous access
	#define 	_BIT_1						0x1
	#define 	_BIT_2						0x2
	#define 	_BIT_4						0x4
	#define 	_BIT_8						0x8
	#define 	_BIT_16						0x10
	#define 	_BIT_32						0x20
	#define 	_BIT_64						0x40
	#define 	_BIT_128					0x80




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
			//		C–Character		Y–Currency	D–Date		T-DateTime
			//		B–Double		F–Float		G–General	I–Integer
			//		L–Logical		M–Memo		N–Numeric	P–Picture
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
	// Structure used to hold the open tables
	/////
		// An internal structure (_is) for speeding through successive data finds
		struct _isSKeyFinds
		{
			// FOR clause (if any)
			SForClause*		forClause;

			// Key operations to generate an index key
			SCdxKeyOp*		keyOps;
			s32				keyOpCount;				// Number of keys in key ops
		};

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
			s8*				cachedTable;				// If isCached, then this holds the entire table contents as of when it was cached
			s8*				data;						// Pointer to this record's line of data if locality=_DISK, or the entire table if locality=_MEMORY
			s8*				odata;						// Pointer to this record's original line data before any changes were made
			s8*				idata;						// Pointer to a pseudo-record suitable for constructing an index key to find through manual input

			// Memo field data
			s8*				mdata;						// Pointer to this record's line of data
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


	//////////
	// CDX-specific structures
	//////
		// Steps used in building index keys from fiel data
		struct SCdxKeyOp
		{
			u32		offsetRow;						// Offset into the row data
			u32		offsetKey;						// Offset into the key data
			s32		length;							// Length of the index key generated for the field
			s32		fieldLength;					// Length of the raw field contents
			u32		indexFixup;						// Any fixup operation to perform on this portion of the key data

			// For fields that support NULL values
			u32		null_offset;					// Offset into the row data
			u8		null_mask;						// Byte mask to determine if the field is NULL
		};

		// A CDX key pointer into a leaf node
		struct SCdxKeyPtr
		{
			// If keyLength is 0, then this will be node, otherwise it's the record number in big-endian form (needs BSWAP run on it)
			union {
				u32		record;						// Converted from its native type to little-endian form automatically
				u32		fileOffset;					// In little-endian form
			};
			u32			record2;					// Compact indexes store both the record number and file_offset for root and index nodes
			u32			offset;						// Offset from the end of the node where this key begins

			// Pointer to the key data
			u32			keyLength;					// Length of the key


		//////////
		// Note:  There is a constraint in the design that this always be the last member.
		//        The data is copied above using memcpy(dst, src, sizeof(SCdxKeyPtr) - sizeof(dst.keyPtr));
		//////
			u8*			keyPtr;						// Reconstructed key from its compact form
		};

		// A copy of the data in SCdxKeyPtr, but one which holds the actual key contents, used for passing keys back and forth
		struct SCdxKey
		{
			// If keyLength is 0, then this will be node, otherwise it's the record number in big-endian form (needs BSWAP run on it)
			union {
				u32		record;						// Converted from its native type to little-endian form automatically
				u32		fileOffset;				// In little-endian form
			};
			u32			record2;					// Compact indexes store both the record number and file_offset for root and index nodes
			u32			offset;						// Offset from the end of the node where this key begins

			// Pointer to the key data
			u32			keyLength;					// Length of the key
			u8			key[256];					// Reconstructed key from its compact form
		};

		// Used during node traversal
		struct SCdxKeyTrailInterior
		{
			u32			record2;					// Record number
			u32			fileOffset;				// File offset to access related node
		};

		// Holds information about the leaf key header (the part which increases from offset 0)
		struct SCdxKeyTrail
		{
			u32			record;						// Record number
			u16			count_DC;					// Duplicate byte count
			u16			count_TC;					// Trailing byte count
		};

		// Holds root node information for individual CDX tags, and also raw IDX nodes
		struct STagRoot
		{
			u32			leftmostNode;				// Offset to first node of the index
			u32			highestNode;				// Offset to the highest node of the index
			bool		isDescending;				// Is this a descending index?
			u32			keyLength;					// Length of the key for this tag

			u8			fillChar;					// Based on the index expression, will either be a space or null
			bool		swapEndians;				// Based on the index expression, it can be stored big-endian if it's an integer, currency, float, or double
			bool		needsSignBitToggled;		// Based on the index expression, if it's integer, currency, float or double, after the big-endian to little-endian swap, it needs the most significant bit toggled, and if negative, then it needs all bits toggled

			// Only used if a CDX node
			u32			keyNode;					// Offset to node holding key information
			u8			tagName[10];				// Tag name
		};

		// Holds information about a CDX leaf node
		struct SCdxNode
		{
			u16			type;						// 0,2		0=index node, 1=root node, 2=leaf node, 3=root+leaf. There are also types where bit3 is enabled, but I cannot find documentation as to what it is.  As such, we use the (type & 0x3) comparison for everything to mask off those bits.
			u16			keyCount;					// 2,2		Number of keys in this node which have this index key
			u32			nodeLeft;					// 4,4		Node going left, -1 if none
			u32			nodeRight;					// 8,4		Node going right, -1 if none
			// Non-compact keys begin immediately after this
													// 12,N		Up to 488 bytes for the non-compact index keys
													// 512 bytes max

			// nodeFreeSpace is only used if is an exterior/leaf node
			u16			nodeFreeSpace;				// 12,2		Number of bytes available in this node

			// The following are in compact indexes
			u32			mask_RN;					// 14,4		(RN) Record Number mask
			u8			mask_DC;					// 18,1		(DC) Duplicate byte Count mask
			u8			mask_TC;					// 19,1		(TC) Trailing byte Count mask
			u8			bits_RN;					// 20,1		Number of bits used for record number
			u8			bits_DC;					// 21,1		Number of bits used for duplicate count
			u8			bits_TC;					// 22,1		Number of bits used for trail count
			u8			totalBytesIn_RNDCTC;		// 23,1		?? Don't know
			// Keys begin immediately after this	// 24,N		Up to 488 bytes for the compact index keys
													// 512 bytes max
		};

		// This structure is the first found in the CDX, but it is also the same structure used
		// for each index tag contained within.
		struct SCdxHeader
		{
			u32			root;						// 0,4		Pointer to the root node (SCdxInteriorNode*)
			u32			free;						// 4,4		Pointer to the first free node (-1 if not present) (SCdxInteriorNode*)
			union {
				u32		reserved1;					// 8,4
				u32		fileSize;					// Note:  Used internally only, this is not stored on the disk
			};
			u16			keyLength;					// 12,2		Number of bytes in each key
			u8			options;					// 14,1		1=UNIQUE, 2=Temporary index, 4=Custom index, 8=FOR clause, 16=??, 32=Compact, 64=Compound, 128=Structural index
			u8			signature;					// 15,1		Index signature

			u32			reserved2;					// 16,4
			u32			reserved3;					// 20,4
			u32			reserved4;					// 24,4
			u32			reserved5;					// 28,4
			u32			reserved6;					// 32,4
			u8			reserved7[466];				// 36,466

			u16			order;						// 502,2	0=Ascending, 1=Descending
			u16			reserved8;					// 504,2

			u16			forClauseLength;			// 506,2	Length of FOR clause
			u16			reserved9;					// 508,2	

			u16			keyExpressionLength;		// 510,2	Length of index key expression
			s8			keyExpression[512];		// 512,512	The key and FOR clause expression storage area, in that order, each is NULL-terminated
													// 1024 bytes
		};

		// Pointer to each key record in an IDX leaf node
		struct SIdxKey
		{
			// Pointer to the key data
			union {
				s8*		key;						// Pointer to the key data
				u32		_key;						// Same value in 32-bit form
			};

			u32			keyLength;					// Length of the key

			// If keyLength is 0, then this will be node, otherwise it's the record number in big-endian form (needs BSWAP run on it)
			union {
				u32		record;						// Converted from its native type to little-endian form automatically
				u32*	node;						// In little-endian form
			};
		};

		// Every IDX node has this header
		struct SIdxNode
		{
			u16			type;						// 0,2		0=index node, 1=root node, 2=leaf node
			u16			keyCount;					// 2,2		Number of keys in this node which have this index key
			u32			nodeLeft;					// 4,4		Node going left, -1 if none
			u32			nodeRight;					// 8,4		Node going right, -1 if none
			// Immediately after this is additional variable-length data:
			// Repeating:
			//		12 + keyLength + (keyCount*4) bytes
			//		Note:  There may be garbage beyond the valid populated data stored in the index nodes, it should be ignored.
		};

		// The first node in an IDX file
		struct SIdxHeader
		{
			u32			root;						// 0,4		Offset to the root node (SIdxNode*)
			u32			free;						// 4,4		Offset to the first free node (-1 if not present) (SIdxNode*)
			u32			fileSize;					// 8,4		File size in bytes
			u16			keyLength;					// 12,2		Number of bytes in each key
			u8			options;					// 14,1		1=UNIQUE, 8=FOR clause
			u8			reserved1;					// 15,1
			s8			keyExpression[220];			// 16,220	Key expression itself
			s8			forClause[220];				// 236,220	FOR clause expression
			u8			reserved2[56];				// 456,56
			// Total size: 512 bytes
		};




	//////////
	// Used for processing DBF and CDX data
	//////
		struct SForOp
		{
			// Row/temp data for left-hand thing
			union {
				u32			tempIndexL;				// Index into the temporary data
				u32			offsetL;				// Offset into the row data
			};
			u32				lengthL;				// Length of the thing to compare (typically also always the right-hand length as well if used)

			// Row/temp data for right-hand thing
			union {
				u32			tempIndexR;				// Index into the temporary data
				u32			offsetR;				// Offset into the row data
			};

			// See _FOR_CLAUSE_OPS_* constants in dbf_defs.h
			u32				op;				// The operation to conduct
		};

		// Temporary data space used for constants found in the FOR expression
		struct SForTemp
		{
			s8*				data;					// Data for this temporary
			u32				length;					// Length of the data
		};

		// For multiple entries in the FOR clause
		struct SForSubItem
		{
			s8*				start;					// Pointer to the starting item
			s8*				end;					// Where it ends
			u32				length;					// Length

			u32				type;					// Known type
		};

		// For clauses are executed on each line to determine a result
		// They are a series of operations
		struct SForClause
		{
			SForOp*			ops;					// A list of operations to perform on the row data
			s32				opCount;				// Number of items in the for clause test
			s32				opAllocated;			// Number of ops allocated

			SForSubItem*	subitems;				// Access to sub-items in the expression
			s32				subitemCount;			// Number of subitems in use
			s32				subitemAllocated;		// Number of subitems allocated

			SForTemp*		temps;					// A list of temporaries referenced by SForClauseOp->operation
			s32				tempCount;				// Number of temporary items
			s32				tempAllocated;			// Number of temporary items allocated
		};




//////////
//
// Global variables
//
/////
    s8			gcDbf_temporaryPath[_MAX_PATH];
    u32			gnDbf_temporaryFileNumber	= 0;

	// sort variables for qsort()
	u32			gnCdx_sort_keyLength		= 1;

	// Table and cursor work areas
    SWorkArea	gsArea[_MAX_DBF_SLOTS];
	s32			gnDbf_currentWorkArea		= 0;