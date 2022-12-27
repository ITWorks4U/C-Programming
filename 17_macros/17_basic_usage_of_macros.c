/*
	Macros are (very) powerful and
	very often used for C and
	mostly for C++, however,
	these offers you a bunch of
	problems, if you don't mind them.
*/

#include <stdio.h>
#include <stdlib.h>

/*	Macros are typeless! The '200' below does not often be an integer.	*/
#define		LENGTH		200

#undef		NOTHING123													//	undefinition of a non existing macro
																		//	for C/C++: no warning or error appears

void nonsense_function();

int main() {
	for(int i = 0; i < LENGTH; i++) {
		printf("%d\n", i);
	}

	nonsense_function();

	return EXIT_SUCCESS;												//	that's a macro, too :o)
}

void nonsense_function() {
	/*	What happens here?	*/
	#undef		LENGTH													//	undefine that macro
	#define		LENGTH		"ABC"										//	redefinition of "LENGTH" => C/C++: "just" a warning,
																		//	if "LENGTH" hasn't been undefined before
	printf("%s\n", LENGTH);
}