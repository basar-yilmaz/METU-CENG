`timescale 1ns / 1ps
module SelectionOfAvatar(
    input [1:0] mode,
    input [5:0] userID,
    input [1:0] candidate, 
    input CLK,
    output reg [1:0] ballotBoxId = 0,
    output reg [5:0] numberOfRegisteredVoters = 0,
    output reg [5:0] numberOfVotesWinner = 0,
    output reg [1:0] WinnerId = 0,
    output reg AlreadyRegistered = 0,
    output reg AlreadyVoted = 0,
    output reg NotRegistered = 0,
    output reg VotingHasNotStarted = 0,
    output reg RegistrationHasEnded = 0
    );

    // internal variables and registers
    reg [1:0] candidates[0:63]; // candidate choice of each voter
    reg registered[0:3][0:15]; // register array for tracking registration
    reg voted[0:3][0:15]; // register array for tracking voting
    reg [5:0] vote_count[0:3]; // register array for counting votes per candidate
    integer i;
	 integer k;
	 integer t;
	 integer clock_counter = 0;
	 
	 initial begin
		// Initialize all array elements to '0'
	 
	  // Initialize candidates array
	  for (k = 0; k < 64; k = k + 1) begin
		 candidates[k] = 2'b0;
	  end

	  // Initialize registered array
	  for (k = 0; k < 4; k = k + 1) begin
		 for (t = 0; t < 16; t = t + 1) begin
			registered[k][t] = 1'b0;
		 end
	  end

	  // Initialize voted array
	  for (k = 0; k < 4; k = k + 1) begin
		 for (t = 0; t < 16; t = t + 1) begin
			voted[k][t] = 1'b0;
		 end
	  end

	  // Initialize vote_count array
	  for (k = 0; k < 4; k = k + 1) begin
		 vote_count[k] = 5'b0;
	  end
	end

	 

    always @(posedge CLK)
    begin
					
			VotingHasNotStarted = 0;
			NotRegistered = 0;
			RegistrationHasEnded = 0;
			AlreadyVoted = 0;
			AlreadyRegistered = 0;
	 
	 

        if (clock_counter < 100) begin
		  
				ballotBoxId = userID[5:4];
            
            if (mode == 0) begin // registration period
                                
                if (registered[ballotBoxId][userID[3:0]] == 1) begin
                    AlreadyRegistered = 1; // user has already registered
                end else begin
                    numberOfRegisteredVoters = numberOfRegisteredVoters + 1; // increment total number of registered voters
                    registered[ballotBoxId][userID[3:0]] = 1; // mark the user as registered
                end
                
            end else begin
                VotingHasNotStarted = 1; // voting has not started yet
            end
				clock_counter = clock_counter + 1;
        end 
		  
		  else if (clock_counter < 200) begin
		  
				ballotBoxId = userID[5:4];
            
            if (mode == 1) begin // voting period
                
                if (registered[ballotBoxId][userID[3:0]] == 0) begin
                    NotRegistered = 1; // user is not registered
                end 
					 
					 else if (voted[ballotBoxId][userID[3:0]] == 1) begin
                    AlreadyVoted = 1; // user has already voted
                end 
					 
					 else begin
                    candidates[($unsigned(userID[5:0]) - 1)] = candidate; // record user's candidate choice
                    vote_count[candidate] = vote_count[candidate] + 1; // increment candidate's vote count
                    voted[ballotBoxId][userID[3:0]] = 1; // mark the user as voted
                end
                
            end 
				
				else begin
                RegistrationHasEnded = 1; // registration has ended
            end  
				
				clock_counter = clock_counter + 1;
        end 
		  
		  else begin // election is over
		  
				// we've already counted votes in between 100-199 clock_count
				// now just compare them and pick the greater one.

            numberOfVotesWinner = 0;

            for (i = 0; i < 4; i = i + 1) begin
                if (vote_count[i] > numberOfVotesWinner) begin
                    numberOfVotesWinner = vote_count[i];
                    WinnerId = i;
                end
            end
				
				clock_counter = clock_counter + 1;

        end

    end

endmodule
