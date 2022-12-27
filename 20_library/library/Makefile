#
#	makefile to create a library instead of a runtime
#
lib:					library.o
						@ar cr library.dll library.o
						@rm library.o
						$(info	library created)

library.o:				library.c library.h
						@gcc -c -Wall library.c

clean:
						rm library.dll