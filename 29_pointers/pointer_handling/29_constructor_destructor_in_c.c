#include <stdio.h>
#include <stdlib.h>

/*
	In C there's no constructor or destructor like in C++.
	This "way" >>may<< be used, however, this also causes
	an undefined behavior.
*/

void init_pointers(int *nullPtr);
void destroy_pointers(int *ptr);

//	"constructor" => What happens, if your "nullPtr" is NOT null
//	or you're using NULL instead?
void init_pointers(int *nullPtr) {
	nullPtr = (int *) malloc(sizeof(int));

	if (nullPtr == NULL) {
		puts("Something was wrong... ¯\\_(ツ)_/¯");
	} else {
		size_t length = (sizeof(nullPtr) / sizeof(nullPtr[0]));

		for (size_t i = 0; i < length; i++) {
			nullPtr[i] = (i * i);
			printf("position %d, field value : %d\n", (i+1), nullPtr[i]);
		}
	}
}

//	"destructor" => Remember, this assigned pointer >>always<<
//	have a size of 8 bytes!
void destroy_pointers(int *ptr) {
	if (ptr != NULL) {
		free(ptr);
	}
}

int main() {
	int *ptrToUse = NULL;
	init_pointers(ptrToUse);
	destroy_pointers(ptrToUse);

	return EXIT_SUCCESS;
}