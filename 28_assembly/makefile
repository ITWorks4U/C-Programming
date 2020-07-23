#compiling assembly1.c by default
task_01:			assembly1.o
					gcc -g -Wall -o assembly_01.run assembly1.o
					rm assembly1.o

assembly1.o:		assembly1.c
					gcc -c assembly1.c

#compiling assembly2.c by using flags -S, -O, -fverbose-asm, where:
#-S := create assembly source file
#-O := remove optimizing
#-fverbose-asm := forces to add useful commands for assembly file as comments
task_02:			assembly2.o
					gcc -g -Wall -o assembly_02.run assembly2.o
					rm assembly2.o

assembly2.o:		assembly2.c
					gcc -c assembly2.c

task_02_S:			assembly2.c
					gcc -S -o asm_src.s assembly2.c

task_02_S_Comments:	assembly2.c
					gcc -S -fverbose-asm -o assembly_lot_of_content.s assembly2.c

task_02_SO:			assembly2.c
					gcc -S -O -o asm_src_no_optimized.s assembly2.c

#comiling assemby3.c by using an instruction which is defined in an assembly source file
task_03:			assembly3.o add.S
					gcc -g -Wall -o assembly_03.run assembly3.o add.S
					rm assembly3.o

assembly3.o:		assembly3.c assembly3.h
					gcc -c assembly3.c

#clean up
clean:
					rm *.run
