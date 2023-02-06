#ifndef EXTERN_H
#define	EXTERN_H

/*
	The keyword extern allows us to define a variable,
	function, expression, ... which can be
	declared elsewhere.

	Make sure this value is available on building
	process, otherwise you'll receive an undefined
	reference.
*/
extern int value;																				//	"just" a definition here

#endif