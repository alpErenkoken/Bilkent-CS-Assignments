`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12.12.2024 20:18:36
// Design Name: 
// Module Name: VGA_c
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module VGA_c(

    input clk_100,reset,        
    output isVideo,Hs,Vs,     
    output [9:0] x,y     
    
    );
    
    // * Generate 25MHz from 100MHz *******************
	reg  [1:0] Reg25MHz;
	wire Wire25MHz;
	
	always @(posedge clk_100 or posedge reset)
		if(reset)
		  Reg25MHz<=0;
		else
		  Reg25MHz <= Reg25MHz + 1;
	
	assign Wire25MHz = (Reg25MHz == 0) ? 1 : 0; // assert tick 1/4 of the time
    
  	  // Counter Registers, two each for buffering to avoid glitches
    reg [9:0] Regh_count, h_CNext;
    reg [9:0] Regv_count, v_CNext;
    
    // Output Buffers
    reg v_sync_reg, h_sync_reg;
    wire v_sync_next, h_sync_next;
    
    // Register Control
    always @(posedge clk_100 or posedge reset)
        if(reset) begin
            Regv_count <= 0;
            Regh_count <= 0;
            v_sync_reg  <= 1'b0;
            h_sync_reg  <= 1'b0;
        end
        else begin
            Regv_count <= v_CNext;
            Regh_count <= h_CNext;
            v_sync_reg  <= v_sync_next;
            h_sync_reg  <= h_sync_next;
        end
        
    //Logic for horizontal counter
    always @(posedge Wire25MHz or posedge reset)      // pixel tick
        if(reset)
            h_CNext = 0;
        else
            if(Regh_count == 799)                 // end of horizontal scan
                h_CNext = 0;
            else
                h_CNext = Regh_count + 1;         
  
    // Logic for vertical counter
    always @(posedge Wire25MHz or posedge reset)
        if(reset)
            v_CNext = 0;
        else
            if(Regh_count == 799)                 // end of horizontal scan
                if((Regv_count == 524))           // end of vertical scan
                    v_CNext = 0;
                else
                    v_CNext = Regv_count + 1;
        
    assign h_sync_next = (Regh_count >= (656) && Regh_count <= (751));
    assign v_sync_next = (Regv_count >= (513) && Regv_count <= (515));
    assign isVideo = (Regh_count < 640) && (Regv_count < 480);
            
    // Outputs
    assign Hs=h_sync_reg;
    assign Vs=v_sync_reg;
    assign x=Regh_count;
    assign y=Regv_count;
    assign pixelClk=Wire25MHz;
            
endmodule