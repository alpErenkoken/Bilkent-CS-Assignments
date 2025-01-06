`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 13.12.2024 13:47:25
// Design Name: 
// Module Name: MouseControl
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

module MouseControl #(parameter MAX_X = 639, parameter MAX_Y = 479) (
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output reg [9:0] mouseX,
    output reg [9:0] mouseY,
    output reg mouseLeftButton,
    output reg mouseRightButton
    );
    
    `define clamped_plus(coord, minus, mag, max) \
        minus ? ((coord < mag) ? 0 : (coord - mag)) \
              : ((coord + mag > max) ? max : (coord + mag))
    
    
    reg [5:0] packet_bits;
    reg [43:0] packet;
    reg [1:0] ps2_clk_history;
    wire signed [8:0] xDelta, yDelta;
    wire [9:0] xDeltaMag, yDeltaMag;
    wire xDeltaSign, yDeltaSign;
    wire xOverflow, yOverflow;
    assign xDelta = { packet[38], packet[24], packet[25], packet[26], packet[27], packet[28], packet[29], packet[30], packet[31] };
    assign yDelta = { packet[37], packet[13], packet[14], packet[15], packet[16], packet[17], packet[18], packet[19], packet[20] };
    assign { xOverflow, yOverflow } = packet[36:35];
    
    assign xDeltaSign = xDelta < 0;
    assign yDeltaSign = yDelta > 0;
    assign xDeltaMag = xDelta < 0 ? (-xDelta) : xDelta;
    assign yDeltaMag = yDelta < 0 ? (-yDelta) : yDelta;
    
    initial begin
        ps2_clk_history <= 2'b11;
    end
    
    always @(posedge clk) begin
        if (rst) begin
            packet_bits <= 0;
            packet <= 0;
            ps2_clk_history <= 2'b11;
          
            mouseX <= MAX_X / 2;
            mouseY <= MAX_Y / 2;
            ps2_clk_history <= 2'b11;
          
            if (ps2_clk_history == 2'b10) begin
              
                packet <= { packet[42:0], ps2_data };
                packet_bits <= packet_bits + 1;
            end
            else if (packet_bits == 44) begin
     
                mouseLeftButton <= packet[42];
                mouseRightButton <= packet[41];
               
                mouseX <= `clamped_plus(mouseX, xDeltaSign, xDeltaMag, MAX_X);
                mouseY <= `clamped_plus(mouseY, yDeltaSign, yDeltaMag, MAX_Y);
 
                packet <= 0;
                packet_bits <= 0;
            end
        end
    end
    
endmodule
