/*
	Handling arguments for C/C++.
	In contrast to other programming languaes
	the number of arguments to handle are different.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {															//	char *argv[] is also able to use
	//	argc	:=	argument counter
	//	argv	:=	argument vector

	for(int i = 0; i < argc; i++) {
		printf("argument %d: %s\n", i, argv[i]);
	}

	//	The first argument is always the name of the
	//	application. Surprised?

	return EXIT_SUCCESS;
}