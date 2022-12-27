/*
	writing content to a file;
	can also be used for C++,
	but it's recommended not
	to do this in C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	/*
		FILE *fopen(const char *__restrict__ __filename, const char *__restrict__ __modes);

		opens a stream to a file, whereas the given mode(s) defines,
		how to open the file

		on success, a pointer to FILE returns,
		on fail, NULL returns and errno (for reason) is set
	*/

	FILE *source = fopen("reading.c", "r");

	if (source == NULL) {							//	common way for C,
													//	not recommended for C++
		perror("fopen()");
		return EXIT_FAILURE;
	}

	/*
		recommended: use a buffer to hold an amount of
		characters to read instead of reading
		each single character by character
	*/
	#define		MAX_CHARS		100
	char buffer[MAX_CHARS];
	memset(buffer, '\0', sizeof(buffer));

	while ((fgets(buffer, MAX_CHARS, source)) != NULL) {
		printf("%s\n", buffer);
	}

	/*
		int fclose(FILE* __stream);

		on success, 0 returns
		on fail, -1 returns and errno is set
	*/
	fclose(source);

	return EXIT_SUCCESS;
}