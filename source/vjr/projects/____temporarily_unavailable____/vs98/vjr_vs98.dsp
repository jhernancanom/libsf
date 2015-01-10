# Microsoft Developer Studio Project File - Name="vjr_vs98" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=vjr_vs98 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vjr_vs98.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vjr_vs98.mak" CFG="vjr_vs98 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vjr_vs98 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "vjr_vs98 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vjr_vs98 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /Zp16 /MT /W3 /GX /O2 /I "c:\libsf\source\vjr\include\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /Zm500 /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glew32.lib glew32s.lib freeglut.lib glew32.lib ..\sound\SDL-1.2.15\lib\x86\SDL.lib /nologo /subsystem:windows /machine:I386 /out:"../vjr.exe" /libpath:"c:\libsf\source\vjr\lib\\"

!ELSEIF  "$(CFG)" == "vjr_vs98 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /Zp1 /MTd /W3 /Gm /Gi /GX /ZI /Od /I "c:\libsf\source\vjr\include\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /Zm500 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\sound\SDL-1.2.15\lib\x86\SDL.lib "C:\Program Files\Visual Leak Detector\lib\Win32\vld.lib" glew32.lib glew32s.lib freeglut.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../vjr.exe" /pdbtype:sept /libpath:"c:\libsf\source\vjr\lib\\"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "vjr_vs98 - Win32 Release"
# Name "vjr_vs98 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\vjr.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\command_defs.h
# End Source File
# Begin Source File

SOURCE=..\compiler_const.h
# End Source File
# Begin Source File

SOURCE=..\compiler_defs.h
# End Source File
# Begin Source File

SOURCE=..\compiler_globals.h
# End Source File
# Begin Source File

SOURCE=..\compiler_structs.h
# End Source File
# Begin Source File

SOURCE=..\edit_chain.h
# End Source File
# Begin Source File

SOURCE=..\edit_chain_manager.h
# End Source File
# Begin Source File

SOURCE=..\engine.h
# End Source File
# Begin Source File

SOURCE=..\object_accessors.h
# End Source File
# Begin Source File

SOURCE=..\vjr.h
# End Source File
# Begin Source File

SOURCE=..\vjr_const.h
# End Source File
# Begin Source File

SOURCE=..\vjr_defs.h
# End Source File
# Begin Source File

SOURCE=..\vjr_globals.h
# End Source File
# Begin Source File

SOURCE=..\vjr_structs.h
# End Source File
# Begin Source File

SOURCE=..\vjr_structs0.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project