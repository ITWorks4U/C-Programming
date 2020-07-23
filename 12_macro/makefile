program.run:	macroSource.o
				gcc -g -Wall -o program.run macroSource.o
				rm macroSource.o

macroSource.o:	macroSource.c macroHeader.h
				gcc -c macroSource.c

clean:
				rm program.run
