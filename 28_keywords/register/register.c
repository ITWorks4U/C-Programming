#include <stdio.h>
#include <stdlib.h>

/*
	In C the keyword 'register' sugggests to the
	compiler that the current variable should be
	stored in a CPU register, rather than into
	the memory.

	Each variable, which is successfully stored
	on a CPU register can be much faster accessed
	than on the memory, however, it depends on
	the compiler, if this variable CAN be stored
	on a CPU register or not, moreover, this
	variable can't be requested by using an
	address operator format. It will cause an error
	on compile time.

	Finally, the register is a storage class specifier.
	We can't use more than one storage class
	for a register variable, like:

	register static int number;
	register auto int number;
	register extern int number;
*/

int main(void) {
	int a = 100;
	printf("a = %d, location: %p\n", a, &a);

	register int b = 42;
	//	causes an error on compile time
	//printf("b = %d, location: %p\n", b, &b);


	return EXIT_SUCCESS;
}