/*
	writing content to a file;
	can also be used for C++,
	but it's recommended not
	to do this in C++
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	/*
		FILE *fopen(const char *__restrict__ __filename, const char *__restrict__ __modes);

		opens a stream to a file, whereas the given mode(s) defines,
		how to open the file

		on success, a pointer to FILE returns,
		on fail, NULL returns and errno (for reason) is set
	*/

	FILE *destination = fopen("file.txt", "w");

	if (destination == NULL) {							//	common way for C,
														//	not recommended for C++
		perror("fopen()");
		return EXIT_FAILURE;
	}

	fprintf(destination, "This number: %d will be available in that file.\n", 123);

	/*
		int fclose(FILE* __stream);

		on success, 0 returns
		on fail, -1 returns and errno is set
	*/
	fclose(destination);

	return EXIT_SUCCESS;
}