/**
*	How to read a file in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 255

int main() {
	FILE *source = fopen("textdocument.txt", "r");				//	create a source and try to load a file to source

	if (source == NULL) {										//	check, if the source file could be opened
		printf(" Source file could not be found!\n");
		return EXIT_FAILURE;
	}

	/*	reading a content character by character; very ineffective for large files	*/
//	int sign;
//	while ((sign = fgetc(source)) != EOF) {						//	EOF := end of file (equal to -1)
//		printf("%c", (char) sign);
//	}

	char BUFFER[MAX];											//	create a buffer for buffered operations
	/*	reading the content of the file as a string, but skips
	*	space and other special characters like '\n'
	*/
//	while ((fscanf(source, "%s", BUFFER) != EOF)) {
//		printf("%s", BUFFER);	
//	}

	/*	reading the same content where each space character and
	*	also each newline character will be considered; stops
	*	reading when the end of the file has been reached
	*/
	while ((fgets(BUFFER, MAX, source) != NULL)) {
		printf("%s", BUFFER);	
	}

	fclose(source);												//	closing file stream
	return EXIT_SUCCESS;
}
