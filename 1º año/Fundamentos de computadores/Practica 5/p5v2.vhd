----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:22:31 01/07/2021 
-- Design Name: 
-- Module Name:    p5v2 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity p5v2 is
	PORT (G0: IN STD_LOGIC;
			G1: IN STD_LOGIC;
			G2: IN STD_LOGIC;
			G3: IN STD_LOGIC;
			B0: OUT STD_LOGIC;
			B1: OUT STD_LOGIC;
			B2: OUT STD_LOGIC;
			B3: OUT STD_LOGIC);
end p5v2;

architecture Behavioral of p5v2 is

begin
	B0<=(NOT G3 AND NOT G2 AND G1 AND G0)OR(NOT G3 AND NOT G2 AND NOT G1 AND G0)OR(G3 AND NOT G2 AND NOT G1 AND NOT G0)OR(G3 AND NOT G2 AND G1 AND G0)OR(G3 AND G2 AND G1 AND NOT G0)OR(G3 AND G2 AND NOT G1 AND G0)OR(NOT G3 AND G2 AND NOT G1 AND NOT G0)OR(NOT G3 AND G2 AND G1 AND G0);
	B1<=(NOT G3 AND NOT G2 AND G1)OR(G3 AND NOT G2 AND NOT G1)OR(G3 AND G2 AND G1)OR(NOT G3 AND G2 AND NOT G1);
	B2<=(G3 AND NOT G2)OR(NOT G3 AND G2);
	B3<=G3;


end Behavioral;


