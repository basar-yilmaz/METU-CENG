`timescale 1ns / 1ps

module bh(input B, input H, input clk, output reg Q);

	initial begin
		Q = 1;
	end

	always @(posedge clk) begin
		if((B==0)&&(H==0)) begin
			Q <= ~Q; // complement
			end 
		else if((B==0)&&(H==1)) begin
			Q <= 1'b1; // set to 1
			end 
		else if((B==1)&&(H==0)) begin
			Q <= 1'b0; // set to 0
			end 
		else begin
			Q <= Q; // no change
		end
	end

endmodule


module ic1337(// Inputs	
              input A0,
              input A1,
              input A2,
              input clk,
              // Outputs
              output Q0,
              output Q1,
              output Z);

	// You can implement your code here
    // ...
	 
	 wire b1,h1,b2,h2;
	 
	 assign b1 = (A0 ^ ~A1) | A2;
	 assign b2 = (A0 & ~A2);
	 assign h1 = (A0 & ~A2);
	 assign h2 = (A2 & ~(~A0 | A1));
	 
	 bh ff1(b1, h1, clk, Q0);
	 bh ff2(b2, h2, clk, Q1);
	 
	 assign Z = (Q0 ^~ Q1);


endmodule