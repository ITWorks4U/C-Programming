#include <stdio.h>
#include <stdlib.h>

//	-----------
//	Debugging a code runs easy within an IDE.
//	Without an IDE (terminal) use gdb
//	Linux:
//		gdb shall be installed by default
//		usage: gdb <application>
//	Windows:
//		use mingw to debug code outside of an IDE
//	-----------
int recursion_function(int counter) {
	if (counter >= 100) {
		return counter;
	}

	printf("counter = %d\n", counter);
	counter++;
	return recursion_function(counter);
}

int main() {
	printf("%d\n", recursion_function(0));
	return EXIT_SUCCESS;
}