//////////
//
// /libsf/source/vjr/vjr.h
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

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include "resource.h"


#define _USE_MATH_DEFINES
#include <math.h>
#include "sound\SDL-1.2.15\include\sdl\SDL.h"
#include "sound\SDL-1.2.15\include\sdl\SDL_audio.h"

#include "vjr_const.h"
#include "\libsf\utils\common\cpp\builder.h"
#include "\libsf\utils\common\cpp\builder.cpp"
#include "\libsf\utils\common\cpp\ll.cpp"
#include "vjr_structs0.h"

#include "compiler\common\compiler_common.h"

#include "compiler\vxb\const.h"
#include "compiler\vxb\structs.h"
#include "compiler\vxb\defs.h"
#include "compiler\vxb\globals.h"

#include "compiler\rdc\const.h"
#include "compiler\rdc\structs.h"
#include "compiler\rdc\defs.h"
#include "compiler\rdc\globals.h"

#include "compiler\asm\const.h"
#include "compiler\asm\structs.h"
#include "compiler\asm\defs.h"
#include "compiler\asm\globals.h"

#include "dbf\dbf.h"
#include "dbf\dbf_defs.h"

#include "grace.h"

#include "vjr_structs.h"
#include "vjr_defs.h"
#include "vjr_globals.h"

#include "fonts.h"
#include "datum\datum.h"
#include "bitmaps\bitmaps.h"

#include "commands\command_defs.h"
#include "sound\sound.h"
#include "sem.h"
#include "sem_line.h"
#include "engine.h"
#include "objects\accessors.h"

#include "bmps\graphics\bitmaps.h"
