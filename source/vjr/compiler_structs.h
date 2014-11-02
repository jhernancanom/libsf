//////////
//
// /libsf/source/vjr/compiler_structs.h
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.29.2014
//////
// Change log:
//     Jun.29.2014 - Initial creation
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




struct SStartEnd;
struct SMasterList;
struct SComp;
struct SCompCallback;
struct SNode;
struct SOp;
struct SAsciiCompSearcher;
struct SStartEndCallback;
struct SLL;
struct SLLCallback;
struct SVariable;
struct SCompileContext;
struct SCompileNote;




//////////
// Structures taken from Visual FreePro
//////
	struct SMasterList
	{
		SLL				ll;						// 2-way link list to hold the related pointer
		bool			used;					// Is this entry/slot used?

		// The reference pointer used to occupy this slot/position
		void*			ptr;					// The pointer associated with this entry
	};

	// The rigidity of this structure is extremely important.
	// Every item in the chain between root and last must be included in the master list!
	struct SStartEnd
	{
		SMasterList*	root;					// Root item
		SMasterList*	last;					// Last item

		// SStartEnd lists can have a master (which points to other items using the SMasterList protocol), or it can be used merely a pointer holder
		union {
			SMasterList**	master;				// Every item in the start/end chain is appended here when created (used primarily for suspension and resumption of the VVM)
			void**			ptr;
		};
		u32				masterCount;			// Number of entries in the master array (used for resizing)

		// Not used and reserved for future use
		void*			extra;					// For future expansion
	};

	// Structure to search for things
	struct SAsciiCompSearcher
	{
		const s8*		keyword;										// Text keyword being searched
		s32				length;											// Length of the keyword (negative for case sensitive, positive case insensitive, 0 for termination entry)
		bool			repeats;										// Can this item repeat?  Or is this a one-shot keyword?
		s32				iCode;											// An associated code to store when this entry is found
		bool			firstOnLine;									// Should this item ONLY be the first on line?
		s32				iCat;											// This entry's general category (function, operator, keyword, flow)

		// For syntax highlighting
		SBgra*			syntaxHighlightColor;							// Color to display this component in
		bool			useBoldFont;									// Should this be bolded?

		// An optional extra callback to parse on finds
		union {
			u32			_onFind;
			void		(*onFind)(SAsciiCompSearcher* tacs, SComp* comp);
		};
	};

	struct SFunction
	{
		SFunction*		next;											// Next function in the chain
		SDatum			name;											// Function name (Note that code appearing at the top of a program without being enclosed in a function will have the source code line "FUNCTION top_of_program" automatically inserted at compile time

		// Knowns identified during compilation
		SVariable*		params;											// The first parameter in the function
		SVariable*		locals;											// The first local variable declared
		SVariable*		returns;										// The first return variable declared
		SVariable*		scoped;											// The first scoped/temporary variable needed by the function
		SFunction*		firstAdhoc;										// First ADHOC function contained within this function

		// Where the function began in source code as of last compile
		SEdit*		firstLine;											// First line of the function
		SEdit*		lastLine;											// Last line of the function
	};

	struct SCompileContext
	{
		// Counters
		u32			sourceLines;
		u32			blankLines;
		u32			commentLines;

		u32			functions;
		u32			params;
		u32			locals;
		u32			scoped;
		u32			returns;

		u32			errors;
		u32			warnings;
	};

	// Used in the compile_Vxbmm() functions so one parameter is passed rather than multiple
	struct SCompileVxbmmContext
	{
		// Parameters
		SEM*	codeBlock;
		SCompileContext*	ccData;
		bool				editAndContinue;

		bool				llProcessThisLine;
		SCompileContext		ccDataLocal;
		SEdit*			line;
		SFunction*			func;
		SFunction*			currentFunction;
		SFunction*			adhoc;
		SFunction*			currentAdhoc;
		SComp*				comp;
	};

	struct SOp
	{
		u32				op_type;										// The type of operand, see _OP_TYPE_* constants

		// Pointer to first (if there is a succession)
		bool			isOpDataAllocated;								// Is the op below allocated?  If false, then it points to one allocated elsewhere
		union {
			// Used as a general test to see if something exists (if (op_data != 0))
			u32			op_data;

			// Actual data items based on op_type
			SComp*		comp;											// The first component
			SVariable*	variable;										// Generic access to (param, local, scoped, other)
			SVariable*	param;											// A parameter variable or reference
			SVariable*	local;											// A local variable or reference
			SVariable*	scoped;											// A scoped/temporary variable or reference used for inter-source-code-line processing
			SVariable*	returns;										// A returns variable or reference
			SVariable*	other;											// Unknown item which must be looked up in the context of the runtime environment
			SObject*	obj;											// An object reference
			SFunction*	func;											// A function reference
		};
		// Number thereafter
		s32				count;											// The number of components (in comp or other) as input
	};

//////////
//
// Sub-instructions are components of a source code line broken out into individual tasks.
//
// They conduct those individual operations only, being part of the larger computation
// taking place across multiple sub-instructions.
//
// This structure is used for two operations in VJr.  One is for parsing source code into
// sub-instructions, the second is for generating actual sub-instruction lists for faster
// execution by the processing engine while still retaining edit-and-continue abilities.
//
//                      ______
//                     |parent|
//                     |______|
//                        ^
//                        |
//                     ___|___
//       _____        | Sub-  |        _____
//      | prev|<------| Instr |------>|next |
//      |_____|       |_______|       |_____|
//                    /       \
//                   /         \
//               ___/_         _\___
//              |left |       |right|
//              |_____|       |_____|
//
//////
	// Processing ops
	struct SNodeOps
	{
		// Operation layer/level and instruction at that level
		s32				sub_level;										// The sub-instruction operation level related to the bigger picture
		s32				sub_instr;										// The sub-instruction being executed, such as "+" in "2 + 4", see _SUB_INSTR_* constants
		SOp				op;												// Any operand data for this node (if it is a terminating node)

		// Note that in some cases there can be multiple return variables.
		// When this happens, the left-most result is always the firstVariable, with each return result being then at x->next until the end
		SVariable*		firstVariable;									// As results are computed or referenced, they are stored in scoped/temporary variables
		u32				variable_count;									// The number of variables
	};

	// General nodes
	struct SNode
	{
		u32				uid;											// Unique ID for this sub-instruction

		// Directions from the central node
		union {
			SNode*		parent;											// Up to the higher node
			SNode*		north;
		};
		union {
			SNode*		prev;											// Previous item in the horizontal chain
			SNode*		west;
		};
		union {
			SNode*		next;											// Next item in the horizontal chain
			SNode*		east;
		};
		union {
			SNode*		left;											// Left node
			SNode*		extra;											// Pointer to an extra direction for this node
		};
		union {
			SNode*		right;											// Right node
			SNode*		south;
		};

		// Node data
		union {
			void*		extraData;										// General purpose data
			SNodeOps*	opData;											// When used as for processing ops
		};
	};

	// A component structure
	struct SComp
	{
		SLL				ll;												// 2-way link list

		// Information about the component
		SEdit*			line;											// The line this component relates to
		s32				iCode;											// Refer to _ICODE_* constants
		s32				iCat;											// Refer to _ICAT_* constants
		SBgra*			color;											// Syntax highlight color
		bool			useBoldFont;									// Syntax highlight font should be bold?
		s32				start;											// Start into the indicates line's source code
		s32				length;											// Length of the component
		s32				nbspCount;										// Number of non-breaking-spaces in this component

		// For each compilation pass, components can be marked in error or warning or both
		bool			isError;										// Is this component part of an error?
		bool			isWarning;										// Is this component part of a warning?

		// For selected components
		SBgra*			overrideSelectionBackColor;
		SBgra*			overrideSelectionForeColor;

		// If this is a character that matches something (the closest parenthesis, bracket, or brace) then this color will be populated
		SBgra*			overrideMatchingForeColor;
		SBgra*			overrideMatchingBackColor;

		// For faster rendering in source code windows
		SBmpCache*		bc;												// Holds drawn things (casks for example)
	};

	struct SCompCallback
	{
		union {
			SComp*		comp;											// Component at start, and the component to continue processing after upon exit
			s8*			text;											// Raw text (depending on when it is being processed
		};
		u32				length;											// If raw text, the length of the thing being searched, otherwise 0.
		u32				iCode;											// The iCode being queried

		// Callback callbacks for adjustment
		union {
			u32			_insertCompByComp;
			void		(*insertCompByComp)		(SComp* compRef, SComp* compNew, bool tlInsertAfter);
		};
		union {
			u32			_insertCompByParams;
			void		(*insertCompByParams)	(SComp* compRef, SEdit* line, u32 tniCode, u32 tnStart, s32 tnLength, bool tlInsertAfter);
		};
		union {
			u32			_deleteComps;
			void		(*deleteComps)			(SComp* comp, SEdit* line);
		};
		union {
			u32			_cloneComps;
			SComp*		(*cloneComps)			(SComp* comp, SEdit* line);
		};
		union {
			u32			_mergeComps;
			SComp*		(*mergeComps)			(SComp* comp, SEdit* line, u32 tnCount, u32 tniCodeNew);
		};
	};

	struct SStartEndCallback
	{
		union
		{
			u32		_func;
			bool	(*funcBool)	(SStartEndCallback* cb);	// This callback should return false to continue searching, or true when the item is found
			void	(*funcVoid)	(SStartEndCallback* cb);
			//////
			// Uses the following format for the callback:
			//		bool func(SStartEndCallback* cb)
			//////////
		};

		// Data items for this callback
		// Primary pointer
		void*		ptr;

		union {
			// Extra1
			u32			ex1;
			u32			extra1;
			u32			extra;
			u32			count1;
			union {
				u32		count1_1;
				u32		count1_2;
			};
			void*		ex1Ptr;
		};

		union {
			// Extra2
			u32			ex2;
			u32			extra2;
			u32			count2;
			union {
				u32		count2_1;
				u32		count2_2;
			};
			void*		ex2Ptr;
		};
	};

	// For warnings, errors, and notes
	struct SCompileNote
	{
		SLL				ll;
		u32				start;											// Column the note begins on
		u32				end;											// Column the note ends on

		u32				number;											// Related number
		SDatum*			msg;											// The message
	};

	// Holds compiler data
	struct SCompiler
	{
		// EC was designed with source code in mind, and that means a tight compiler relationship
		SEdit*			parent;											// The EC this belongs to (parent->parent points back to EM)

		// The last source code line
		SDatum*			sourceCode;										// Copy at last compile of LEFT(parent->sourceCode.data, parent->sourceCodePopulated)

		// Components compiled in prior compiler passes
		SComp*			firstComp;										// Pointer to the first component identified on this line
		SComp*			firstWhitespace;								// Whitespaces are removed for ease of compilation, but they persist here for rendering and reference

		// Executable code
		SNode*			firstNode;										// Low-level executable code (nodes, or sub instructions) for this line
		u32				nodeArrayCount;									// How many sub-instructions there are

		// Results of compilation
		SCompileNote*	errors;											// Noted error
		SCompileNote*	warnings;										// Noted warning
		SCompileNote*	notes;											// Noted notes (LOL)
	};
