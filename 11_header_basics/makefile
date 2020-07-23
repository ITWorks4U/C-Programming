program.run:	main.o algorithms.o
				gcc -g -Wall -o program.run main.o algorithms.o
				rm *.o

main.o:			main.c headerFile.h
				gcc -c main.c

algorithm.o:	algorithms.c headerFile.h
				gcc -c algorithms.c

clean:
				rm program.run
