A showcase for Verilog vs. Chisel vs. SimpleChisel (32-bit)
----
All designs do the same thing:
Iterating through the memory space and negating an constant to every 32-bit signed integer.
----
Each design consists of the following parts:
1. A loader that is responsible for loading data from memory
2. A storer that is responsible for storing data to memory
3. An negator that is responsible for negating constant to the data
4. [Optional] An asynchronous encryption/decryption engine if the memory space is encrypted
----
Possible Configurations:
The memory bandwidth can be 64,128,256-bit and takes multiple cycles
The negator can be a single cycle negator, or to be a 4-cycle pipelined negator, or to have/ do not have buffer


Export VERILATOR_INCLUDE={{{Verilator_install_path}/share/verilator/inlcude}