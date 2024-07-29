#	contant expressions
SOURCE_C = main.c
SOURCE_CPP = main.cpp
LIBARY = libary.dll
FLAGS = -g3 -Wall
OUTPUT = application

#	hint:	with @ in front of the certain command, this won't be printed on the terminal / command line
#			$(info text) displays a normal text while your script is running
#			attention: this text will also be printed when an error appears

#	target for the C application
target_c:		main.c libary.dll
				@gcc $(FLAGS) $(SOURCE_C) $(LIBARY) -o $(OUTPUT)
				$(info App "$(OUTPUT)" built.)

#	target for the C++ application
target_cpp:		main.cpp libary.dll
				@g++ $(FLAGS) $(SOURCE_CPP) $(LIBARY) -o $(OUTPUT)
				$(info App "$(OUTPUT) built.")

#	a library, which is going to use here
#	this library contains the math functions here => your main application(s) "just"
#	import the functions from the library only
libary.dll:		math.o
				@ar cr $(LIBARY) math.o
				@rm *.o
				$(info Building library...)

#	in case of you want to see the assembly definition for C++ and C
assembly_cpp:	math.cpp math.h
				@gcc -S math.cpp -o assembly_cpp

assembly_c:		math.c math.h
				@gcc -S math.c -o assembly_c

#	object file, which is required for the library
math.o:			math.cpp math.h
				@gcc -c $(FLAGS) math.cpp

#	clean up the "mess" ;-)
clean:
				@rm $(OUTPUT) $(LIBARY)
				$(info App "$(OUTPUT)" removed.)