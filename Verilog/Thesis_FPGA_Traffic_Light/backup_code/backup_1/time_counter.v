
module time_counter
(
    /*AUTOARG*/
    // Outputs
    g_end,
    y_end,
    r_end,
    // Inputs
    clk,
    rst_n,
    fsm_g,
    fsm_r,
    fsm_y
);

// Dinh nghia
parameter GREEN_TIME  = 29;     ///< Thoi gian cua den xanh
parameter YELLOW_TIME = 4;      ///< Thoi gian cua den vang
parameter RED_TIME    = 2;      ///< Thoi gian cua den do

/* Interface */
// INPUT
input       clk;
input       rst_n;
input       fsm_g;
input       fsm_r;
input       fsm_y;
// OUTPUT
output wire g_end;
output wire y_end;
output wire r_end;

// Internal signals //
reg  [7:0] clk_counter;     ///< Giu gia tri cua counter
wire clr_counter;           ///< Clear counter

// posedge: positive edge -> Canh len
always @ (posedge clk) begin
    if (~rst_n)                                         ///< Neu co reset
        clk_counter[7:0] <= 8'd0;                       ///< Gan gia tri cua counter ve 0
    else if (clr_counter)                               ///< Neu co clear counter
        clk_counter[7:0] <= 8'd0;                       ///< Gan gia tri cua counter ve 0
    else                                                ///< Truong hop con lai
        clk_counter[7:0] <= clk_counter[7:0] + 1'b1;    ///< Tang gia tri counter len 1 don vi
end

// Compare the end time (So sanh thoi gian ket thuc)
assign g_end = fsm_g & (clk_counter[7:0] == GREEN_TIME);
assign y_end = fsm_y & (clk_counter[7:0] == YELLOW_TIME);
assign r_end = fsm_r & (clk_counter[7:0] == RED_TIME);

// Clear counter trong trong truong hop 1 trong 3 tin hieu ben duoi == 1
assign clr_counter = g_end | y_end | r_end;

endmodule
