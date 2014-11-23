//////////
//
// Oppie-1 -- Simple CPU able to execute these instructions:
//
//		ASM Instruction			Bytes		Opcode Bit Encoding (x=unused)
//		-------------------		------		------------------------------
//											* Register encodings are 2 bits
//		mov   reg8,[address]	2			000.00.000:00000000
//		mov   reg8,reg8			1			001.x.00.00	(dest,src)
//		add   reg8,reg8			1			0100.00.00
//		adc   reg8,reg8			1			0110.00.00
//		sub   reg8,reg8			1			0101.00.00
//		sbb   reg8,reg8			1			0111.00.00
//		mov   [address],reg8	2			100.00.000:00000000
//		cmp   reg8,reg8			1			101.x.00.00	(left,right)
//		jz    +/- 1KB			2			110.xx.s.00:00000000
//		jmp   +/- 1KB			2			111.xx.s.00:00000000 
//
// Using this environment:
//
//		8-bit Regs			Flags			Memory
//		---------------		---------		-----------
//		r1 -- 00000000		zero?			2 Kilobytes
//		r2 -- 00000000		carry?
//		r3 -- 00000000
//		r4 -- 00000000
//		ip -- 00000000		// Instruction pointer
//
//////
module oppie1();

	//////////
	// Oppie operational mechanics
	//////
		reg					clk;				// Clock signal
		reg					i_halt;				// Instruction halt
		
		// Flags between pipe stages
		reg					ok_i_fetch;			// Okay to fetch the next instruction?
		reg					ok_i_decode;		// Okay to decode the next instruction?
		reg					ok_d_read;			// Okay to read data?
		reg					ok_i_process;		// Okay to process the instruction?
		reg					ok_d_write;			// Okay to write/retire the data?
		
		// Valid pipe stage (used for refilling after branch)
		reg		[2:0]		pipe_valid;
		reg					ok_pipe_stage2;		// Indicates if stage-2 is okay
		reg					ok_pipe_stage3;		// Indicates if stage-3 is okay
		reg					ok_pipe_stage4;		// Indicates if stage-4 is okay
		`define STAGE0		3'b000
		`define STAGE1		3'b001
		`define STAGE2		3'b010
		`define STAGE3		3'b011
		`define STAGE4		3'b100
	
	
	//////////
	// Oppie register state
	//////
		reg		[1:0]		flags;				// bit-0=zero? bit-1=carry?
		reg		[7:0]		r1;					// 8-bit R1 general purpose register
		reg		[7:0]		r2;					// 8-bit R1 general purpose register
		reg		[7:0]		r3;					// 8-bit R1 general purpose register
		reg		[7:0]		r4;					// 8-bit R1 general purpose register
		reg		[10:0]		ip;					// 11-bit IP instruction pointer (2 KB)
		
		`define R1			2'b00
		`define R2			2'b01
		`define R3			2'b10
		`define R4			2'b11
		
		`define CARRY		1'b1
		`define ZERO		1'b0


	//////////
	// Memory write
	//////
		reg					write_clk;
		reg					write_enable;
		reg		[10:0]		write_address;
		reg		[7:0]		write_data;

	
	//////////
	// Memory reads
	//////
		reg					read_clk;
		reg					read1_enable;		// Instruction 1 (read in stage 1)
		reg		[10:0]		read1_address;
		wire	[7:0]		read1_data;
	  
		reg					read2_enable;		// Instruction 2 (read in stage 1)
		reg		[10:0]		read2_address;
		wire	[7:0]		read2_data;
	  
		reg					read3_enable;		// Data 1 (read in stage 3)
		reg		[10:0]		read3_address;
		wire	[7:0]		read3_data;
	
	
	//////////
	// Queues for pipe stages
	//////
		reg		[10:0]		p1_ip_address;		// ip address as of the instruction fetch
		
		reg		[7:0]		p2_i_data1;			// i-data 1 read from stage 1
		reg		[7:0]		p2_i_data2;			// i-data 2 read from stage 1
		reg		[1:0]		p2_reg_src;			// Register source for stage 4
		reg		[1:0]		p2_reg_dst;			// Register destination for stage 4
		reg					p2_read_ok;			// Is it oky to read data in stage 3
		reg		[10:0]		p2_read_address;	// Read address for stage 3
		reg		[10:0]		p2_write_address;	// Write address for stage 5, i_write
		reg		[9:0]		p2_ip_sign;			// Direction for jump targets stage 4
		reg		[9:0]		p2_ip_delta;		// Delta for jump targets stage 4
		reg		[10:0]		p2_ip_address;		// ip of this instruction
		reg		[3:0]		p2_process_op;		// Operation to conduct for stage 4

		reg		[1:0]		p3_reg_src;			// Register source for stage 4
		reg		[1:0]		p3_reg_dst;			// Register destination for stage 4
		reg		[7:0]		p3_data;			// Data read in stage 3
		reg		[10:0]		p3_write_address;	// Write address for stage 5, i_write
		reg		[9:0]		p3_ip_sign;			// Direction for jump targets stage 4
		reg		[9:0]		p3_ip_delta;		// Delta for jump targets stage 4
		reg		[10:0]		p3_ip_address;		// ip of this instruction
		reg		[3:0]		p3_process_op;		// Operation to conduct for stage 4

		reg		[1:0]		p4_reg_src;			// Register source for stage 4
		reg		[1:0]		p4_reg_dst;			// Register destination for stage 4
		reg		[7:0]		p4_data;			// Data read in stage 3
		reg		[7:0]		p4_result;			// Computed result stage 4
		reg		[10:0]		p4_write_address;	// Write address for stage 5, i_write
		reg		[9:0]		p4_ip_sign;			// Direction for jump targets stage 4
		reg		[9:0]		p4_ip_delta;		// Delta for jump targets stage 4
		reg		[10:0]		p4_ip_address;		// ip of this instruction
		reg		[3:0]		p4_process_op;		// Operation to conduct for stage 4
		reg					p4_carry;			// Used for common operations

		reg		[10:0]		p5_write_address;	// Write address for stage 5, i_write
		reg		[7:0]		p5_result;			// Computed result stage 4
	
	
	//////////
	// Process ops
	//////
		reg		[3:0]		i_process_op [2:0];
		
		`define MOV_FROM_MEM8	4'b0000
		`define MOV				4'b0001
		`define ADD				4'b0010
		`define ADC				4'b0011
		`define SUB				4'b0100
		`define SBB				4'b0101
		`define MOV_TO_MEM8		4'b0110
		`define CMP				4'b0111
		`define JZ				4'b1000
		`define JMP				4'b1001
	

	//////////
	//
	// Instantiate i-data and d-data:
	//		BITS_DATA		= 8
	//		BITS_ADDRESS	= 11
	//		SIZE_RAM		= 2048		// BITS_DATA count
	//
	//////
	  ram_1_3 #(8, 11, 2048)	i_d_data(	.write_clk		(write_clk),
											.write_enable	(write_enable),
											.write_address	(write_address),
											.write_data		(write_data),
											
											.read_clk		(read_clk),
											.read1_enable	(read1_enable		&&	ok_i_fetch	&&	~i_halt),
											.read1_address	(read1_address),
											.read1_data		(read1_data),
											
											.read2_enable	(read2_enable		&&	ok_i_fetch	&&	~i_halt),
											.read2_address	(read2_address),
											.read2_data		(read2_data),
											
											.read3_enable	(read3_enable		&&	ok_d_read	&&	ok_stage3),
											.read3_address	(read3_address),
											.read3_data		(read3_data)		);


	//////////
	//
	// Instantiate adder
	//
	//////
		reg		[7:0]	add_v1;			// Value 1
		reg		[7:0]	add_v2;			// Value 2
		wire	[7:0]	add_result;
		reg		[1:0]	add_dst;		// Destination register

		// Will be computed on the negative edge of the clock
		add_adc_reg8 aar8(.result(add_result), .v1(add_v1), .v2(add_v2), .carry(p4_carry), .dst_reg(add_dst));


	//////////
	//
	// Instantiate subtractor
	//
	//////
		reg		[7:0]	sub_v1;			// Value 1
		reg		[7:0]	sub_v2;			// Value 2
		wire	[7:0]	sub_result;
		reg		[1:0]	sub_dst;		// Destination register

		// Will be computed on the negative edge of the clock
		sub_sbb_reg8 ssr8(.result(sub_result), .v1(sub_v1), .v2(sub_v2), .borrow(p4_carry), .dst_reg(sub_dst));


	//////////
	//
	// Initial setup
	// Set clock and halt instruction processing
	//
	//////
		initial begin
			bootup;
		end


	//////////
	//
	// Clock signal
	//
	//////
		always begin
			#1 clk = ~clk;
		end
	
	
	//////////
	//
	// 1: i-fetch
	//
	//////
		always @(posedge clk) begin
			i_fetch;	// Retrieve the instruction bytes
		end
	
	
	//////////
	//
	// 2: i-decode
	//
	//////
		always @(posedge clk) begin
			i_decode;	// Decode the loaded instruction
		end
	
	
	//////////
	//
	// 3: d-read
	//
	//////
		always @(posedge clk) begin
			if (i_halt == 0 && ok_d_read && ok_pipe_stage3) begin
				d_read;
			end
		end
	
	
	//////////
	//
	// 4: Process
	//
	//////
		always @(posedge clk) begin
			if (i_halt == 0 && ok_i_process && ok_pipe_stage4) begin
				i_process;
			end
		end
	
	
	//////////
	//
	// 5: d-write
	//
	//////
		always @(posedge clk) begin
			if (i_halt == 0 && ok_d_write) begin
				d_write;
			end
		end
	
	
	//////////
	//
	// Push between pipe stages
	//
	//////
		always @(negedge clk) begin
			if (i_halt == 0) begin
				push_pipe_data;
			end
		end
	
	
	//////////
	//
	// Read the next instruction
	//
	//////
		task i_fetch;
			begin
				// Read the next instruction unless we're halted
				if (i_halt == 0 && ok_i_fetch) begin
					// Raise the read signal and wait a tick
					read_clk		= 1'b1;
					read1_enable	= 1'b1;
					read2_enable	= 1'b1;
					p1_ip_address	= ip;			// Indicate the ip address
					read1_address	= ip;			// Read from the IP address
					read2_address	= ip + 1;		// Read from the IP address + 1
					ok_i_decode		= 1'b1;			// Indicate it's okay to decode next clock
			
				end else begin
					ok_i_decode		= 1'b0;			// We weren't able to fetch an instruction, so hold off
				end
			end
		endtask
	
	
	//////////
	//
	// Decode fetched instruction
	//
	//////
		task i_decode;
			begin
				if (i_halt == 0 && ok_i_decode && ok_pipe_stage2) begin
					if (read1_data[7:5] == 3'b000) begin
						// mov  reg8,[address]
						// 2 opcode bytes
						// 000.00.000:00000000 = 000.reg8_dst.address_src
						p2_reg_dst				<= p2_i_data1[4:3];
						p2_read_address[10:8]	<= p2_i_data1[2:0];
						p2_read_address[7:0]	<= p2_i_data2[7:0];
						p2_read_ok				<= 1'b1;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `MOV_FROM_MEM8;
			
					end else if (read1_data[7:5] == 3'b001) begin
						// mov  reg8,reg8
						// 1 opcode byte
						// 001.x.00.00 = 001.x.reg8_dst.reg8_src
						p2_reg_dst				<= p2_i_data1[3:2];
						p2_reg_src				<= p2_i_data1[1:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `MOV;
			  
					end else if (read1_data[7:4] == 4'b0100) begin
						// add  reg8,reg8
						// 1 opcode byte
						// 0100.00.00 = 010.x.reg8_dst.reg8_src
						p2_reg_dst				<= p2_i_data1[3:2];
						p2_reg_src				<= p2_i_data1[1:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `ADD;
			  
					end else if (read1_data[7:4] == 4'b0110) begin
						// adc  reg8,reg8
						// 1 opcode byte
						// 0110.00.00 = 011.x.reg8_dst.reg8_src
						p2_reg_dst				<= p2_i_data1[3:2];
						p2_reg_src				<= p2_i_data1[1:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `ADC;
			  
					end else if (read1_data[7:4] == 4'b0101) begin
						// sub  reg8,reg8
						// 1 opcode byte
						// 0101.00.00 = 010.x.reg8_dst.reg8_src
						p2_reg_dst				<= p2_i_data1[3:2];
						p2_reg_src				<= p2_i_data1[1:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `SUB;
			  
					end else if (read1_data[7:4] == 4'b0111) begin
						// sbb  reg8,reg8
						// 1 opcode byte
						// 0111.00.00 = 011.x.reg8_dst.reg8_src
						p2_reg_dst				<= p2_i_data1[3:2];
						p2_reg_src				<= p2_i_data1[1:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `SBB;
			  
					end else if (read1_data[7:5] == 3'b100) begin
						// mov  [address],reg8
						// 2 opcode bytes
						// 100.00.000:00000000 = 100.reg8_src.address_dst
						p2_reg_src				<= p2_i_data1[4:3];
						write_address[10:8]		<= p2_i_data1[2:0];
						write_address[7:0]		<= p2_i_data2[7:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b1;
						p2_process_op[3:0]		<= `MOV_TO_MEM8;
			  
					end else if (read1_data[7:5] == 3'b101) begin
						// cmp  reg8,reg8
						// 1 opcode byte
						// 101.x.00.00 = 101.x.reg8_dst.reg8_src
						p2_reg_dst				<= p2_i_data1[3:2];
						p2_reg_src				<= p2_i_data1[1:0];
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_process_op[3:0]		<= `CMP;
			  
					end else if (read1_data[7:5] == 3'b110) begin
						// jz   +/- 1KB
						// 2 opcode bytes
						// 110.xx.s.00:00000000 = 110.xx.sign.delta
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_ip_sign[0]			<= p2_i_data1[2:2];
						p2_ip_delta[9:8][0]		<= p2_i_data1[1:0];
						p2_ip_delta[7:0][0]		<= p2_i_data2[7:0];
						p2_process_op[3:0]		<= `JZ;
			  
					end else /*if (read1_data[7:5] == 3'b111)*/ begin
						// jmp  +/- 1KB
						// 2 opcode bytes
						// 111.xx.s.00:00000000 = 111.xx.sign.delta
						p2_read_ok				<= 1'b0;
						ok_d_write				<= 1'b0;
						p2_ip_sign[0]			<= p2_i_data1[2:2];
						p2_ip_delta[9:8][0]		<= p2_i_data1[1:0];
						p2_ip_delta[7:0][0]		<= p2_i_data2[7:0];
						p2_process_op[3:0]		<= `JMP;
					end
			
				end else begin
					ok_d_read = 1'b0;		// Lower the flag, we weren't able to decode
				end
			end
		endtask
	
	
	//////////
	//
	// Read data for the instruction
	//
	//////
		task d_read;
			begin
				// This stage happens in the i_d_data() ram object
			end
		endtask
	
	
	//////////
	//
	// Process the instruction
	//
	//////
		task i_process;
			begin
				if (i_halt == 0 && ok_i_process && ok_pipe_stage4) begin
					// ok_d_read is set in i_decode based on the instruction encoding
					if (p4_process_op == `MOV_FROM_MEM8) begin
						mov_from_mem8;
					
					end else if (p4_process_op == `MOV) begin
						// The p4_reg_src contents need moved into the p4_reg_dst
						mov_reg8_to_reg8;
					
					end else if (p4_process_op == `ADD) begin
						// The p4_reg_src contents need added into the p4_reg_dst
						p4_carry = 1'b0;
						add_adc_reg8_to_reg8;
					
					end else if (p4_process_op == `ADC) begin
						// The p4_reg_src contents need added-with-carry into the p4_reg_dst
						p4_carry = flags[`CARRY:`CARRY];
						add_adc_reg8_to_reg8;
					
					end else if (p4_process_op == `SUB) begin
						// The p4_reg_src contents need subtracted from the p4_reg_dst
						p4_carry = 1'b0;
						sub_sbb_reg8_to_reg8;
					
					end else if (p4_process_op == `SBB) begin
						// The p4_reg_src contents need subtracted from the p4_reg_dst
						p4_carry = flags[`CARRY:`CARRY];
						sub_sbb_reg8_to_reg8;
					
					end else if (p4_process_op == `MOV_TO_MEM8) begin
						// The p4_reg_src contents need moved into the write address
						// And if an upcoming read from that address is in the pipe, it needs updated as well
						mov_to_mem8;
					
					end else if (p4_process_op == `CMP) begin
						// The p4_reg_dst(left) contents need compared to the p4_reg_src(right)
						cmp_reg8_to_reg8;
					
					end else if (p4_process_op == `JZ) begin
						// We need to alter the instruction pointer if zero
						if (flags[`CARRY:`CARRY] == 1'b1) begin
							ok_i_fetch		= 1'b0;
							ok_i_decode		= 1'b0;
							ok_d_read		= 1'b0;
							ok_i_process	= 1'b0;
							if (p4_ip_sign == 1'b1) begin
								// Jumping negative
								ip = p3_ip_address - p4_ip_delta;
							end else begin
								// Jumping positive
								ip = p3_ip_address + p4_ip_delta;
							end
						end
					
					end else if (p4_process_op == `JMP) begin
						// We need to alter the instruction pointer unconditionally
						ok_i_fetch		= 1'b0;
						ok_i_decode		= 1'b0;
						ok_d_read		= 1'b0;
						ok_i_process	= 1'b0;
						if (p4_ip_sign == 1'b1) begin
							// Jumping negative
							ip = p3_ip_address - p4_ip_delta;
						end else begin
							// Jumping positive
							ip = p3_ip_address + p4_ip_delta;
						end
					end
				end
			end
		endtask
	
	
	//////////
	//
	// Write the data back out to main memory
	//
	//////
		task d_write;
			begin
				// This stage happens in the i_d_data() ram object
			end
		endtask
	
	
	//////////
	//
	// Move data from mem8 into the destination reg8
	//
	//////
		task mov_from_mem8;
			begin
				// The loaded data from stage 3 needs to be moved into the destination
				if (p4_reg_dst == `R1) begin
					r1 = p4_data;
				
				end else if (p4_reg_dst == `R2) begin
					r2 = p4_data;
				
				end else if (p4_reg_dst == `R3) begin
					r3 = p4_data;
				
				end else /*if (p4_reg_dst == `R4)*/ begin
					r4 = p4_data;
				end
			end
		endtask
	
	
	//////////
	//
	// Move data from reg8 to reg8
	//
	//////
		task mov_reg8_to_reg8;
			begin
				if (p4_reg_dst == `R1) begin
					/*if (p4_reg_src == `R1) begin
						// nop
						r1 = r1;
					end else*/ if (p4_reg_src == `R2) begin
						r1 = r2;
					end else if (p4_reg_src == `R3) begin
						r1 = r3;
					end /*else if (p4_reg_src == `R4)*/ begin
						r1 = r4;
					end
				
				end else if (p4_reg_dst == `R2) begin
					if (p4_reg_src == `R1) begin
						r2 = r1;
					end /*else if (p4_reg_src == `R2) begin
						// nop
						r2 = r2;
					end*/ else if (p4_reg_src == `R3) begin
						r2 = r3;
					end /*else if (p4_reg_src == `R4)*/ begin
						r2 = r4;
					end
				
				end else if (p4_reg_dst == `R3) begin
					if (p4_reg_src == `R1) begin
						r3 = r1;
					end else if (p4_reg_src == `R2) begin
						r3 = r2;
					end /*else if (p4_reg_src == `R3) begin
						// nop
						r3 = r3;
					end*/ /*else if (p4_reg_src == `R4)*/ begin
						r3 = r4;
					end
				
				end else /*if (p4_reg_dst == `R4)*/ begin
					if (p4_reg_src == `R1) begin
						r4 = r1;
					end else if (p4_reg_src == `R2) begin
						r4 = r2;
					end else if (p4_reg_src == `R3) begin
						r4 = r3;
					end /*else if (p4_reg_src == `R4) begin
						// nop
						r4 = r4;
					end*/
				end
			end
		endtask
	
	
	//////////
	//
	// ADD or ADC reg8 to reg8
	//
	//////
		task add_adc_reg8_to_reg8;
			begin
				add_dst = p4_reg_dst;
				if (p4_reg_dst == `R1) begin
					add_v1 = r1;
				end else if (p4_reg_dst == `R2) begin
					add_v1 = r2;
				end else if (p4_reg_dst == `R3) begin
					add_v1 = r3;
				end else /*if (p4_reg_dst == `R4)*/ begin
					add_v1 = r4;
				end
				
				if (p4_reg_src == `R1) begin
					add_v2 = r1;
				end else if (p4_reg_src == `R2) begin
					add_v2 = r2;
				end else if (p4_reg_src == `R3) begin
					add_v2 = r3;
				end /*else if (p4_reg_src == `R4)*/ begin
					add_v2 = r4;
				end
			end
		endtask
	
	
	//////////
	//
	// SUB or SBB reg8 to reg8
	//
	//////
		task sub_sbb_reg8_to_reg8;
			// Setup parameters
			begin
				sub_dst = p4_reg_dst;
				if (p4_reg_dst == `R1) begin
					sub_v1 = r1;
				end else if (p4_reg_dst == `R2) begin
					sub_v1 = r2;
				end else if (p4_reg_dst == `R3) begin
					sub_v1 = r3;
				end else /*if (p4_reg_dst == `R4)*/ begin
					sub_v1 = r4;
				end
				
				if (p4_reg_src == `R1) begin
					sub_v2 = r1;
				end else if (p4_reg_src == `R2) begin
					sub_v2 = r2;
				end else if (p4_reg_src == `R3) begin
					sub_v2 = r3;
				end /*else if (p4_reg_src == `R4)*/ begin
					sub_v2 = r4;
				end
			end
		endtask
	
	
	//////////
	//
	// Move data to mem8 from the source reg8
	//
	//////
		task mov_to_mem8;
			begin
				// The register needs to be moved back out to main memory
				if (p4_reg_dst == `R1) begin
					p4_result = r1;
				
				end else if (p4_reg_dst == `R2) begin
					p4_result = r2;
				
				end else if (p4_reg_dst == `R3) begin
					p4_result = r3;
				
				end else /*if (p4_reg_dst == `R4)*/ begin
					p4_result = r4;
				end
			end
		endtask
	

	//////////
	//
	// Compare reg8 to reg8
	//
	//////
		task cmp_reg8_to_reg8;
			begin
				if (p4_reg_dst == `R1) begin
					if (p4_reg_src == `R1) begin
						flags[`ZERO:`ZERO] = 1'b1;
					end else if (p4_reg_src == `R2) begin
						flags[`ZERO:`ZERO] = ~(r1 == r2);
					end else if (p4_reg_src == `R3) begin
						flags[`ZERO:`ZERO] = ~(r1 == r3);
					end /*else if (p4_reg_src == `R4)*/ begin
						flags[`ZERO:`ZERO] = ~(r1 == r4);
					end
				
				end else if (p4_reg_dst == `R2) begin
					if (p4_reg_src == `R1) begin
						flags[`ZERO:`ZERO] = ~(r2 == r1);
					end else if (p4_reg_src == `R2) begin
						flags[`ZERO:`ZERO] = 1'b1;
					end else if (p4_reg_src == `R3) begin
						flags[`ZERO:`ZERO] = ~(r2 == r3);
					end /*else if (p4_reg_src == `R4)*/ begin
						flags[`ZERO:`ZERO] = ~(r2 == r4);
					end
				
				end else if (p4_reg_dst == `R3) begin
					if (p4_reg_src == `R1) begin
						flags[`ZERO:`ZERO] = ~(r3 == r1);
					end else if (p4_reg_src == `R2) begin
						flags[`ZERO:`ZERO] = ~(r3 == r2);
					end else if (p4_reg_src == `R3) begin
						flags[`ZERO:`ZERO] = 1'b1;
					end /*else if (p4_reg_src == `R4)*/ begin
						flags[`ZERO:`ZERO] = ~(r3 == r4);
					end
				
				end else /*if (p4_reg_dst == `R4)*/ begin
					if (p4_reg_src == `R1) begin
						flags[`ZERO:`ZERO] = ~(r4 == r1);
					end else if (p4_reg_src == `R2) begin
						flags[`ZERO:`ZERO] = ~(r4 == r2);
					end else if (p4_reg_src == `R3) begin
						flags[`ZERO:`ZERO] = ~(r4 == r3);
					end else if (p4_reg_src == `R4) begin
						flags[`ZERO:`ZERO] = 1'b1;
					end
				end
			end
		endtask
	
	
	//////////
	//
	// Transfer data between clocks for pipe stages
	//
	//////
		task push_pipe_data;
			begin
				
				//////////
				// If we have d-read memory in flight that's from our
				// write address, we need to update the value
				//////
					if (read3_address == p4_write_address) begin
						p3_data = p4_result;
					end
				
				
				//////////
				// Stage 4 to stage 5
				//////
					p5_write_address	= p4_write_address;
					p5_result			= p4_result;
				
				
				//////////
				// Stage 3 to stage 4
				//////
					p4_reg_src			= p3_reg_src;
					p4_reg_dst			= p3_reg_dst;
					p4_data				= p3_data;
					p4_write_address	= p3_write_address;
					p4_ip_sign			= p3_ip_sign;
					p4_ip_delta			= p3_ip_delta;
					p4_ip_address		= p3_ip_address;
					p4_process_op		= p3_process_op;
				
				
				//////////
				// Stage 2 to stage 3
				//////
					p3_reg_src			= p2_reg_src;
					p3_reg_dst			= p2_reg_dst;
					p3_write_address	= p2_write_address;
					p3_ip_sign			= p2_ip_sign;
					p3_ip_delta			= p2_ip_delta;
					p3_ip_address		= p2_ip_address;
					p3_process_op		= p2_process_op;
					read3_enable		= p2_read_ok;
					read3_address		= p2_read_address;
				
				
				//////////
				// Stage 1 to stage 2
				//////
					p2_ip_address		= p1_ip_address;
					p2_i_data1			= read1_data;
					p2_i_data2			= read2_data;
				
				
				//////////
				// Indicate which pipe entries are valid
				//////
					if (pipe_valid == `STAGE0) begin
						pipe_valid		= `STAGE1;
						ok_pipe_stage2	= 1'b0;
						ok_pipe_stage3	= 1'b0;
						ok_pipe_stage4	= 1'b0;
						
					end else if (pipe_valid == `STAGE1) begin
						pipe_valid		= `STAGE2;
						ok_pipe_stage2	= 1'b1;
						ok_pipe_stage3	= 1'b0;
						ok_pipe_stage4	= 1'b0;
					
					end else if (pipe_valid == `STAGE2) begin
						pipe_valid		= `STAGE3;
						ok_pipe_stage3	= 1'b1;
						ok_pipe_stage4	= 1'b0;
						
					end else if (pipe_valid == `STAGE3) begin
						pipe_valid		= `STAGE4;
						ok_pipe_stage4	= 1'b1;
					end
			end
		endtask

	
	//////////
	//
	// Bootup
	//
	//////
		task bootup;
			begin
				// Initialize clk
				clk				= 1'b0;			// Clock is initially low
	    
				// Halt all instruction processing until we're done loading
				i_halt			= 1'b1;			// Halt is true
				pipe_valid		= `STAGE1;		// No valid stages except i-fetch
	      
				// Initialize ok values
				ok_i_fetch		= 1'b0;			// Okay to i-fetch:		is false
				ok_i_decode		= 1'b0;			// Okay to i-decode:	is false
				ok_d_read		= 1'b0;			// Okay to d-read:		is false
				ok_i_process	= 1'b0;			// Okay to i-process:	is false
				ok_d_write		= 1'b0;			// Okay to d-write:		is false
	    
				// Initialize flags and registers
				flags			= 2'b0;			// 0=zero? 1=carry?
				r1				= 8'b0;			// 8-bit R1 general purpose register, set to 0
				r2				= 8'b0;			// 8-bit R1 general purpose register, set to 0
				r3				= 8'b0;			// 8-bit R1 general purpose register, set to 0
				r4				= 8'b0;			// 8-bit R1 general purpose register, set to 0
				ip				= 11'b0;		// 11-bit RI instruction pointer begins at 0
	    
				// Populate RAM
			end
		endtask

endmodule




//////////
//
// RAM with 1 write port and 3 read ports
//
//////
  module ram_1_3(	write_clk,
					write_address,
					write_data,
					write_enable,
					
					read_clk,
					read1_enable,
					read1_address,
					read1_data,
					
					read2_enable,
					read2_address,
					read2_data,
					
					read3_enable,
					read3_address,
					read3_data		);
	
	
	//////////
	// Memory sizing parameters
	//////													// By default:
	  parameter		WIDTH_DATA				= 8;			// 8-bit data
	  parameter		WIDTH_ADDRESS			= 11;			// 11-bit address
	  parameter		SIZE_RAM				= 2048;			// 2 KB buffer
	
	
	//////////
	// Physical storage
	//////
		reg		[WIDTH_DATA - 1:0]			memory[SIZE_RAM - 1:0];


	//////////
	// One write port
	//////
		input								write_clk;
		input								write_enable;
		input	[WIDTH_ADDRESS - 1:0]		write_address;
		input	[WIDTH_DATA - 1:0]			write_data;


	//////////
	// Three read ports
	//////
		input								read_clk;
		input								read1_enable;
		input	[WIDTH_ADDRESS - 1:0]		read1_address;
		output	[WIDTH_DATA - 1:0]			read1_data;
		reg		[WIDTH_DATA - 1:0]			read1_data;

		input								read2_enable;
		input	[WIDTH_ADDRESS - 1:0]		read2_address;
		output	[WIDTH_DATA - 1:0]			read2_data;
		reg		[WIDTH_DATA - 1:0]			read2_data;

		input								read3_enable;
		input	[WIDTH_ADDRESS - 1:0]		read3_address;
		output	[WIDTH_DATA - 1:0]			read3_data;
		reg		[WIDTH_DATA - 1:0]			read3_data;


    //////////
    // Write data to memory
    //////
		always @(negedge write_clk) begin
			if (write_enable) begin
				oppie1.write_enable		= 1'b0;						// Lower write-flag
				memory[write_address]	<= write_data;				// Receive the data
			end
		end


    //////////
    // Read data from memory
    //////
		always @(negedge read_clk) begin
			if (read1_enable) begin
				oppie1.read1_enable		<= 1'b0;					// Lower read-flag #!
				read1_data				<= memory[read1_address];	// Pipe the #1 data
			end
			if (read2_enable) begin
				oppie1.read2_enable		<= 1'b0;					// Lower read-flag #2
				read2_data				<= memory[read2_address];	// Pipe the #2 data
			end
			if (read3_enable) begin
				oppie1.read3_enable		<= 1'b0;					// Lower read-flag #3
				read3_data				<= memory[read3_address];	// Pipe the #3 data
			end
		end
  endmodule




//////////
//
// 8-bit adder with carry
//
//////
	module add_adc_reg8(	result,
							v1,
							v2,
							carry,
							dst_reg		);
		
		//////////
		// Two 8-bit inputs, and a carry
		//////
			output	[7:0]		result;		// Computed result
			input	[7:0]		v1;			// Value 1
			input	[7:0]		v2;			// Value 2
			input				carry;
			input	[1:0]		dst_reg;	// Destination register
		

		//////////
		// Compute the 8-bit sum with carry, and store the result
		//////
			always @(negedge oppie1.clk) begin
				// Compute
				
				// Store
				if (dst_reg == `R1) begin
					oppie1.r1 = result;
				end else if (dst_reg == `R2) begin
					oppie1.r2 = result;
				end else if (dst_reg == `R3) begin
					oppie1.r3 = result;
				end else /*if (dst_reg == `R4)*/ begin
					oppie1.r4 = result;
				end
			end
	endmodule




//////////
//
// 8-bit subtract with borrow
//
//////
	module sub_sbb_reg8(	result,
							v1,
							v2,
							borrow,
							dst_reg		);
		
		//////////
		// Two 8-bit inputs, and a borrow
		//////
			output	[7:0]		result;		// Computed result
			input	[7:0]		v1;			// Value 1
			input	[7:0]		v2;			// Value 2
			input				borrow;
			input	[1:0]		dst_reg;	// Destination register
		

		//////////
		// Compute the 8-bit subtraction with borrow
		//////
			always @(negedge oppie1.clk) begin
				// Compue
				
				// Store
				if (dst_reg == `R1) begin
					oppie1.r1 = result;
				end else if (dst_reg == `R2) begin
					oppie1.r2 = result;
				end else if (dst_reg == `R3) begin
					oppie1.r3 = result;
				end else /*if (dst_reg == `R4)*/ begin
					oppie1.r4 = result;
				end
			end
	endmodule
