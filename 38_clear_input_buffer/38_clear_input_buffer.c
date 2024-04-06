/*
	Cleaning a buffer after reading from keyboard or any other input stream
	may reduce the amount of undefined behaviors.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH	30

int main(void) {
	char word1[MAX_LENGTH];
	char word2[MAX_LENGTH];
	memset(word1, '\0', MAX_LENGTH);
	memset(word2, '\0', MAX_LENGTH);

	/*
		Usually we're allowed to enter anything
		up to a certain amount of allowed characters.
		But what happens, when we exceed this limit?

		It may cause an undefined behavior or your application may crash.
	*/

	printf("Enter anything: ");
	fgets(word1, MAX_LENGTH, stdin);

	/*
		As an naive programmer, we're assuming, that the fflush() function shall work, but it doesn't.
		fflush() clears the output stream, like stdout, stderr

		int fflush(FILE *__stream);

		taken from the manual:
		-------------
		DESCRIPTION
			For output streams, fflush() forces a write of all user-space buffered data for the given output or update stream via the stream's underlying write function.
			For  input  streams  associated  with seekable files (e.g., disk files, but not pipes or terminals), fflush() discards any buffered data that has been fetched from the underlying
			file, but has not been consumed by the application.

			The open status of the stream is unaffected.
			If the stream argument is NULL, fflush() flushes all open output streams.
			For a nonlocking counterpart, see unlocked_stdio(3).

		RETURN VALUE
			Upon successful completion 0 is returned.  Otherwise, EOF is returned and errno is set to indicate the error.

		ERRORS
			EBADF  stream is not an open stream, or is not open for writing.

			The function fflush() may also fail and set errno for any of the errors specified for write(2).
		-------------
	*/
	// int a = fflush(stdin);
	// printf("a = %d\n", a);

	/*
		most efficient method for C programming:
		combine a while / infinite for loop with getchar() to discard any buffer left until the next
		occurrence of a newline character (\n); for reading an input stream "EOF" for "end of file"
		is often in use to check, if the current file has no more characters to read

		int getchar(void);

		As an alternative, int getc(FILE *__stream); MAY also work, but there's no guarantee.
	*/
	while(getchar() != '\n' || getchar() != EOF) {}

	/*	hardly used, but works, too	=> has the same effect like >>while<<	*/
	// for(;getchar() != '\n' || getchar() != EOF;) {}

	printf("again: ");
	fgets(word2, MAX_LENGTH, stdin);
	while(getchar() != '\n' || getchar() != EOF) {}

	printf("word1: %s, located on: %p\n", word1, &word1);
	printf("word2: %s\n, located on: %p\n", word2, &word2);

	return EXIT_SUCCESS;
}