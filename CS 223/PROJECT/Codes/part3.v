module part3(
    input clk_100MHz, reset,         
    input [2:0] colors,
    input isBrush,   
    input PS2Clk, PS2Data,          // PS/2 mouse interface
    output hsync, 
    output vsync,
    output [11:0] rgb       
);

    wire isVideo;
    reg [11:0] rgb_reg;                      
    wire [9:0] x, y;            

    reg [4:0] cursor_x = 10;    
    reg [4:0] cursor_y = 8;     

    wire [7:0] mouse_x, mouse_y;
    wire mouse_x_sign, mouse_y_sign;
    wire mouse_x_ov, mouse_y_ov;
    wire mouse_left_click, mouse_valid;

    wire w_25MHz;
    reg  [1:0] r_25MHz;
    always @(posedge clk_100MHz or posedge reset)
        if (reset)
            r_25MHz <= 0;
        else
            r_25MHz <= r_25MHz + 1;
    
    assign w_25MHz = (r_25MHz == 0) ? 1 : 0;

    (* ram_style = "block" *) reg [2:0] memory [0:299]; 

    // Instantiate the VGA controller
    VGA_c c(clk_100MHz, reset, isVideo, hsync, vsync, x, y);

    // Instantiate the PS/2 mouse controller
    ps2_mouse mouse_controller(
        .i_clk(clk_100MHz),
        .i_reset(reset),
        .i_PS2Data(PS2Data),
        .i_PS2Clk(PS2Clk),
        .o_x(mouse_x),
        .o_x_ov(mouse_x_ov),
        .o_x_sign(mouse_x_sign),
        .o_y(mouse_y),
        .o_y_ov(mouse_y_ov),
        .o_y_sign(mouse_y_sign),
        .o_r_click(),
        .o_l_click(mouse_left_click),
        .o_valid(mouse_valid)
    );

    integer i;

    always @(posedge clk_100MHz or posedge reset) begin
        if (reset) begin
            cursor_x <= 10;  
            cursor_y <= 8;

            for (i = 0; i < 300; i = i + 1) begin
                memory[i] <= 3'b110; // Initialize memory with white
            end
        end else if (mouse_valid) begin
            // Update cursor position with bounds check
            if (mouse_x > 2) begin
                if (mouse_x_sign && cursor_x > 0)
                    cursor_x <= cursor_x - 1;
                else if (!mouse_x_sign && cursor_x < 19)
                    cursor_x <= cursor_x + 1;
            end

            if (mouse_y > 2) begin
                if (!mouse_y_sign && cursor_y > 0)
                    cursor_y <= cursor_y - 1;    
                else if (mouse_y_sign && cursor_y < 14)
                    cursor_y <= cursor_y + 1;
            end

            // Drawing logic
            if (mouse_left_click) begin
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
                if (cursor_x >= 0 && cursor_y >= 0 && cursor_x <= 19 && cursor_y <= 14)
                    memory[cursor_y * 20 + cursor_x] <= colors[2:0];
            end
        end
    end

    reg [2:0] color;
    reg [4:0] x_part;
    reg [4:0] y_part;

    always @(*) begin
        x_part = (x >> 5) < 20 ? (x >> 5) : 19;  // Bound check for x_part
        y_part = (y >> 5) < 15 ? (y >> 5) : 14;  // Bound check for y_part

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

        if ((x_part == cursor_x && (y_part >= cursor_y - 1 && y_part <= cursor_y + 1)) || 
            (y_part == cursor_y && (x_part >= cursor_x - 1 && x_part <= cursor_x + 1)))  
            rgb_reg = 12'h000; // Cursor color
    end

    assign rgb = (isVideo) ? rgb_reg : 12'b0;

endmodule
