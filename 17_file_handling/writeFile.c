/**
*	How to write content to a file.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *destination = NULL;							//	create a destination
	destination = fopen("aTestDocument.txt", "a+");		//	try to open the stream

	if (destination == NULL) {							//	if any error occurred
		printf(" Error by creating a file.\n");
		return EXIT_FAILURE;
	}

	/*	Writing a single character to the stream. Very ineffective,
	*	if the character is a non printable character for destination stream.
	*/
	int sign = 33;
	while (sign < 255) {
		fputc(sign, destination);
		sign++;
	}

	/*	Print a simple text to the file.	*/
	char message[] = "\n\nThis is a simple text which should be\n written to a text document.\n\n";
	fputs(message, destination);

	/*	Let's also print a system based output to the file.	*/
	fprintf(destination, " This is testing for fprintf, where the content comes from file \"%s\". This function was called on line %d.\n\n\n", __FILE__, __LINE__);

	fclose(destination);

	return EXIT_SUCCESS;
}
