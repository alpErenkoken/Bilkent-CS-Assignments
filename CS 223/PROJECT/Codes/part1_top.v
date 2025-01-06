`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12.12.2024 20:21:36
// Design Name: 
// Module Name: part1_top
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


module part1_top(

    input clk_100MHz,reset,            
    input BTNU,BTND,BTNL,BTNR,           
    output hsync,vsync,
    output [11:0] rgb       
);
    
    wire isVideo;               
    wire [9:0] x, y;             
    wire p_clk;
    
  // Instantiate VGA Controller
    VGA_c c(clk_100MHz,reset,isVideo,hsync,vsync,x,y);

    // Signal Declarations
    reg [11:0] rgb_reg;          // Register for storing RGB values
   
    // Movement offsets
    reg [9:0] x_start = 0;      
    reg [9:0] y_start = 0; 
    reg [9:0] x_pos, y_pos;     // Pixel position after offset (wrapped)

    // Button press detection (one clock cycle pulse)
    reg [3:0] button_reg, button_prev;
    wire move_up, move_down, move_left, move_right;

    assign move_up    = ~button_prev[3] & button_reg[3];
    assign move_down  = ~button_prev[2] & button_reg[2];
    assign move_left  = ~button_prev[1] & button_reg[1];
    assign move_right = ~button_prev[0] & button_reg[0];

    
    always @(*) begin
        x_pos = (x + x_start) % 640;
        y_pos = (y + y_start) % 480;

        if ((x_pos / 16 + y_pos / 16) % 2 == 0)
            rgb_reg = 12'hFFF;  // White
        else
            rgb_reg = 12'h000;  // Black
    end

    // Button input handling
    always @(posedge clk_100MHz or posedge reset) begin
        if (reset) begin
            button_reg <= 4'b0000;
            button_prev <= 4'b0000;
            x_start <= 0;
            y_start <= 0;
            
        end else begin
            // Button edge detection
            button_prev <= button_reg;
            button_reg <= {BTNU, BTND, BTNL, BTNR};

            if (move_down)
                y_start <= (y_start + 5) % 480;        // Move down (wrap around)
            if (move_left)
                x_start <= (x_start + 640 - 5) % 640;  
            if (move_right)
                x_start <= (x_start + 5) % 640;  
            if (move_up)
                y_start <= (y_start + 480 - 5) % 480;  // Move up (wrap around)

        end
    end

    assign rgb = (isVideo) ? rgb_reg : 12'b0;

endmodule