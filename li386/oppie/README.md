Nov.22.2014
-----------

Oppie (or "Little Opcode") plans to be (James 4:15, Lord willing), a
series of mini-CPUs that perform various functions approaching a real
CPU.

Oppie-1 -- (in progress) A simple 8-bit CPU with eight opcodes, 2 KB of
		RAM, four 8-bit registers, built atop a 3-, 4-, or 5-stage
		pipeline (read instruction, decode, [read data], execute,
		[write retire] -- pipe stages in [brackets] are optional
		per instruction).

Oppie-2 -- (planned) An extension of Oppie-1 supporting more instructions,
		eight 32-bit registers and full 32-bit unsigned integer
		processing and instructions.

Oppie-3 -- (planned) Adds a stack pointer, stack, CALL and RET support.
Oppie-4 -- (planned) Adds signed integer support, interrupts, timer.
Oppie-5 -- (planned) Adds multiple tasks/processes, scheduling one at
		a time, fullly preemptive context switching.
Oppie-6 -- (planned) Adds multiple cores.

-----
The final goal is the basic framework necessary to bring the LibSF
"i386-x40" to life (hereafter called li386 for short).

The li386 architecture defines:

	(1)  Only protected-mode operations.
	(2)  32-bit or 40-bit processing.
	(3)  FPU and SIMD as first-class citizens.
	(4)  Four cores.
	(5)  1TB of addressable memory per core.
	(6)  1TB of addressable memory shared in common (5TB total).
	(7)  Support for multiple ISAs, including:
		(a) li386 (LibSF's revamp of the x86 opcodes)
		(b) liARM (a large subset of ARMv7's 32-bit ISA)
		(c) i386 ISAs (80386 opcodes with some newer features
			added bringing it closer to i686)

All of this is James 4:15, which is to say, "Lord willing," for it is
not by me, but by Him, if it is to be. :-)

Best regards,
Rick C. Hodgin
