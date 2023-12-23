#include <stdio.h>
#include <stdlib.h>

int main() {
	/*
		Remembering the first listening (01_first_program)?
		The variable b has a value of 12 bytes, whereas only 8 bytes
		shall be there.

		The function printf() returns the number of bytes for the certain
		output, however, by using formatters this also raises
		the amount of bytes, thus "a = %d\n" returns 8 bytes +
		%d (4 bytes) = 12 bytes!

		Without caring of these "small" amount of extra size, this also
		might a heavy problem on runtime anywhere.
	*/

	int a = 7654321;
	int b = printf("a = %d\n", a);																							//	contains 8 characters as expected
	printf("b = %d characters\n", b);																						//	prints 12 characters... But, why?

	return EXIT_SUCCESS;
}