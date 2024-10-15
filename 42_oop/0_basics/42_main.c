/*
	OOP and C? Does this work? Well, yes, but actually maybe.
	C is not designed for OOP, however, you can do a tiny step into it.

	Fun fact: Objective-C is the result of Smalltalk with C.
*/

#include <stdio.h>
#include <stdlib.h>
#include "42_oop.h"

int main(void) {
	/*
		This won't work, because it would refer to
		the definition of the structure in the header
		file. There the structure is an unknown structure.
		The compiler won't know what this structure may contain.
	*/
	// struct Coordinate _c;

	/*	you're forced to use pointers	*/
	struct Coordinate *c = coord_create(5,5);
	printf("x: %d, y: %d\n", location_x(c) , location_y(c));

	struct Coordinate *c1 = coord_create(16,91);
	printf("x: %d, y: %d\n", location_x(c1) , location_y(c1));

	/*	causes memory leak	*/
	// c1 = NULL;
	// printf("x: %d, y: %d\n", location_x(c1) , location_y(c1));

	coord_destroy(c1);
	coord_destroy(c);

	return EXIT_SUCCESS;
}