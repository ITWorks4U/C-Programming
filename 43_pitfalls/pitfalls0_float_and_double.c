/*	assuming, that float and double are identical
*
*	In every known programming language the behavior of using
*	floating data types are different rather than their
*	expectation.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float data = 0.1;
	printf("data = %f\n", data);

	/*	Why will data still not be 0.1?
	*
	*	In higher languages, C might be here a "high language", too,
	*	two types of floating data types exists:	float (single), double
	*
	*	In other languages, e. g.: Python, only one type of floating data
	*	exists, however, even there this pitfall exists, too.
	*
	*	By default a double data type is in use, however, comparing float and
	*	double to assume, that these are identical, causes a logical error on
	*	runtime.
	*
	*	To detect and solve that issue, use "F" as a literal expression behind
	*	your floating data type. Instead of "data == 0.1" use "data == 0.1F".
	*
	*/

	if (data == 0.1) {
		puts("Yeah, data is 0.1 as expected. :)");
	} else {
		puts("Wait, what...?");
	}

	return EXIT_FAILURE;
}