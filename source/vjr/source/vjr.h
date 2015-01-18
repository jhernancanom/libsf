//////////
//
// /libsf/source/vjr/source/vjr.h
//
//////
// Version 0.55
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Feb.12.2014
//////
// Change log:
//     Feb.12.2014 - Initial creation
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

#ifndef WINVER                  // Specifies that the minimum required platform is Windows XP.
#define WINVER 0x0501           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows XP.
#define _WIN32_WINNT 0x0501     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows XP.
#define _WIN32_WINDOWS 0x0501   // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE               // Specifies that the minimum required platform is Internet Explorer 6.0.
#define _WIN32_IE 0x0600        // Change this to the appropriate value to target other versions of IE.
#endif

#include "vjr_compile_time_settings.h"


#if defined(_WIN64) || defined(_WIN32)
	// Compiling directly on Windows
	#include <windows.h>
	#include <io.h>
	#include <sys/locking.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <share.h>
	#include <sql.h>
	#include <sqlext.h>
	#include "resource.h"
	
	#define _USE_MATH_DEFINES
	#include <math.h>
	#include "sound\SDL-1.2.15\include\sdl\SDL.h"
	#include "sound\SDL-1.2.15\include\sdl\SDL_audio.h"

	#include <stdio.h>
	#include <stdlib.h>

	#include "vjr_const.h"
	
	#include "\libsf\utils\common\cpp\builder.h"
	#include "\libsf\utils\common\cpp\builder.cpp"
	#include "\libsf\utils\common\cpp\ll.cpp"
	
	#include "vjr_structs0.h"

	#include "compiler\common\compiler_common.h"

	#include "compiler\vxb\vxb_const.h"
	#include "compiler\vxb\vxb_structs.h"
	#include "compiler\vxb\vxb_defs.h"
	#include "compiler\vxb\vxb_dictionary.h"
	#include "compiler\vxb\vxb_globals.h"

	#include "compiler\rdc\rdc_const.h"
	#include "compiler\rdc\rdc_structs.h"
	#include "compiler\rdc\rdc_defs.h"
	#include "compiler\rdc\rdc_globals.h"

	#include "compiler\asm\asm_const.h"
	#include "compiler\asm\asm_structs.h"
	#include "compiler\asm\asm_defs.h"
	#include "compiler\asm\asm_globals.h"

	#include "dbf\dbf.h"

	#include "sem\sem.h"
	#include "sem\sem_line.h"
	#include "sem\sem_extra_info.h"

	#include "grace.h"

	#include "vjr_structs.h"
	#include "vjr_defs.h"
	#include "vjr_globals.h"

	#include "fonts.h"
	#include "datum\datum.h"
	#include "bitmaps\bitmaps.h"

	#include "commands\command_defs.h"
	#include "sound\sound.h"
	#include "engine.h"
	#include "objects\accessors.h"

	#include "bmps\graphics\bitmaps.h"

	//////////
	// Source files are all included in this one source file
	// for ease of compilation across platforms and compilers.
	//////
		#include "vjr_sup.cpp"
		#include "objects\accessors.cpp"
		#include "objects\base.cpp"
		#include "objects\callbacks.cpp"
		#include "objects\copy.cpp"
		#include "objects\create.cpp"
		#include "objects\delete.cpp"
		#include "objects\events.cpp"
		#include "objects\render.cpp"
		#include "objects\reset.cpp"
		#include "bitmaps\bitmaps.cpp"
		#include "compiler\vxb\vxb_compiler.cpp"
		#include "compiler\vxb\vxb_dictionary.cpp"
		#include "compiler\rdc\rdc_compiler.cpp"
		#include "compiler\asm\asm_compiler.cpp"
		#include "commands\commands.cpp"
		#include "engine.cpp"
		#include "sem\sem.cpp"
		#include "sem\sem_line.cpp"
		#include "sem\sem_extra_info.cpp"
		#include "sound\sound.cpp"
		#include "dbf\dbc.cpp"
		#include "dbf\dbf.cpp"
		#include "dbf\cdx.cpp"
		#include "grace.cpp"
		#include "datum\datum.cpp"
		#include "fonts.cpp"


#elif defined(__linux__)
	// Compiling on Linux
	#define WM_USER				0x0400
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <sys/time.h>
	#include <inttypes.h>
	#include <memory.h>
	#include <string.h>
	
	#define _USE_MATH_DEFINES
	#include <math.h>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_audio.h>

	#include "vjr_const.h"
	
	#include "/libsf/utils/common/cpp/linux/windows.h"
	#include "/libsf/utils/common/cpp/linux/hwndx.h"
	
	#include "/libsf/utils/common/cpp/builder.h"
	#include "/libsf/utils/common/cpp/builder.cpp"
	#include "/libsf/utils/common/cpp/ll.cpp"
	
	#include "vjr_structs0.h"

	#include "compiler/common/compiler_common.h"

	#include "compiler/vxb/vxb_const.h"
	#include "compiler/vxb/vxb_structs.h"
	#include "compiler/vxb/vxb_defs.h"
	#include "compiler/vxb/vxb_dictionary.h"
	#include "compiler/vxb/vxb_globals.h"

	#include "compiler/rdc/rdc_const.h"
	#include "compiler/rdc/rdc_structs.h"
	#include "compiler/rdc/rdc_defs.h"
	#include "compiler/rdc/rdc_globals.h"

	#include "compiler/asm/asm_const.h"
	#include "compiler/asm/asm_structs.h"
	#include "compiler/asm/asm_defs.h"
	#include "compiler/asm/asm_globals.h"

	#include "dbf/dbf.h"

	#include "sem/sem.h"
	#include "sem/sem_line.h"
	#include "sem/sem_extra_info.h"

	#include "grace.h"

	#include "vjr_structs.h"
	#include "vjr_defs.h"
	#include "vjr_globals.h"

	#include "fonts.h"
	#include "datum/datum.h"
	#include "bitmaps/bitmaps.h"

	#include "commands/command_defs.h"
	#include "sound/sound.h"
	#include "engine.h"
	#include "objects/accessors.h"

	#include "bmps/graphics/bitmaps.h"

	//////////
	// Source files are all included in this one source file
	// for ease of compilation across platforms and compilers.
	//////
		#include "vjr_sup.cpp"
		#include "objects/accessors.cpp"
		#include "objects/base.cpp"
		#include "objects/callbacks.cpp"
		#include "objects/copy.cpp"
		#include "objects/create.cpp"
		#include "objects/delete.cpp"
		#include "objects/events.cpp"
		#include "objects/render.cpp"
		#include "objects/reset.cpp"
		#include "bitmaps/bitmaps.cpp"
		#include "compiler/vxb/vxb_compiler.cpp"
		#include "compiler/vxb/vxb_dictionary.cpp"
		#include "compiler/rdc/rdc_compiler.cpp"
		#include "compiler/asm/asm_compiler.cpp"
		#include "commands/commands.cpp"
		#include "engine.cpp"
		#include "sem/sem.cpp"
		#include "sem/sem_line.cpp"
		#include "sem/sem_extra_info.cpp"
		#include "sound/sound.cpp"
		#include "dbf/dbc.cpp"
		#include "dbf/dbf.cpp"
		#include "dbf/cdx.cpp"
		#include "grace.cpp"
		#include "datum/datum.cpp"
		#include "fonts.cpp"
		
		#include "/libsf/utils/common/cpp/linux/windows.cpp"
		#include "/libsf/utils/common/cpp/linux/hwndx.cpp"
		
#else
	#error Unknown target for compilation (must be Windows or Linux)
#endif
