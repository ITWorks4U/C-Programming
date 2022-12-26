#include <stdio.h>
#include <stdlib.h>

void funny_function(int array[], size_t elements) {
	for(size_t i = 0; i < elements; i++) {
		printf("element: %d\n", array[i]);
	}	
}

int main() {
	//	-----------
	//	integer array
	//	-----------
	int array[] = {1, 2, 3, -100. -687, 753, 42, 1337, 9001};						//	9 elements
	// printf("array has %ls elements\n", array);									//	unable to print array elements
	// printf("array has %lu elements\n", sizeof(array));							//	9 elements? No! There're 36 "elements".
	printf("array has %lu elements\n", sizeof(array) / sizeof(array[0]));			//	9 elements. :o)

	for(size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("array element: %d\n", array[i]);
	}

	//	-----------
	//	C-strings
	//	-----------
	char word[] = "Howdy! How're you?";
	printf("word has %lu elements\n", sizeof(word));							//	9 elements? No! There're 36 "elements".
	printf("word has %lu elements\n", sizeof(word) / sizeof(word[0]));			//	9 elements. :o)

	for(size_t i = 0; i < sizeof(word) / sizeof(word[0]); i++) {
		printf("word element: %c\n", word[i]);
	}

	//	-----------
	//	outsourcing to function
	//	-----------
	funny_function(array, sizeof(array) / sizeof(array[0]));

	return EXIT_SUCCESS;
}