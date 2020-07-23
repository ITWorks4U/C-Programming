all:		exit.o
			gcc -g -Wall -o exitExample.run exit.o
			rm exit.o

exit.o:		exit.c exit.h
			gcc -c exit.c

clean:
			rm exitExample.run
