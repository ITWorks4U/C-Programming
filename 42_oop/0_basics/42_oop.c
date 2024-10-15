/*
	OOP and C? Does this work? Well, yes, but actually maybe.
	C is not designed for OOP, however, you can do a tiny step into it.

	Fun fact: Objective-C is the result of Smalltalk with C.
*/

#include <stdlib.h>
#include "42_oop.h"

/*
	The header file contains the definition, this source
	file contains the declaration. In this file it's required
	to declare your structure to work with.
*/
struct Coordinate {
	int x;
	int y;
};

/*	"constructor"	*/
struct Coordinate *coord_create(int x, int y) {
	struct Coordinate *__new = (struct Coordinate *) calloc(1, sizeof(struct Coordinate));
	__new->x = x;
	__new->y = y;

	return __new;
}

/*	"destructor"	*/
void coord_destroy(struct Coordinate *self) {
	free(self);
}

/*	"getX()"	*/
int location_x(struct Coordinate *self) {
	/*
		To avoid an undefined reference it's a good advice
		to check the structure against NULL.
	*/

	if (self != NULL) {
		return self->x;
	}

	return UNDEFINED_REFERENCE;
}

/*	"getY()"	*/
int location_y(struct Coordinate *self) {
	if (self != NULL) {
		return self->y;
	}

	return UNDEFINED_REFERENCE;
}
