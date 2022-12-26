/*
	basic functionality of functions in C
	every function has: [modifier] <data type> <function name> ([arguments: <datatype> <name>, <datatype> <name>, ...]) {}

	[] := optional
	<> := required
*/

#include <stdio.h>
#include <stdlib.h>

/*	numeric data types always a value of the type	*/
float function1() {
	return 1234.5678F;
}

/*	data function without a return value; on compiling (C/C++) you'll get a warning only	*/
short function2() {}

/*	void never requires a return type, but you may given them one, if you like...*/
void function3() {}
void function4() {
	puts("Any text!");
	return;																							//	a void function hardly needs a return statement
}

/*	...unless you're using pointers :P	*/
void* what_is_this() {																				//	will be handled later
	return NULL;
}

int main() {
	printf("%f\n", function1());																	//	1234.5678 returns
	printf("%d\n", function2());																	//	What will be printed here?
	function3();																					//	for function3() and function4() it won't
	function4();																					//	cooperate with the printf() function
	printf("%p\n", what_is_this());																	//	prints the address of the pointer, if given

	return EXIT_SUCCESS;
}