`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12.12.2024 20:23:21
// Design Name: 
// Module Name: part2_top
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


module part2_top(

    input clk_100MHz,reset,         
    input BTNU,BTND,BTNL,BTNR,BTNC,            
    input [2:0] colors,
    input isBrush,   
    output hsync, 
    output vsync,
    output [11:0] rgb       
);

    wire isVideo;
    reg [11:0] rgb_reg;                      
    wire [9:0] x, y;            

    reg [4:0] cursor_x = 10;    
    reg [4:0] cursor_y = 8;     

    reg [3:0] button_reg, button_prev;
    wire move_up, move_down, move_left, move_right;
    wire w_25MHz;
    reg  [1:0] r_25MHz;
        always @(posedge clk_100MHz or posedge reset)
            if(reset)
              r_25MHz <= 0;
            else
              r_25MHz <= r_25MHz + 1;
        
    
    assign w_25MHz = (r_25MHz == 0) ? 1 : 0;

    assign move_up    = ~button_prev[3] & button_reg[3];
    assign move_down  = ~button_prev[2] & button_reg[2];
    assign move_left  = ~button_prev[1] & button_reg[1];
    assign move_right = ~button_prev[0] & button_reg[0];

    (* ram_style = "block" *) reg [2:0] memory [0:299]; 

  VGA_c c(clk_100MHz,reset,isVideo,hsync,vsync,x,y);      
  
  integer i;

    always @(posedge w_25MHz or posedge reset) begin
        if (reset) begin
            cursor_x <= 10;  
            cursor_y <= 8;
            button_reg <= 4'b0000;
            button_prev <= 4'b0000;
            

            for (i = 0; i < 300; i = i + 1) begin
                 memory[i] <= 3'b110; 
                 end
            
        end else begin
            button_prev <= button_reg;
            button_reg <= {BTNU, BTND, BTNL, BTNR};

            if (move_up && cursor_y > 0)
                cursor_y <= cursor_y - 1;
            if (move_down && cursor_y < 14)
                cursor_y <= cursor_y + 1;
            if (move_left && cursor_x > 0)
                cursor_x <= cursor_x - 1;
            if (move_right && cursor_x < 19)
                cursor_x <= cursor_x + 1;

            if (BTNC) begin
                if (isBrush) begin
                if (cursor_x > 0 && cursor_y > 0) 
                    memory[(cursor_y - 1) * 20 + (cursor_x - 1)] <= colors[2:0];
                if (cursor_x > 0) 
                    memory[cursor_y * 20 + (cursor_x - 1)] <= colors[2:0];
                if (cursor_x > 0 && cursor_y < 14) 
                    memory[(cursor_y + 1) * 20 + (cursor_x - 1)] <= colors[2:0];
                if (cursor_y > 0) 
                    memory[(cursor_y - 1) * 20 + cursor_x] <= colors[2:0];
                if (cursor_y < 14) 
                    memory[(cursor_y + 1) * 20 + cursor_x] <= colors[2:0];
                if (cursor_x < 19 && cursor_y > 0) 
                    memory[(cursor_y - 1) * 20 + (cursor_x + 1)] <= colors[2:0];
                if (cursor_x < 19) 
                    memory[cursor_y * 20 + (cursor_x + 1)] <= colors[2:0];
                if (cursor_x < 19 && cursor_y < 14) 
                    memory[(cursor_y + 1) * 20 + (cursor_x + 1)] <= colors[2:0];

                end 
                if (cursor_x>0 && cursor_y>0 && cursor_x < 19 && cursor_y < 14)
                memory[cursor_y * 20 + cursor_x] <= colors[2:0];
            end
        end
    end
    
    reg [2:0] color;
    reg [4:0] x_part;
    reg [4:0] y_part;
    
        
always @(*) begin

        x_part = x >> 5;
        y_part = y >> 5;

        color = memory[y_part * 20 + x_part];

        case (color)
            3'b000: rgb_reg = 12'hF00; // Red 
            3'b001: rgb_reg = 12'h0F0; // Green 
            3'b010: rgb_reg = 12'h00F; // Blue 
            3'b011: rgb_reg = 12'hFF0; // Yellow 
            3'b100: rgb_reg = 12'hF0F; // Magenta 
            3'b101: rgb_reg = 12'h0FF; // Cyan 
            3'b110: rgb_reg = 12'hFFF; // White
            3'b111: rgb_reg = 12'h000; // Black
            default: rgb_reg = 12'hFFF; // Default white
            
        endcase
        
        if ((x_part == cursor_x && (y_part >= cursor_y - 2 && y_part <= cursor_y + 2)) || (y_part == cursor_y && (x_part >= cursor_x - 2 && x_part <= cursor_x + 2)))  
            rgb_reg = 12'h000; 
    end
    assign rgb = (isVideo) ? rgb_reg : 12'b0;

endmodule
