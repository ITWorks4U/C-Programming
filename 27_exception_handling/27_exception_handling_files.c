#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>																							//	allows use to use the global
																											//	variable errno for error handling

/*
	Trying to read a file, whereas this is inaccessable,
	not existing, we don't have access to the file, ...
	causes, that source is NULL. Now we take a deeper
	look, how is that possible to handle.
*/

int main(void) {
	FILE *source = fopen("not found or not access to a file or else...", "r");

	if (source == NULL) {
		// printf("%d <=> %s\n", errno, strerror(errno));													//	allows us to print
																											//	the current error
																											//	number followed by
																											//	the error message

		switch(errno) {																						//	can also be used here
			case ENOENT:																					//	in case of the file wasn't found
				perror("file error");
				break;
			case EFAULT:																					//	no more free memory here
				perror("memory error");
				break;
			case EACCES:																					//	attempt to open a file without
				perror("access error");																		//	permissions
				break;
			case EMFILE:																					//	too much open files
				perror("too much open files");
				break;
			default:																						//	any other error here
				perror("any error");
				break;
		}

		return EXIT_FAILURE;																				//	errno can also be used here
	}

	//	normal workflow here...
	fclose(source);

	return EXIT_SUCCESS;
}