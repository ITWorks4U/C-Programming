/*
	Can C also do inheritance and polymorphic?
	Well yes, but actually no.

	It might support an "inheritance" and also
	polymorphic, but it also contains pitfalls.
*/

#ifndef INHERITANCE_H
#define	INHERITANCE_H

#define	UNDEFINED_REFERENCE	0xFFFF

/*	"super class" / "interface" / "abstract class"	*/
struct GeometricObject;

/*	"child class"	*/
struct Rectangle;

/*	functions only for a rectangle	*/
struct Rectangle *rectangle_create(int width, int height);
void rectangle_destroy(struct Rectangle *r);
int get_width_rectangle(const struct Rectangle *r);
int get_height_rectangle(const struct Rectangle *r);
int get_area_rectangle(const struct Rectangle *r);
int get_circumference_rectangle(const struct Rectangle *r);

#endif