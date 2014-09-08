--------------

        -- You are not alone in your Visual FreePro interest! --

        www.visual-freepro.org site-wide web statistics
        May.13.2013 through Sep.07.2014 (482 days)
        * 24,856 unique IP address hits.
        * Of those visiting on more than 10 separate days, each IP address visits on an average of 30 separate days.
        * 678 have visited on 10 days or more, 152 on 30 separate days, 81 on 50 separate days.
        * Excluding Rick C. Hodgin and bots, 20 users have visited the site on more than 100 separate days.
        * 706 separate IP addresses have downloaded at least one video.
        * 12,607 video downloads initiated (includes pauses, restarts, rewinds, fast forwards, and jump to hh:mm).

--------------

        Visual FreePro, Jr. specific
        Jun.01.2014 through Sep.07.2014 (98 days)
        * 3,423 unique IP address hits.
        * 89 of those have visited the site on more than 10 separate days. 18 on at least 25 separate days.
        * 72 separate IP addresses have downloaded at least one video.
        * 672 video downloads initiated (includes pauses, restarts, rewinds, fast forwards, and jump to hh:mm).
        * The Jul.12.2014 video Adding a function to VJr has been initiated 349 times by 51 IP addresses.

--------------
		
        Mar.31.2014 - RCH - All development has been moved to local LibSF servers until
        the next milestone is achieved.  Please check back periodically.  Thank you.

--------------

        This repository contains all source code maintained by the Liberty Software
        Foundation (LibSF).  Our talents and skills given back to God, from whom they
		come, being used to serve His Kingdom here upon this Earth.  In much prayer and
		supplication, knowing that He is able to do exceedingly abundantly beyond any
		of our needs.  Jesus Christ, our Savior, to Him be all the glory.

--------------

        Mar.09.2014 - Development is ongoing.  Working on VASM, VDeb, and the VVM execution engine per OBED 0.70.
        Jan.28.2014 - Development is ongoing.  Slow and steady wins the race. :-)
        May.11.2013 - Development of WhiteBox continues.  About 2500 lines of code.
        Apr.29.2013 - Development on Visual FreePro is suspended pending the completion of WhiteBox.
        Apr.29.2013 - Development of WhiteBox begins.

--------------

        As of Feb.20.2013, it contains The Visual FreePro Project,
        which is comprised of several sub-components:

        (1) VVM    - The Visual FreePro Virtual Machine top-level program.
        (2) OSS    - The VVM Operating System Specific code.
        (3) MC     - The VVM Machine Code assembler, disassembler for debugger.
        (4) VASM   - The VVM source code assembler.
        (5) VDeb   - The VVM Debugger (a compiled DLL).
        (6) VDebugLauncher - The VVM Debugger launcher (tells VVM to load the debugger DLL).
        (7) Localization - Supporting resource DLLs for English and Spanish.
        (8) For more information, see:  https://github.com/RickCHodgin/libsf/blob/master/vvm/how_to_contribute.txt
        (9) For more information, see:  http://www.visual-freepro.org/videos/

--------------

vvm
====
        The Visual FreePro Virtual Machine, independent and capable
        of being used for non-VFrP applications.  The VVM is localized
        through vvmenu.dll, with "enu" being replicated to other
        languages, such as "es" for Spanish, etc.
        
        Note:  To run the application, see README.md in vvm\bin\.
        Note:  To contribute to vvm, email rick.c.hodgin@gmail.com
        
        If you'd like to compile and try the application yourself, in-
        stall to the \libsf\ directory.  Some paths are currently hard-
        coded to that location.  In time, this will be made relative.


vvm\oss
====
        VVM's Operating System Specific code.


vvm\mc
====
        VVM's Machine Code support DLL. It is a common/shared component
        used to carry out work converting assembly source code into VVM
        machine code (assembly), the reverse (dissassembly), and other
        functions related to symbolic debugging information and convertying
        to and from the VVM's executable file format, which is RXML format.


vvm\vdeb
====
        A VVM debugger used for debugging native VVM programs.  The
        debugger is resource localized through vdebugenu.dll, with "enu"
        being the default. It is then replicated to other languages.
        Currently, The Visual FreePro Project maintains: English, Spanish.


vvm\vdebugLauncher
====
        The VVM debugger launcher (loads vdebug.dll into a running
        VVM instance).  Multiple debugger connections to a single,
        running VVM instance can be achieved, each debugging a different
        program, thread, or snippet (function).


vvm\vasm
====
        VVM's Assembler. This is a stand-alone application sed to convert
        from the command line VVM assembly source code into machine code
        the VVM can execute. As of Nov 23, 2012, development is focused
        on VASM, VVMMC and VVM's execution engine.


vvm\localization
====
        VVM supports localization DLLs in English and Spanish for three
        separate modules:  vvm, vdebug and vvmmc.


apps\whitebox
====
        WhiteBox is a non-linear audio/video editor.  Jan.28.2014 On hold
        pending additional completion of the virtual machine and supporting
        infrastructure.  However, still planned.


Future Plans
====
        Jul.15.2014 - (planned) Visual FreePro 0.70 is released, able to execute several commands.


Timeline
====
        See the https://github.com/RickCHodgin/libsf-full for the historic timeline.
        See this repository for day-to-day updates and changes.
