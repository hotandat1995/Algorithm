
module fsm
(
   /* AUTOARG */
   // Outputs
   street_a,
   street_a_pri_lamp,
   street_b,
   street_b_pri_lamp,
   fsm_g,
   fsm_y,
   fsm_r,
   // Inputs
   clk,
   rst_n,
   g_end,
   y_end,
   r_end
);

/* Interface */
// INPUT
input               clk;                   ///< Clock pin
input               rst_n;                 ///< Reset pin
input               g_end;                 ///< Green end pin
input               y_end;                 ///< Yellow end pin
input               r_end;                 ///< Red end pin
// Output
output reg [2:0]    street_a;              ///< Duong A
output reg [2:0]    street_b;              ///< Duong B
output wire         fsm_g;                 ///< fsm cho pin green
output wire         fsm_y;                 ///< fsm cho pin yellow
output wire         fsm_r;                 ///< fsm cho pin red
output wire         street_a_pri_lamp;     ///< Den uu tien cho Street A
output wire         street_b_pri_lamp;     ///< Den uu tien cho Street B

// Internal signals //
reg [2:0] current_state,    ///< Trang thai hien tai
          next_state;       ///< Trang thai tiep theo
reg       street_a_pl,      ///< Bien luu tam cua den uu tien Street A
          street_b_pl;      ///< Bien luu tam cua den uu tien Street B

// STATE number                                                       Street A | Street B
localparam AG_BR  = 3'd0;   ///< Khai bao bien co gia tri decimal 0 - GREEN    - RED
localparam AY_BR  = 3'd1;   ///< Khai bao bien co gia tri decimal 1 - YELLOW   - RED
localparam AR_BR1 = 3'd2;   ///< Khai bao bien co gia tri decimal 2 - RED      - RED 1
localparam AR_BG  = 3'd3;   ///< Khai bao bien co gia tri decimal 3 - RED      - GREEN
localparam AR_BY  = 3'd4;   ///< Khai bao bien co gia tri decimal 4 - RED      - YELLOW
localparam AR_BR2 = 3'd5;   ///< Khai bao bien co gia tri decimal 5 - RED      - RED 2

/**
 * Next state logic:
 * Trong truong hop current_state thoa dieu kien cua g_end, y_end, r_end thi se chuyen
 * trang thai. Nguoc lai se giu nguyen trang thai hien tai.
 */
always @ (*) begin
    case (current_state[2:0])
        AG_BR:
            begin
                if (g_end)
                    next_state[2:0] = AY_BR;
                else
                    next_state[2:0] = current_state[2:0];
            end
        AY_BR:
            begin
                if (y_end)
                    next_state[2:0] = AR_BR1;
                else
                    next_state[2:0] = current_state[2:0];
            end
        AR_BR1:
            begin
                if (r_end)
                    next_state[2:0] = AR_BG;
                else
                    next_state[2:0] = current_state[2:0];
            end
        AR_BG:
            begin
                if (g_end)
                    next_state[2:0] = AR_BY;
                else
                    next_state[2:0] = current_state[2:0];
            end
        AR_BY:
            begin
                if (y_end)
                    next_state[2:0] = AR_BR2;
                else
                    next_state[2:0] = current_state[2:0];
            end
        AR_BR2:
            begin
                if (r_end)
                    next_state[2:0] = AG_BR;
                else
                    next_state[2:0] = current_state[2:0];
            end
        default:
            next_state[2:0] = current_state[2:0];
    endcase
end

/**
 * STATE MEMORY:
 * Dung de clear gia tri trong truong hop reset thi gan current_state = AR_BR1
 * Nguoc lai thi se luu next_state vao trong current_state
 */
always @ (posedge clk)
begin
    if (~rst_n)
        current_state[2:0] <= AR_BR1;
    else
        current_state[2:0] <= next_state[2:0];
end

// Output cho Street A
always @ (*) begin
    case (current_state[2:0])
        AG_BR:
            begin
                street_a[2:0] = 3'b100;    ///< Khi trang thai AG_BR output den la GREEN-ON , YELLOW-OFF, RED-OFF
                street_a_pl   = 1'b0;      ///< Den uu tien = OFF
            end
        AY_BR:
            begin
                street_a[2:0] = 3'b010;    ///< Khi trang thai AY_BR output den la GREEN-OFF, YELLOW-ON , RED-OFF
                street_a_pl   = 1'b0;      ///< Den uu tien = OFF
            end
        default:
            begin
                street_a[2:0] = 3'b001;    ///< Khi trang thai other output den la GREEN-OFF, YELLOW-OFF, RED-ON
                street_a_pl   = 1'b1;      ///< Den uu tien = ON
            end
    endcase
end

// Output cho Street B
always @ (*) begin
    case (current_state[2:0])
        AR_BG:
            begin
                street_b[2:0] = 3'b100;    ///< Khi trang thai AG_BR output den la GREEN-ON , YELLOW-OFF, RED-OFF
                street_b_pl   = 1'b0;      ///< Den uu tien = OFF
            end
        AR_BY:
            begin
                street_b[2:0] = 3'b010;    ///< Khi trang thai AY_BR output den la GREEN-OFF, YELLOW-OFF, RED-OFF
                street_b_pl   = 1'b0;      ///< Den uu tien = OFF
            end
        default:
            begin
                street_b[2:0] = 3'b001;    ///< Khi trang thai other output den la GREEN-OFF, YELLOW-ON , RED-ON
                street_b_pl   = 1'b1;      ///< Den uu tien = ON
            end
    endcase
end

// Set output cho tin hieu FSM GREEN, YELLOW, RED
assign fsm_g = (current_state[2:0] == AG_BR)  | (current_state[2:0] == AR_BG);
assign fsm_y = (current_state[2:0] == AY_BR)  | (current_state[2:0] == AR_BY);
assign fsm_r = (current_state[2:0] == AR_BR1) | (current_state[2:0] == AR_BR2);
// Set output cho tin hieu den uu tien STREET A, B
assign street_a_pri_lamp = street_a_pl;
assign street_b_pri_lamp = street_b_pl;

endmodule
