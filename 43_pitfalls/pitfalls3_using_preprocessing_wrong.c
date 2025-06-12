/*	Based on pitfalls 2, when you try to use preprocessing commands to run a (special) command
*	for an operating system, this can also be used in the wrong way.
*/

#include <stdio.h>
#include <stdlib.h>

/*	usually, a definition (and also a declaration) starts with:	*/
#define	TEST	0

/*	You can also use a define as:	*/
#define	TEST_2
/*	However, this preprocessing definition above does not tell you, for what this might be planned.
*	In that case you can use such commands to ensure, that an instruction / instructions can be used
*	only, if "TEST_2" is defined. No matter, if this has an expression.
*
*	But by using TEST_2 not all of the preprocessing commands below can't be used correctly.
*/

/*	Try to figure out, which one of the commands below might use this definition correctly.	*/
int main(void) {
	/*	#ifdef := if defined	*/
	#ifdef TEST
	puts("Yeah, by using #ifdef \"TEST\" is defined and can be used as well...");
	#else
	puts("Nope, #ifdef doesn't figure out, if \"TEST\" is defined or not...");
	#endif

	/*	#if TEST := if test is 0 or 1 <or> true or false ==> Works with integer only	*/
	#if TEST
	puts("Yeah, by using #if \"TEST\" is defined and can be used as well...");
	#else
	puts("Nope, #if doesn't figure out, if \"TEST\" is defined or not...");
	#endif

	/*	#if defined := like #ifdef	*/
	#if defined TEST
	puts("Yeah, by using #if defined \"TEST\" is defined and can be used as well...");
	#else
	puts("Nope, #if defined doesn't figure out, if \"TEST\" is defined or not...");
	#endif

	return EXIT_FAILURE;
}