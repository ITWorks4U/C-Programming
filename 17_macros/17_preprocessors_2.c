#include <stdio.h>
#include <stdlib.h>

/*
	C/C++ comes with a set of defined
	macros / preprocessors, which can
	be used like:
*/

int main() {
	//	printing current file name and line number
	printf("Using file: \"%s\" on line: %d\n", __FILE__, __LINE__);

	//	check, on which OS this application runs:
	#ifdef __MSDOS__
	puts("Runs under MS DOS!");
	#elif __WIN32__ || __WIN64__
	puts("Runs under MS Windows (32 or 64 bit)!");
	#elif __unix__
	puts("Runs under UNIX/Linux!");
	#else
	puts("Runs under any other OS!");
	#endif

	return EXIT_SUCCESS;
}