`timescale 1ns / 1ps
module lab3_2(
			input[5:0] money,
			input CLK,
			input vm, //0:VM0, 1:VM1
			input [2:0] productID, //000:sandwich, 001:chocolate, 11x: dont care
			input sugar, //0: No sugar, 1: With Sugar
			output reg [5:0] moneyLeft,
			output reg [4:0] itemLeft,
			output reg productUnavailable,//1:show warning, 0:do not show warning
			output reg insufficientFund , //1:full, 0:not full
			output reg notExactFund , //1:full, 0:not full
			output reg invalidProduct, //1: empty, 0:not empty
			output reg sugarUnsuitable, //1: empty, 0:not empty
			output reg productReady	//1:door is open, 0:closed
	);

	// Internal State of the Module
	// (you can change this but you probably need this)
	reg [4:0] numOfSandwiches;
	reg [4:0] numOfChocolate;
	reg [4:0] numOfWaterVM1;
	reg [4:0] numOfWaterVM0;
	reg [4:0] numOfCoffee;
	reg [4:0] numOfTea;

	initial
	begin
		// You can initialize here
    	// ...
		numOfSandwiches = 5'b01010;
		numOfChocolate = 5'b01010;
		numOfWaterVM1 = 5'b01010;
		numOfWaterVM0 = 5'b00101;
		numOfCoffee = 5'b01010;
		numOfTea = 5'b01010;

		productReady = 1'b0;
		itemLeft = 5'b0;
		productUnavailable = 1'b0;
		invalidProduct = 1'b0;
		notExactFund = 1'b0;
		insufficientFund = 1'b0;
		sugarUnsuitable = 1'b0;
		
	end

	//Modify the lines below to implement your design
	always @(posedge CLK)
	begin
	
	productReady <= 1'b0;
	insufficientFund <= 1'b0;
	productUnavailable <= 1'b0;
	invalidProduct <= 1'b0;
	notExactFund <= 1'b0;
	moneyLeft <= money; 
	sugarUnsuitable <= 1'b0;

	
	if (vm == 1'b0) // VM0 selected
	begin
		case (productID)
			3'b000: // sandwich
				if (numOfSandwiches > 1'b0 && money == 6'b010100) // check availability and exact money
				begin
					numOfSandwiches = numOfSandwiches - 1'b1; // decrement num of sandwiches
					productReady <= 1'b1;
					moneyLeft <= 1'b0;
					itemLeft <= numOfSandwiches;
				end
				else if (numOfSandwiches <= 1'b0)
					begin
					productUnavailable <= 1'b1;
					productReady <= 1'b0;
					end
				else if (money != 6'b010100)
					begin
					notExactFund <= 1'b1;
					productReady <= 1'b0;
					end
			3'b001: // chocolate
				if (numOfChocolate > 1'b0 && money == 6'b001010) // check availability and exact money
				begin
					numOfChocolate = numOfChocolate - 1'b1; // decrement num of chocolates
					productReady <= 1'b1;
					itemLeft <= numOfChocolate;
					moneyLeft <= 1'b0;
				end
				else if (numOfChocolate <= 1'b0)
					begin
					productUnavailable <= 1'b1;
					productReady <= 1'b0;
					end
				else if (money != 6'b001010) begin
					notExactFund <= 1'b1;
					productReady <= 1'b0; end
			3'b010: // water
				if (numOfWaterVM0 > 1'b0 && money == 6'b000101) // check availability and exact money
				begin
					numOfWaterVM0 = numOfWaterVM0 - 1'b1; // decrement num of waters in VM0
					productReady <= 1'b1;
					itemLeft <= numOfWaterVM0;
					moneyLeft <= 1'b0;
				end
				else if (numOfWaterVM0 <= 1'b0)begin
					productUnavailable <= 1'b1;
					productReady <= 1'b0; end
				else if (money != 6'b000101)begin
					notExactFund <= 1'b1;
					productReady <= 1'b0; end
			default: // if the productID not valid for VM0 
				begin
				invalidProduct <= 1'b1;
				productReady <= 1'b0; end
		endcase // end case
		sugarUnsuitable <= 1'b1; // sugar unsuitable for all products in VM0
	end 

	else if (vm == 1'b1) // VM1 selected
	begin
		case (productID)
			3'b011: // coffee
				if (numOfCoffee > 1'b0 && money >= 6'b001100) // check availability and sufficient money
				begin sugarUnsuitable <= 1'b0;
					if (money < 6'b001100) // check if sugar selected and if enough money provided
					begin
						insufficientFund <= 1'b1;
						moneyLeft <= money; // return provided money
						productReady <= 1'b0;
					end
					else // purchase successful
					begin sugarUnsuitable <= 1'b0;
						numOfCoffee = numOfCoffee - 1'b1; // decrement num of coffees
						productReady <= 1'b1;
						itemLeft <= numOfCoffee;
						moneyLeft <= money - 6'b001100; // subtract price from provided money
					end
				end
				else if (numOfCoffee <= 1'b0) begin sugarUnsuitable <= 1'b0;
					productUnavailable <= 1'b1;
					productReady <= 1'b0; end
				else if (money < 6'b001100) begin sugarUnsuitable <= 1'b0;
					insufficientFund <= 1'b1;
					productReady <= 1'b0; end
			3'b100: // tea
				if (numOfTea > 1'b0 && money >= 6'b001000) // check availability and sufficient money
				begin
					sugarUnsuitable <= 1'b0;
		
					if (money < 6'b001000) // check if sugar selected and if enough money provided
					begin
						insufficientFund <= 1'b1;
						moneyLeft <= money; // return provided money
						productReady <= 1'b0;
					end
					else // purchase successful
					begin
						numOfTea = numOfTea - 1'b1; // decrement num of teas
						productReady <= 1'b1;
						itemLeft <= numOfTea;
						moneyLeft <= money - 6'b001000; // subtract price from provided money
					end
				end
					else if (numOfTea <= 1'b0) begin
						sugarUnsuitable <= 1'b0;
						productUnavailable <= 1'b1;
						productReady <= 1'b0; end
					else if (money < 6'b001000) begin
						sugarUnsuitable <= 1'b0;
						insufficientFund <= 1'b1;
						productReady <= 1'b0; end
				

			3'b010: // water
				if (numOfWaterVM1 > 1'b0 && money >= 6'b000101) // check availability and exact money
					begin
					if (sugar)
						begin
							sugarUnsuitable <= 1'b1; // sugar not suitable for water
							moneyLeft <= money; // return provided money
							itemLeft <= numOfWaterVM1;
						end
					else // purchase successful
						begin
							numOfWaterVM1 = numOfWaterVM1 - 5'b00001; // decrement num of waters in VM1
							productReady <= 1'b1;
							moneyLeft <= money - 6'b000101;
							itemLeft <= numOfWaterVM1;
						end
					end
				else if (numOfWaterVM1 <= 1'b0) begin
					productUnavailable <= 1'b1;
					itemLeft <= numOfWaterVM1;
					productReady <= 1'b0; end
				else if (sugar) begin
					sugarUnsuitable <= 1'b1;
					itemLeft <= numOfWaterVM1;
					productReady <= 1'b0;
				end
				else if (money < 6'b000101) begin
					insufficientFund <= 1'b1;
					itemLeft <= numOfWaterVM1;
					productReady <= 1'b0; end
				
			default: // if the productID not valid for VM1
				begin
				invalidProduct <= 1'b1;
				productReady <= 1'b0; end
			endcase 
		end 
	end 



endmodule

