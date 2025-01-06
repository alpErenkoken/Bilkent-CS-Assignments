set_property PACKAGE_PIN W5 [get_ports clk_100MHz]
set_property IOSTANDARD LVCMOS33 [get_ports clk_100MHz]


## Buttons
#set_property PACKAGE_PIN U18 [get_ports BTNC]						
#	set_property IOSTANDARD LVCMOS33 [get_ports BTNC]
#set_property PACKAGE_PIN T18 [get_ports BTNU]
#set_property IOSTANDARD LVCMOS33 [get_ports BTNU]

#set_property PACKAGE_PIN U17 [get_ports BTND]
#set_property IOSTANDARD LVCMOS33 [get_ports BTND]

#set_property PACKAGE_PIN W19 [get_ports BTNL]
#set_property IOSTANDARD LVCMOS33 [get_ports BTNL]

#set_property PACKAGE_PIN T17 [get_ports BTNR]
#set_property IOSTANDARD LVCMOS33 [get_ports BTNR]



### Switches
set_property PACKAGE_PIN V17 [get_ports {colors[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {colors[0]}]
set_property PACKAGE_PIN V16 [get_ports {colors[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {colors[1]}]
set_property PACKAGE_PIN W16 [get_ports {colors[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {colors[2]}]



set_property PACKAGE_PIN T1 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports reset]
set_property PACKAGE_PIN R2 [get_ports isBrush]
set_property IOSTANDARD LVCMOS33 [get_ports isBrush]


#VGA Connector
set_property PACKAGE_PIN G19 [get_ports {rgb[11]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[11]}]
set_property PACKAGE_PIN H19 [get_ports {rgb[10]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[10]}]
set_property PACKAGE_PIN J19 [get_ports {rgb[9]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[9]}]
set_property PACKAGE_PIN N19 [get_ports {rgb[8]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[8]}]
set_property PACKAGE_PIN N18 [get_ports {rgb[3]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[3]}]
set_property PACKAGE_PIN L18 [get_ports {rgb[2]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[2]}]
set_property PACKAGE_PIN K18 [get_ports {rgb[1]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[1]}]
set_property PACKAGE_PIN J18 [get_ports {rgb[0]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[0]}]
set_property PACKAGE_PIN J17 [get_ports {rgb[7]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[7]}]
set_property PACKAGE_PIN H17 [get_ports {rgb[6]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[6]}]
set_property PACKAGE_PIN G17 [get_ports {rgb[5]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[5]}]
set_property PACKAGE_PIN D17 [get_ports {rgb[4]}]				
	set_property IOSTANDARD LVCMOS33 [get_ports {rgb[4]}]
set_property PACKAGE_PIN P19 [get_ports hsync]						
	set_property IOSTANDARD LVCMOS33 [get_ports hsync]
set_property PACKAGE_PIN R19 [get_ports vsync]						
	set_property IOSTANDARD LVCMOS33 [get_ports vsync]
	
	##USB HID (PS/2)
set_property PACKAGE_PIN C17 [get_ports PS2Clk]						
	set_property IOSTANDARD LVCMOS33 [get_ports PS2Clk]
	set_property PULLUP true [get_ports PS2Clk]
set_property PACKAGE_PIN B17 [get_ports PS2Data]					
	set_property IOSTANDARD LVCMOS33 [get_ports PS2Data]	
	set_property PULLUP true [get_ports PS2Data]