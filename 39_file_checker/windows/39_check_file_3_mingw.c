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

/*	available for Windows only	*/
#include <windows.h>

#define	EXISTING		"File does exist."
#define	MISSING			"File does not exist."
#define	FILE_TO_CHECK	"test.dat"

//	-------------------
//	using a user layer method for Windows
//	-------------------
int main(void) {
	/*	taken from: https://stackoverflow.com/questions/3828835/how-can-we-check-if-a-file-exists-or-not-using-win32-program	*/
	
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(FILE_TO_CHECK, &FindFileData) ;

	int found = handle != INVALID_HANDLE_VALUE;
	if(found) {
		FindClose(handle);
		puts(EXISTING);
	} else {
		puts(MISSING);
	}

	return EXIT_SUCCESS;
}
//	-------------------