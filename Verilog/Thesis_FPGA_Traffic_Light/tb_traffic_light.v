
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

    /* AUTO WIRE */
    // Beginning of automatic wires (for undeclared instantiated-module outputs)
    // Khoi tao wires cho Duong A, B
    wire [2:0]  street_a;           // From dut of Den_Giao_Thong.v
    wire        street_a_pri_lamp;  // From dut of Den_Giao_Thong.v
    wire [2:0]  street_b;           // From dut of Den_Giao_Thong.v
    wire        street_b_pri_lamp;  // From dut of Den_Giao_Thong.v
    // End of automatics

    // Khoi tao module Den giao thong va truyen cac thong so chay
    // dut (Device under test): Thiet bi duoc test
    Den_Giao_Thong dut
    (
        /* AUTO INST */
        // Outputs
        .street_a           (street_a[2:0]),        ///< Duong A
        .street_a_pri_lamp  (street_a_pri_lamp),    ///< Den uu tien duong A
        .street_b           (street_b[2:0]),        ///< Duong B
        .street_b_pri_lamp  (street_b_pri_lamp),    ///< Den uu tien duong B
        // Inputs
        .clk                (clk),                  ///< Chan clock
        .rst_n              (rst_n)                 ///< Chan reset
    );

    /* Define cac bien su dung trong module test */
    integer counter_data;        ///< Dung de luu gia tri mo file
    integer index;               ///< So luong lan lap lai
    parameter DURATION = 1000;   ///< Thoi gian lap tinh theo chu ki

    // Open csv-file de write data vao
    initial
    begin
        // Open file
        counter_data = $fopen("D:/Work_Place/Practice_space/Practice_SP/Verilog/Thesis_FPGA_Traffic_Light/output_file/counter_output.csv");
    end

    // Dung simulate va close file khi da du thoi gian can test
    always @(posedge clk)
    begin
        if (DURATION == index)
        begin
            $stop;                  ///< Dung simulate
            $fclose(counter_data);  ///< Close file
        end
    end

    // Khoi dong pin clock
    initial
    begin
        clk = 0;
        for (index = 0; index < DURATION; index = index + 1)
        begin
            #10             ///< Doi 10 chu ki
            clk = !clk;     ///< Dao gia tri cua clock
            /* In gia tri cua cac pin ra file counter_output.csv de kiem tra */
            $fdisplay(counter_data,"%d,%d,%d,%d,%b", index, street_a, street_a_pri_lamp, street_b, street_b_pri_lamp);
        end
    end

    // Khoi dong pin reset
    initial
    begin
        rst_n = 0;
        #20         ///< Doi sau 20 chu ki thi trigger reset 1 lan duy nhat
        rst_n = 1;
        #1          ///< Doi sau 1 chu ki thi dua chan reset ve 0
        rst_n = 0;
    end

endmodule
