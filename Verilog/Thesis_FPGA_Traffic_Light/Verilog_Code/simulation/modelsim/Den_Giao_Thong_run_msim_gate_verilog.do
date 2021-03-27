transcript on
if {[file exists gate_work]} {
	vdel -lib gate_work -all
}
vlib gate_work
vmap work gate_work

vlog -vlog01compat -work work +incdir+. {Den_Giao_Thong.vo}

vlog -vlog01compat -work work +incdir+D:/Work_Place/Practice_space/Practice_SP/Verilog/Thesis_FPGA_Traffic_Light/Verilog_Code {D:/Work_Place/Practice_space/Practice_SP/Verilog/Thesis_FPGA_Traffic_Light/Verilog_Code/tb_traffic_light.v}

vsim -t 1ps +transport_int_delays +transport_path_delays -L cycloneii_ver -L gate_work -L work -voptargs="+acc" tb_traffic_light

add wave *
view structure
view signals
run -all
