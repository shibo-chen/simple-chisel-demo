# Given no targets, 'make' will default to building 'simv', the simulated version
# of the pipeline

# make          <- compile (and run) simv if needed

# As shortcuts, any of the following will build if necessary and then run the
# specified target

# make sim      <- runs simv (after compiling simv if needed)
# make dve      <- runs DVE interactively (after compiling it if needed)
#                                

# make clean    <- remove files created during compilations (but not synthesis)
# make nuke     <- remove all files created during compilation and synthesis
#
# synthesis command not included in this Makefile
#

INCLUDE = -I obj_dir -I${VERILATOR_INCLUDE}
LINK_FILES = obj_dir/VDatapath_STMP__ALL.a obj_dir/VDatapath_STUP__ALL.a obj_dir/VDatapath_STME__ALL.a obj_dir/VDatapath_PTMP__ALL.a obj_dir/VDatapath_PTUP__ALL.a\
			 obj_dir/VDatapath_PTME__ALL.a obj_dir/VDatapath_PDUP__ALL.a obj_dir/VDatapath_PDMP__ALL.a obj_dir/VDatapath_PDME__ALL.a
all:  Datapath_STMP Datapath_STUP Datapath_STME Datapath_PTMP Datapath_PTUP Datapath_PTME Datapath_PDUP Datapath_PDMP Datapath_PDME
	g++ $(INCLUDE) $(wildcard testbench/*.cpp) $(wildcard testbench/util/*.cpp) $(VERILATOR_INCLUDE)/verilated.cpp  $(LINK_FILES) -o test
	./test -V
.PHONY: all

Datapath_STMP: Datapath_STMP.sv negator/SingleCycleTightlyCoupledNegator.sv
	verilator -cc -Wall Datapath_STMP.sv
	cd obj_dir; make -f VDatapath_STMP.mk; cd ..

Datapath_STUP: Datapath_STUP.sv negator/SingleCycleTightlyCoupledNegator.sv
	verilator -cc -Wall Datapath_STUP.sv
	cd obj_dir; make -f VDatapath_STUP.mk; cd ..

Datapath_STME:  Datapath_STME.sv negator/SingleCycleTightlyCoupledNegator.sv Encryp-Decryp-Simulator/SimulatedAESDecryptEngin.sv Encryp-Decryp-Simulator/SimulatedAESEncryptEngin.sv
	verilator -cc -Wall Datapath_STME.sv
	cd obj_dir; make -f VDatapath_STME.mk; cd ..

Datapath_PTMP: Datapath_PTMP.sv negator/PipelinedTightlyCoupledNegator.sv
	verilator -cc -Wall Datapath_PTMP.sv
	cd obj_dir; make -f VDatapath_PTMP.mk; cd ..

Datapath_PTUP: Datapath_PTUP.sv negator/PipelinedTightlyCoupledNegator.sv
	verilator -cc -Wall Datapath_PTUP.sv
	cd obj_dir; make -f VDatapath_PTUP.mk; cd ..

Datapath_PTME:  Datapath_PTME.sv negator/PipelinedTightlyCoupledNegator.sv Encryp-Decryp-Simulator/SimulatedAESDecryptEngin.sv Encryp-Decryp-Simulator/SimulatedAESEncryptEngin.sv
	verilator -cc -Wall Datapath_PTME.sv
	cd obj_dir; make -f VDatapath_PTME.mk; cd ..

Datapath_PDMP: Datapath_PDMP.sv negator/PipelinedDecoupledNegator.sv
	verilator -cc -Wall Datapath_PDMP.sv
	cd obj_dir; make -f VDatapath_PDMP.mk; cd ..

Datapath_PDUP: Datapath_PDUP.sv negator/PipelinedDecoupledNegator.sv
	verilator -cc -Wall Datapath_PDUP.sv
	cd obj_dir; make -f VDatapath_PDUP.mk; cd ..

Datapath_PDME:  Datapath_PDME.sv negator/PipelinedDecoupledNegator.sv Encryp-Decryp-Simulator/SimulatedAESDecryptEngin.sv Encryp-Decryp-Simulator/SimulatedAESEncryptEngin.sv
	verilator -cc -Wall Datapath_PDME.sv
	cd obj_dir; make -f VDatapath_PDME.mk; cd ..


clean: obj_dir test
	rm -rf obj_dir
	rm test
