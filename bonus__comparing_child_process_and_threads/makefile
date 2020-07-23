all:				forkTest threadTest

forkTest:			forkTest.c forkTest.h definition.h
					gcc -g -Wall -o forkTester.run forkTest.c forkTest.h definition.h

threadTest:			threadTest.c threadTest.h
					gcc -g -Wall -o threadTest.run threadTest.c threadTest.h definition.h -lpthread

clean:
					rm *.run
