/**
*	How to use random() in C/C++.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include "random.h"

#ifdef LINUX
	#include <unistd.h>
#elif WINDOWS
	#include <windows.h>
#endif

int main() {
	int i;
	int length = 100;

	for (i = 0; i < 10; i++) {
		printf("generated randomized word #%.2d: %s\n", i, generateRandomWord(length));
	
		#ifdef LINUX
			sleep(1);
		#elif WINDOWS
			Sleep(1000);
		#endif
	}

	return EXIT_SUCCESS;
}
