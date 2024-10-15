/*
	OOP and C? Does this work? Well, yes, but actually maybe.
	C is not designed for OOP, however, you can do a tiny step into it.

	Fun fact: Objective-C is the result of Smalltalk with C.
*/

#ifndef OOP_H
#define OOP_H

/*	our "indicator" for a NULL reference	*/
#define	UNDEFINED_REFERENCE	0xFFFF

/*
	forward definition

	Usually in your header or source file this structure is
	defined and declared. The header just has the definition,
	so it shall be impossible to create an instance directly.
*/
struct Coordinate;

/*	function prototypes	*/
struct Coordinate *coord_create(int x, int y);								/*	"new"			*/
void coord_destroy(struct Coordinate *self);								/*	"delete"		*/
int location_x(struct Coordinate *self);									/*	"getX()"		*/
int location_y(struct Coordinate *self);									/*	"getY()"		*/

#endif
