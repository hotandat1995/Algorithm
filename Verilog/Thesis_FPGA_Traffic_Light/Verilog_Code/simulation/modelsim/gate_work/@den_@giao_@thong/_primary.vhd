library verilog;
use verilog.vl_types.all;
entity Den_Giao_Thong is
    port(
        street_a        : out    vl_logic_vector(2 downto 0);
        street_a_pri_lamp: out    vl_logic;
        street_b        : out    vl_logic_vector(2 downto 0);
        street_b_pri_lamp: out    vl_logic;
        rst_n           : in     vl_logic;
        clk             : in     vl_logic
    );
end Den_Giao_Thong;
