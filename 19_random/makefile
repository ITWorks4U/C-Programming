all:			randArchive.a
				gcc -g -Wall -o random.run randArchive.a
				./random.run

randArchive.a:	random.o randomRunner.o
				ar -rc randArchive.a randomRunner.o random.o
				rm *.o

random.o:		random.c random.h
				gcc -c random.c

randomRunner.o:	randomRunner.c random.h
				gcc -c randomRunner.c

clean:
				rm random.run
