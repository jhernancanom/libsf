Nov.22.2014
-----------

The li386 folder was created to support the LibSF i386-x40 CPU design,
a 40-bit extension of the traditional i386 architecture with several
internal changes to make it a much simpler core:

	(1)  Only protected mode is supported.
	
	(2)  Hardware-only FPU and SIMD support.
	
	(3)  32-bit (eax) and 40-bit processing (wax) registers.
	
	(4)  32-bit and 40-bit memory address modes.
	
	(5)  Four-core base design.
	
	(6)  1TB of addressable memory per core.
	
	(7)  1TB of common / shared memory between cores.
	
	(8)  Removal of traditional paging support, replaced with a new concept called Memory Monitor Range, which simulates features of paging in a heavily memory'd environment (such as with 1 TB of addressable RAM).
		
	(9)  Hardware support for multiple ISAs:
	
		(a) li386 -- A revamping of i386 opcodes
		
		(b) liARM -- Support for a large subset of ARMv7
		
		(c) i386  -- The original 80386 ISA with some tweaks.

We'll see what the Lord brings.  Currently there are test projects
under development to make li386 a reality, codenamed "Oppie" for
"little opcodes."

See the oppie folder for current progress.  As of Nov.27.2014:

	(1)  Oppie-1 -- (in progress) an 8-bit core, 5-stage pipeline
	(2)  Oppie-2 -- (planned) Extended Oppie-1 to 32-bits, stack, interrupts
	(3)  Oppie-3 -- (planned) A largely i386 compatible core, no FPU or SIMD
	(4)  Oppie-4 -- (planned) A dual-core Oppie-3
	(5)  Oppie-5 -- (planned) A single-thread LibSF 386-x40
	(6)  Oppie-6 -- (planned) Add Love Threading, Love Processing
	(7)  Oppie-7 -- (planned) Dual-core Oppie-6

Best regards,
Rick C. Hodgin
