----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:26:17 01/06/2021 
-- Design Name: 
-- Module Name:    P5_Code - Behavioral 
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity P5_Code is
	PORT (G0: IN STD_LOGIC;
			G1: IN STD_LOGIC;
			G2: IN STD_LOGIC;
			G3: IN STD_LOGIC;
			P: OUT STD_LOGIC;
			S: OUT STD_LOGIC;
			T: OUT STD_LOGIC;
			C: OUT STD_LOGIC);
end P5_Code;

architecture Behavioral of P5_Code is
	signal entrada: STD_LOGIC_VECTOR(3 downto 0);
begin
	entrada<= G3 & G2 & G1 & G0;
	--Salida de de P con when...else
	P<= '1' when entrada = "0000" else
		'1' when entrada = "0001" else
		'1' when entrada = "0011" else
		'1' when entrada = "0010" 
		else '0';

	--Salida de S con with...
	with entrada select
	S<= '1' when "0110" | "0111" | "0101" | "0100",
		 '0' when others;
		 
	--Salida de T con if...else
	process(entrada)--siempre obligatorio usarlo con if..else
	begin --obligatorio ponerlo tb
	if entrada="1100" then T<='1';--si uso todo el rato if seria end if x cada if¿?
	elsif entrada="1101" then T<='1';
	elsif entrada="1111" then T<='1';
	elsif entrada="1110" then T<='1';
	else T<='0';
	end if;
	end process;
	
	--Salida de C con case
		process(entrada) --siempre obligatorio usarlo con case
		begin --obligatorio ponerlo tb
		case entrada is
		when "1010" => C <= '1';
		when "1011" => C <= '1';
		when "1001" => C <= '1';
		when "1000" => C <= '1';
		when others => C <= '0';
		
		end case;
		end process;
end Behavioral;

