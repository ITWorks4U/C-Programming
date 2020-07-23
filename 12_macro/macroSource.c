/**
*	How to use macros in C/C++.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "makroHeader.h"

int main() {
	struct SData *content = (struct SData*) malloc(sizeof(struct SData));
	if (content != NULL) {

		strncpy(content->name, " ITWorks4U", strlen(" ITWorks4U"));
		printf("%s\n", content->name);

		printf(" LENGTH = %u\n", LENGTH);

		int i;
		content->lastName[0] = ' ';
		for (i = 1; i < LENGTH; i++) {
			if (i < (LENGTH - 1)) {
				content->lastName[i] = '-';
			} else {
				content->lastName[i] = '\0';
			}
		}
		printf("%s\n", content->lastName);


		static const char wordHolder[] = " available on Youtube";
		strncpy(content->location, wordHolder, strlen(wordHolder));
		printf("%s\n", content->location);

		free(content);

		int value = 47;
		if (CHECK_NUMBER_OF_50(value)) {
			printf(" 47 is smaller than 50.\n"); 
		} else {
			printf(" 47 is not smaller than 50.\n"); 
		}

		#ifdef __MSDOS__
			printf(" Runs under MS DOS.\n");
		#elif __WIN32__
			printf(" Runs under MS Windows 32 bit system.\n");
		#elif __WIN64__
			printf(" Runs under MS Windows 64 bit system.\n");
		#elif __unix__
			printf(" Runs under UNIX/Linux system.\n");
		#else
			printf(" Runs under an unknown OS.\n");
		#endif

	}

	return EXIT_SUCCESS;
}

