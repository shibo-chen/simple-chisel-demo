# A showcase for Verilog vs. Chisel vs. SimpleChisel

This showcase compares same designs in three different languages to demonstrate the value of [SimpleChisel](https://github.com/shibo-chen/simple-chisel-demo.git). 

## Menu

- [General Introduction](#general-introduction)
    - [Structure](#structure)
    - [Inteface](#interface)
    - [Basic Components](#basic-components)
- [Configurations](#configurations)
    - [Naming Convention](#naming-convention)
    - [Graphs](#graphs)
- [Try it out](#try-it-out)
    - [Run it](#run-it)
    - [Tests](#tests)

## General Introduction
All designs do the same thing: Negating signed integers to their 2's complement.

### Structure
Different designs in different languages are in different directories: Verilog, Chisel, or SimpleChisel. 
### Interface

### Basic Components

## Configurations

### Naming Convention

### Graphs

## Try it out

### Run it

### Tests
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