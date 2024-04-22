/*
	There're different ways to check, if a file may exist or not.
	In contrast to OOP languages, like C++, Java, C#, ... in C
	there's no exception handling available or a smart and save way.

	You could either use a condition check, a signal handling or any else,
	however, what happens, when the file exists, but you don't have the
	access right to use it? Or what happens, if the file is corrupted?
	Or what happens, if a path instead is given? ...

	This code is supposed to use in C only.
	In C++ it may have a different behavior!

	This source code has been built and ran under Linux Mint 21.1.
	It could also work on any other Linux system or macOS.
*/

#include <stdio.h>
#include <stdlib.h>

/*	for example 1	*/
#include <signal.h>
#include <string.h>

/*	for example 2	*/
#include <unistd.h>

/*	for example 3	*/
#include <sys/stat.h>

#define	EXISTING		"File does exist."
#define	MISSING			"File does not exist."
#define	FILE_TO_CHECK	"test.dat"					/*	file to test to	*/

//	-------------------
//	example 1
//	-------------------
void handler_function(int signum) {
	/*
		attention:
			If the user has no access rights to that file or the file
			has no read flag or it's corrupted or else,
			a SIGSEGV is also going to raise!
	*/
	fprintf(stderr, "gotten signal: %d <=> %s\n", signum, strsignal(signum));
	puts(MISSING);
	exit(EXIT_FAILURE);
}

void check_if_file_exists_01(void) {
	/*	attempt #1: using a signal handling for "Segmentation fault (core dumped)"	*/

	signal(SIGSEGV, handler_function);

	/*	fopen may return an allocated pointer or NULL, but it could also raise SIGSEGV	*/
	FILE *f = fopen(FILE_TO_CHECK, "r");

	/*
		usually, you would use this condition check,
		but it's not often a 100% save way
	*/
	// if (f == NULL) {
	// 	perror("fopen()");
	// 	exit(EXIT_FAILURE);
	// }

	/*	fclose expects a valid FILE pointer to use => must not be NULL, otherwise SIGSEGV raises	*/
	fclose(f);
	puts(EXISTING);
}
//	-------------------

//	-------------------
//	example 2
//	-------------------
void check_if_file_exists_02(void) {
	/*	attempt #2: using the access function (UNIX/Linux only; perhaps also possible for macOS)	*/

	/*
		int access(const char *__name, int __type);
		returns 0 on success,
		-1 on error => errno is set
	*/

	if (access(FILE_TO_CHECK, F_OK) < 0) {
		puts(MISSING);
	} else {
		puts(EXISTING);
	}
}
//	-------------------

//	-------------------
//	example 3
//	-------------------
void check_if_file_exists_03(void) {
	/*	attempt	#3:	using stat function	*/

	struct stat buffer;

	/*
		int stat(const char *__restrict__ __file, struct stat* __restrict__ __buf);
		returns 0 on success,
		-1 on error => errno is set

		If you omit __buf and replaces it with a NULL argument in case you won't use struct stat,
		a warning of "non-null expectation failed" appears. So make sure to use a struct stat,
		even you don't need that in any case.
	*/

	if (stat(FILE_TO_CHECK, &buffer) < 0) {
		puts(MISSING);
	} else {
		puts(EXISTING);
	}
}
//	-------------------

int main(void) {
	// check_if_file_exists_01();
	// check_if_file_exists_02();
	// check_if_file_exists_03();

	return EXIT_SUCCESS;
}