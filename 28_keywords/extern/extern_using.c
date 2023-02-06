#include <stdio.h>
#include <stdlib.h>
#include "extern.h"

/*
	Since >value< has been marked as extern
	and we also have >value< declared with
	a value, we can use it here.

	Make sure this value is available on building
	process, otherwise you'll receive an undefined
	reference.
*/

int main(void) {
	printf("value = %d\n", value);

	return EXIT_SUCCESS;
}