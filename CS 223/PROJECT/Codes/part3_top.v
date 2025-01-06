module part3_top (
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output [3:0] vgaRed,
    output [3:0] vgaGreen,
    output [3:0] vgaBlue,
    output hsync,
    output vsync
);

    // Parameters for screen resolution
    parameter MAX_X = 639;
    parameter MAX_Y = 479;

    // Wires for mouse control
    wire [9:0] mouseX, mouseY;
    wire mouseLeftButton, mouseRightButton;

    // Wires for VGA control
    wire [9:0] vgaX, vgaY;
    wire isVideo, p_tick;

    // Registers to synchronize mouseX and mouseY to VGA clock
    reg [9:0] cursorX, cursorY;

    // Instantiate MouseControl module
    MouseControl #(MAX_X, MAX_Y) mouse_controller (
        .clk(clk),
        .rst(rst),
        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data),
        .mouseX(mouseX),
        .mouseY(mouseY),
        .mouseLeftButton(mouseLeftButton),
        .mouseRightButton(mouseRightButton)
    );

    // Instantiate VGA controller module
    VGA_c vga_controller (
        .clk_100(clk),
        .reset(rst),
        .isVideo(isVideo),
        .hsync(hsync),
        .vsync(vsync),
        .p_tick(p_tick),
        .x(vgaX),
        .y(vgaY)
    );

    // Synchronize mouse position to VGA pixel clock
    always @(posedge p_tick or posedge rst) begin
        if (rst) begin
            cursorX <= MAX_X / 2;
            cursorY <= MAX_Y / 2;
        end else begin
            cursorX <= mouseX;
            cursorY <= mouseY;
        end
    end

    // VGA color output logic
    reg [3:0] red, green, blue;

    always @(posedge p_tick) begin
        if (isVideo) begin
            // Draw a white background
            red = 4'hF;
            green = 4'hF;
            blue = 4'hF;

            // Draw a black "+" cursor at cursorX, cursorY
            if ((vgaX == cursorX && (vgaY >= cursorY - 5 && vgaY <= cursorY + 5)) ||
                (vgaY == cursorY && (vgaX >= cursorX - 5 && vgaX <= cursorX + 5))) begin
                red = 4'h0;
                green = 4'h0;
                blue = 4'h0;
            end
        end else begin
            // Set to black outside the video area
            red = 4'h0;
            green = 4'h0;
            blue = 4'h0;
        end
    end

    // Assign colors to VGA outputs
    assign vgaRed = red;
    assign vgaGreen = green;
    assign vgaBlue = blue;

endmodule
