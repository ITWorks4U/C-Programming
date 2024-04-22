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

/*	available for Windows only	*/
#include <io.h>

/*	the known flags must be defined	*/
#define	F_OK	0
#define X_OK	1
#define W_OK	2
#define R_OK	4

#define	EXISTING		"File does exist."
#define	MISSING			"File does not exist."
#define	FILE_TO_CHECK	"test.dat"

//	-------------------
//	using system layer method for Windows
//	-------------------
int main(void) {
	/*	similar to access() in Linux the flags can be combined with a BIT-OR	*/

	if (_access(FILE_TO_CHECK, F_OK | R_OK) != 0) {
		puts(MISSING);
	} else {
		puts(EXISTING);
	}

	return EXIT_SUCCESS;
}
//	-------------------