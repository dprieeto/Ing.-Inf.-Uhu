--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   00:28:49 01/07/2021
-- Design Name:   
-- Module Name:   C:/Users/rdsbl/Desktop/P5/p5v1/p5v1_test.vhd
-- Project Name:  p5v1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: P5_Code
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_ARITH.ALL;
USE ieee.std_logic_UNSIGNED.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY p5v1_test IS
END p5v1_test;
 
ARCHITECTURE behavior OF p5v1_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT P5_Code
    PORT(
         G0 : IN  std_logic;
         G1 : IN  std_logic;
         G2 : IN  std_logic;
         G3 : IN  std_logic;
         P : OUT  std_logic;
         S : OUT  std_logic;
         T : OUT  std_logic;
         C : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal G0 : std_logic := '0';
   signal G1 : std_logic := '0';
   signal G2 : std_logic := '0';
   signal G3 : std_logic := '0';

 	--Outputs
   signal P : std_logic;
   signal S : std_logic;
   signal T : std_logic;
   signal C : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
	signal entrada:std_logic_vector(3 downto 0);
	signal entrada_int: integer range 0 to 15;
 
 
BEGIN
 
	entrada<= G3&G2&G1&G0;
	entrada_int<= CONV_INTEGER(entrada);
	-- Instantiate the Unit Under Test (UUT)
   
	uut: P5_Code PORT MAP (
          G0 => G0,
          G1 => G1,
          G2 => G2,
          G3 => G3,
          P => P,
          S => S,
          T => T,
          C => C
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
     -- hold reset state for 100 ns.
      wait for 100 ns;	

		G3 <= '0';G2 <= '0';G1 <= '0';G0 <= '0';
		Wait for 10 ms;
		G3 <= '0';G2 <= '0';G1 <= '0';G0 <= '1';
		Wait for 10 ms;
		G3 <= '0';G2 <= '0';G1 <= '1';G0 <= '1';
		Wait for 10 ms;
		G3 <= '0';G2 <= '0';G1 <= '1';G0 <= '0';
		Wait for 10 ms;--3
		G3 <= '0';G2 <= '1';G1 <= '1';G0 <= '0';
		Wait for 10 ms;--4
		G3 <= '0';G2 <= '1';G1 <= '1';G0 <= '1';
		Wait for 10 ms;--5
		G3 <= '0';G2 <= '1';G1 <= '0';G0 <= '1';
		Wait for 10 ms;--6
		G3 <= '0';G2 <= '1';G1 <= '0';G0 <= '0';
		Wait for 10 ms;--7
		G3 <= '1';G2 <= '1';G1 <= '0';G0 <= '0';
		Wait for 10 ms;--8
		G3 <= '1';G2 <= '1';G1 <= '0';G0 <= '1';
		Wait for 10 ms;--9
		G3 <= '1';G2 <= '1';G1 <= '1';G0 <= '1';
		Wait for 10 ms;--10
		G3 <= '1';G2 <= '1';G1 <= '1';G0 <= '0';
		Wait for 10 ms;--11
		G3 <= '1';G2 <= '0';G1 <= '1';G0 <= '0';
		Wait for 10 ms;--12
		G3 <= '1';G2 <= '0';G1 <= '1';G0 <= '1';
		Wait for 10 ms;--13
		G3 <= '1';G2 <= '0';G1 <= '0';G0 <= '1';
		Wait for 10 ms;--14
		G3 <= '1';G2 <= '0';G1 <= '0';G0 <= '0';
		Wait for 10 ms;--15

      wait;
   end process;

END;
