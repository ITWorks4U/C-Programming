/*
	An own library, which
	can be implemented elsewhere.

	This library is for C only.
	In C++ this library shall be updated.

	This library will be available
	for Linux only. On Windows a
	library is able to create
	by using Visual Studio.

	video: https://www.youtube.com/watch?v=nZBSVb6SJaQ&list=PLwMeVY6dlAg20kre011gbHHzMl77SIi-g&index=21
*/

//	----------
//	simple implementation
//	of a periodic system
//	----------

#ifndef LIBRARY_H
#define LIBRARY_H

//	----------
//	data types
//	----------
typedef enum {
	SOLID = 0x10, LIQUID = 0x20, GAS = 0x30
} Type;

typedef enum {
	METAL = 0x40, SEMI_METAL = 0x50, NON_METAL = 0x60, NOBLE_METAL = 0x70, NOBLE_GAS = 0x80
} Classification;

typedef enum {
	NATURAL = 0x90, ARTIFICIALLY = 0x100, RADIOACTIVE = 0x110
} Notofication;

typedef struct {
	int Id;
	char name[21];
	char symbol[3];
	double melting_point;
	double boiling_point;
	Type t;
	Classification c;
	Notofication n;
} Element;

//	----------
//	functions
//	----------
void print_element(Element e);

#endif