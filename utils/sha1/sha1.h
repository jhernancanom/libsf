//////////
//
// /libsf/utils/sha1/sha1.h
//
//////
//    _     _ _     _____ _____ 
//   | |   (_) |__ / ____|  ___|
//   | |   | | '_ \\___ \|  __|
//   | |___| | |_) |___) | |
//   |_____|_|_.__/_____/|_|
//
//   Liberty Software Foundation
// and the Village Freedom Project
//   __     _______     ____  
//   \ \   / /  ___| __|  _ \ 
//    \ \ / /| |_ | '__| |_) |
//     \ V / |  _|| |  |  __/ 
//      \_/  |_|  |_|  |_|
//
//////
// Version 1.00
// Public Domain - See sha1.cpp.
//////
// Last update:
//     Feb.17.2013
//////
// Change log:
//     Feb.17.2013 - Initial creation, compiles with OSS in VS2008 Professional.
//////
//
// This software is released into the Public Domain.  Enjoy. :-)
//
//     http://www.libsf.org/
//
// Thank you.  And may The Lord bless you richly as you lift up
// your life, your talents, your gifts, your praise, unto Him.
// In Jesus' name I pray.  Amen.
//
//////




//////////
// Constants (defined so they're visible in the debugger)
//////
	const u32	_SHA1_NUMBER_SIZE	= 20;
	const u32	_SHA1_CONTEXT_SIZE	= 92;


//////////
// Forward declarations used outside of the SHA-1 sha1.cpp source code
//////
	void			sha1_computeSha1					(cu8* tcData, u32 tnLength, u8 sha20Bytes[_SHA1_NUMBER_SIZE]);
	void			sha1_convertSha20ToHex				(cu8 sha20Bytes[_SHA1_NUMBER_SIZE], s8* tcHexOutput, bool tlSpacesBetween);
	void			sha1_computeSha1AsHex				(cu8* tcData, u32 tnLength, u8 sha20Bytes[_SHA1_NUMBER_SIZE], s8* tcHexOutput, bool tlSpacesBetween);
	void			sha1_convertHexToSha20				(cs8* tcHexInput, u8 sha20Bytes[_SHA1_NUMBER_SIZE], bool* tlError);
	void			sha1_92initialize					(u8 context[92]);
	void			sha1_92continueOnThisData			(u8 context[92], const u8* tcData, u32 tnLength);
	void			sha1_92finalize						(u8 context[92], u8 sha20Bytes[_SHA1_NUMBER_SIZE], bool tlWipeData);
	u64				sha1_convertSha20To64Bit			(u8 sha20Bytes[_SHA1_NUMBER_SIZE]);
	u32				sha1_convertSha20To32Bit			(u8 sha20Bytes[_SHA1_NUMBER_SIZE]);
	bool			sha1_compare						(u8 sha20Bytes1[_SHA1_NUMBER_SIZE], u8 sha20Bytes2[_SHA1_NUMBER_SIZE]);


//////////
// Direct 64-bit tests
//////
	u64				sha1_computeAs_u64					(cu8* tcData, u32 tnLength);
	u64				sha1_computeAs_u64					(SDatum* datum);
	u64				sha1_computeAs_u64					(SVariable* var);


//////////
// Direct 32-bit tests
//////
	u32				sha1_computeAs_u32					(cu8* tcData, u32 tnLength);
	u32				sha1_computeAs_u32					(SDatum* datum);
	u32				sha1_computeAs_u32					(SVariable* var);
