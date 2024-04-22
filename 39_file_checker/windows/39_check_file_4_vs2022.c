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

	>>	Tested under Win11 Professional 64 Bit with Visual Studio 2022.	<<
*/

#include <stdio.h>
#include <stdlib.h>

/*	sample #1	*/
#include <signal.h>
#include <string.h>

/*	sample #2	*/
#include <io.h>
#define F_OK	0
#define	X_OK	1
#define	W_OK	2
#define	R_OK	4

/*	sample #3	*/
#include <Windows.h>
#define	MAX_LENGTH	9	/*	the LENGTH of characters for FILE_TO_CHECK	*/

#define	EXISTING		"File does exist."
#define	MISSING			"File does not exist."
#define	FILE_TO_CHECK	"test.dat"

//	-------------------
//	sample 1: using signal handler
//	-------------------
static void handler_function(int signnum) {
	/*	HAS NEVER BEEN TRIGGERED HERE	*/
	fprintf_s(stdout, "gotten signal: %d\n", signnum);
	puts(MISSING);
	exit(EXIT_FAILURE);
}

static void check_file_1(void) {
	/*
		In VS2022 even a signal handler is planned to use,
		your application has never been handled with the signal handling!
	*/

	signal(SIGSEGV, handler_function);
	FILE* f = NULL;

	//	deprecated under VS2022
	/*f = fopen(FILE_TO_CHECK, "r");*/

	//	this function shall be used instead
	fopen_s(&f, FILE_TO_CHECK, "r");

	//	displays the warning, that 'f' could be NULL (which is still true)
	fclose(f);

	puts(EXISTING);
}
//	-------------------

//	-------------------
//	sample 2: using access() function
//	-------------------
static void check_file_2(void) {
	//	deprecated under VS2022
	/*access(FILE_TO_CHECK, F_OK);*/

	//	works logically wrong => prints that the file "test.dat" exists, which doesn't
	/*_access_s(FILE_TO_CHECK, F_OK);*/

	if (_access(FILE_TO_CHECK, F_OK) < 0) {
		puts(MISSING);
	} else {
		puts(EXISTING);
	}
}
//	-------------------

//	-------------------
//	sample 3: using a "professional way"
//	-------------------
static void check_file_3(void) {
	wchar_t text[MAX_LENGTH];
	memset(text, '\0', MAX_LENGTH);

	//	deprecated under VS2022
	/*mbstowcs(text, FILE_TO_CHECK, strlen(FILE_TO_CHECK) + 1);*/

	//	displays the warning, that "text" might not end to 0 (null), which is true,
	//	because strlen() expects a char* and not wchar_t
	size_t length_of_text = strlen(text);

	mbstowcs_s(&length_of_text, text, strlen(FILE_TO_CHECK) + 1, FILE_TO_CHECK, MAX_LENGTH);
	LPWSTR ptr = text;

	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(ptr, &FindFileData);

	int found = handle != INVALID_HANDLE_VALUE;
	if (found) {
		FindClose(handle);
		puts(EXISTING);
	} else {
		puts(MISSING);
	}
}
//	-------------------

int main(void) {
	//check_file_1();
	//check_file_2();
	// check_file_3();

	return EXIT_SUCCESS;
}