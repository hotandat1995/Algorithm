
/* Testbench file */

// Do chia thoi gian
`timescale 1ns/1ns

// Khai bao module test
module tb_traffic_light;

/*AUTO REG INPUT*/
// Beginning of automatic reg inputs (for undeclared instantiated-module inputs)
// Khoi tao cac thanh ghi:
reg         clk;           // To dut of Den_Giao_Thong.v
reg         rst_n;         // To dut of Den_Giao_Thong.v
// End of automatics

/*AUTOWIRE*/
// Beginning of automatic wires (for undeclared instantiated-module outputs)
//Khoi tao wires cho Duong A, B
wire [2:0]  street_a;           // From dut of Den_Giao_Thong.v
wire        street_a_pri_lamp;  // From dut of Den_Giao_Thong.v
wire [2:0]  street_b;           // From dut of Den_Giao_Thong.v
wire        street_b_pri_lamp;  // From dut of Den_Giao_Thong.v
// End of automatics

// Khoi tao module Den giao thong va truyen cac thong so chay
// dut (Device under test): Thiet bi duoc test
Den_Giao_Thong dut
(
    /*AUTOINST*/
    // Outputs
    .street_a           (street_a[2:0]),        ///< Duong A
    .street_a_pri_lamp  (street_a_pri_lamp),    ///< Den uu tien duong A
    .street_b           (street_b[2:0]),        ///< Duong B
    .street_b_pri_lamp  (street_b_pri_lamp),    ///< Den uu tien duong B
    // Inputs
    .clk                (clk),                  ///< Chan clock
    .rst_n              (rst_n)                 ///< Chan reset
);

// Khoi dong pin clock
initial begin
    clk = 0;
    forever #10 clk = !clk;     ///< 10 don vi thoi gian thi doi chieu 1 lan. VD: clk = 1, 10 ns sau clk = 0
end

// Khoi dong pin reset
initial begin
    rst_n = 0;
    #20
    rst_n = 1;
end

endmodule
