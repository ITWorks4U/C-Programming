/*
	There're different ways to check, if a file may exist or not.
	In contrast to OOP languages, like C++, Java, C#, ... in C
	there's no exception handling available or a smart and save way.

	You could either use a condition check, a signal handling or any else,
	however, what happens, when the file exists, but you don't have the
	access right to use it? Or what happens, if the file is corrupted?
	Or what happens, if a path instead is given? ...

	In Windows the expected default behavior may differ in contrast to
	UNIX/Linux / macOS.

	>>	Tested under Win10 Professional 64 Bit with mingw gcc.	<<
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#define	EXISTING		"File does exist."
#define	MISSING			"File does not exist."
#define	FILE_TO_CHECK	"test.dat"

//	-------------------
//	use signal handling
//	-------------------
void handler_function(int signum) {
	fprintf(stderr, "gotten signal: %d \n", signum);
	puts(MISSING);
	exit(EXIT_FAILURE);
}

int main(void) {
	signal(SIGSEGV, handler_function);

	/*
		On Windows the behavior may be different.
		The expected result shall be a SIGSEGV, however,
		no signal has been triggered, thus it assumes that
		a non existing file may exists anyway.
	*/

	FILE *f = fopen(FILE_TO_CHECK, "r");

	/*	do something here	*/
	fclose(f);
	puts(EXISTING);

	return EXIT_SUCCESS;
}
//	-------------------