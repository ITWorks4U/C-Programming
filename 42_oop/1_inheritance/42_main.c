#include <stdio.h>
#include <stdlib.h>
#include "42_inheritance.h"

int main(void) {
	
	/*	usage of "child class instance"	*/
	struct Rectangle *r = rectangle_create(5,10);
	printf("width = %d, height = %d\n", get_width_rectangle(r), get_height_rectangle(r));
	printf("area = %d, circumference = %d\n", get_area_rectangle(r), get_circumference_rectangle(r));
	printf("location of *r: %p\n", r);
	rectangle_destroy(r);
	
	/*
		"polymorphic programming"
		
		Guess what? A casting to the certain object is required here to avoid
		warnings and MAYBE undefined behavior!
	*/
	struct GeometricObject *go = (struct GeometricObject *) rectangle_create(10,10);
	printf("width = %d, height = %d\n", get_width_rectangle((struct Rectangle *) go), get_height_rectangle((struct Rectangle *) go));
	printf("area = %d, circumference = %d\n", get_area_rectangle((struct Rectangle *) go), get_circumference_rectangle((struct Rectangle *) go));
	printf("location of *r: %p\n", (struct Rectangle *) go);
	rectangle_destroy((struct Rectangle *) go);

	return EXIT_SUCCESS;
}