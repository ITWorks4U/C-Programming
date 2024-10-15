#include <stdlib.h>
#include "42_inheritance.h"

/*
	method 1:

	Declaring the "super class" here, which contains nothing.
	It "just" exists.
*/
struct GeometricObject{};

struct Rectangle{
	struct GeometricObject go;

	int width;
	int height;
};

struct Rectangle *rectangle_create(int width, int height) {
	struct Rectangle *_new_rect = (struct Rectangle *) calloc(1, sizeof(struct Rectangle));
	_new_rect->width = width;
	_new_rect->height = height;

	return _new_rect;
}

void rectangle_destroy(struct Rectangle *r) {
	free(r);
}

int get_width_rectangle(const struct Rectangle *r) {
	if (r != NULL) {
		return r->width;
	}

	return UNDEFINED_REFERENCE;
}

int get_height_rectangle(const struct Rectangle *r) {
	if (r != NULL) {
		return r->height;
	}

	return UNDEFINED_REFERENCE;
}

int get_area_rectangle(const struct Rectangle *r) {
	if (r != NULL) {
		return r->height * r->width;
	}

	return UNDEFINED_REFERENCE;
}

int get_circumference_rectangle(const struct Rectangle *r) {
	if (r != NULL) {
		return 2 * (r->height + r->width);
	}

	return UNDEFINED_REFERENCE;
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*
	method 2:

	Without struct GeometricObject. In that case the reference to GeometricObject
	must be used with a pointer. Guess what? Pitfalls awaits you. (:
*/
// struct Rectangle{
// 	struct GeometricObject *go;

// 	int width;
// 	int height;
// };

// struct Rectangle *rectangle_create(int width, int height) {
// 	struct Rectangle *_new_rect = (struct Rectangle *) calloc(1, sizeof(struct Rectangle));
// 	_new_rect->width = width;
// 	_new_rect->height = height;

// 	return _new_rect;
// }

// void rectangle_destroy(struct Rectangle *r) {
// 	free(r);
// }

// int get_width_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return r->width;
// 	}

// 	return UNDEFINED_REFERENCE;
// }

// int get_height_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return r->height;
// 	}

// 	return UNDEFINED_REFERENCE;
// }

// int get_area_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return r->height * r->width;
// 	}

// 	return UNDEFINED_REFERENCE;
// }

// int get_circumference_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return 2 * (r->height + r->width);
// 	}

// 	return UNDEFINED_REFERENCE;
// }

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*
	method 3:

	Your "super class" contains properties, whereas your "child class" only refers
	to your super class. In that case a static and also a dynamic reference can be used
	with different behavior(s).
*/
// struct GeometricObject{
// 	int width;
// 	int height;
// };

// struct Rectangle{
// 	/*
// 		What would be better:	A static or dynamic reference?	:o)

// 		Remember: When you're using a dynamic reference, this MUST also be
// 		freed from them memory!
// 	*/
// 	struct GeometricObject go;
// };

// struct Rectangle *rectangle_create(int width, int height) {
// 	struct Rectangle *_new_rect = (struct Rectangle *) calloc(1, sizeof(struct Rectangle));
// 	_new_rect->go.width = width;
// 	_new_rect->go.height = height;

// 	return _new_rect;
// }

// void rectangle_destroy(struct Rectangle *r) {
// 	free(r);
// }

// int get_width_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return r->go.width;
// 	}

// 	return UNDEFINED_REFERENCE;
// }

// int get_height_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return r->go.height;
// 	}

// 	return UNDEFINED_REFERENCE;
// }

// int get_area_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return r->go.height * r->go.width;
// 	}

// 	return UNDEFINED_REFERENCE;
// }

// int get_circumference_rectangle(const struct Rectangle *r) {
// 	if (r != NULL) {
// 		return 2 * (r->go.height + r->go.width);
// 	}

// 	return UNDEFINED_REFERENCE;
// }
