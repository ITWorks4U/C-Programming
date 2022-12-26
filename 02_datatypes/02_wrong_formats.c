#include <stdio.h>
#include <stdlib.h>

int main() {
	/*	trying to print an integer by using a different format	*/
	int a = 1517538462;																						//	1,517,538,462

	printf("a as decimal value = %d\n", a);																	//	normal formatted output for an integer
	printf("a as octal value = %o\n", a);																	//	a %O won't work
	printf("a as hexadecimal value = %X\n", a);																//	you may also %x => prints x instead of X
	printf("a as exponential value = %e\n", a);																//	won't work correctly for an integer

	printf("a as short value = %d\n", a);																	//	short uses the same format for print
	printf("a as char value = %c\n", a);																	//	%c can only display a visible character between 33 and 127!
																											//	0 - 31: system command, like \0, \n, \b, ... 32: space
	// printf("a as string value = %s\n", a);																//	causes a segmentation fault (application crashes)

	printf("a as long value = %ld\n", a);																	//	long may also hold a integer, but you may get a warning on compiling
	printf("a as unsigned int value = %u\n", a);															//	works correctly for an integer, since it's not declared as 'unsigned'

	printf("a as float value = %f\n", a);																	//	floating point numbers won't work correctly
	printf("a as double value = %lf\n", a);																	//	for an integer value

	printf("a as pointer value = %p\n", &a);																//	strictly recommended: & in front of a variable
																											//	otherwise a wrong address returns

	return EXIT_SUCCESS;
}