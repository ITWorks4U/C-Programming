all:			logic.a
				gcc -g -Wall -o logical.run logic.a
				./logical.run

logic.a:		logic.o logicRunner.o
				ar -rc logic.a logic.o logicRunner.o
				rm *.o

logic.o:		logic.c logic.h
				gcc -c logic.c

logicRunner.o:	logicRunner.c logic.h
				gcc -c logicRunner.c

clean:
				rm logical.run
