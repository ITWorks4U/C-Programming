#include <stdio.h>
#include <stdlib.h>
#include "24_csv.h"

int main() {
	if (formatted_csv_reader()) {										//	calling specified function here
		puts("Aaaaand done!");
	} else {
		puts("Oops, there was an error. D:");
	}

	return EXIT_SUCCESS;
}