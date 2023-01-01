#define _GNU_SOURCE																//	required for getline() function
#include <stdio.h>
#include <string.h>
#include "24_csv.h"

bool write_to_csv() {
	FILE *destination = fopen("test.csv", "w");
	if (destination == NULL) {
		perror("fopen()");
		return false;
	}

	for(int i = 1; i < 10000; i++) {
		//	using a comma as a separator for CSV-export
		fprintf(destination, "%d: %d, %d+5: %d, %d*5 %d, %d*%d: %d\n", i, i, i, i+5, i, i*5, i, i, i*i);
	}

	fclose(destination);
	return true;
}

bool read_from_csv() {
	//	reading from a CSV-file without mind the format
	FILE *source = fopen("output.xls", "r");									//	Surprised by using a XLS file?
	if (source == NULL) {
		perror("fopen()");
		return false;
	}

	char content[BUFFER];
	memset(content, '\0', BUFFER);

	while((fgets(content, BUFFER, source)) != NULL) {
		printf("%s", content);
	}

	fclose(source);
	return true;
}

bool formatted_csv_reader() {
	//	possible way to read a CSV-file in a formatted form
	FILE *source = fopen("output.csv", "r");
	if (source == NULL) {
		perror("fopen()");
		return false;
	}

	char *line = NULL;															//	using a pointer to the current line
	size_t length = 0;

	/*
		Reading a full line from given stream. #define _GNU_SOURCE required
		on top of the source file to use the function.

		ssize_t getline(
			char **__restrict__ __lineptr,										//	current line to store the content
			size_t *__restrict__ __n,											//	address of the variable, that holds the size of the input buffer
			FILE *__restrict__ __stream											//	stream to read from
		);
	*/

	while((getline(&line, &length, source)) != -1) {
		if (line[0] == 'A') {													//	ignoring the first line ('A' is given here)
			continue;
		}

		printf("current line: %s", line);

		//	the line could be separated again by using
		//	strtok() function to handle each single element
	}

	fclose(source);
	return true;
}