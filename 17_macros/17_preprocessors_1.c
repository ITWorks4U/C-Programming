#include <stdio.h>
#include <stdlib.h>

/*
	preprocessors are similar to macros and may
	control your application workflow
*/

#define		COMMAND

int main() {
	/*
		check, if COMMAND exists (a number is required, otherwise an error exists)
		for 0: condition check is false
		any number: condition check is true
	*/
	#if COMMAND 0
		puts("COMMAND is defined.");
	#endif

	//	check, if COMMAND is defined
	#ifdef COMMAND
		puts("COMMAND is defined.");
	#endif

	//	check, if COMMAND is undefined
	#ifndef COMMAND
		puts("COMMAND is not defined.");
	#endif

	#ifndef ABC
		puts("ABC is not defined yet...");
	#endif

	return EXIT_SUCCESS;
}