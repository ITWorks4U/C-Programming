#include <stdio.h>
#include <stdlib.h>

/*
	In C (also in C++) you can define a function as an
	argument for an another function, e. g. in C a
	signal handling works with this mechanism.
*/

/*	functions planned as an argument	*/
int add(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

/*	function, which holds functions like above as an argument	*/
void funny_function(int (*f)(int, int)) {									//	this function requires any
																			//	function of type int with
																			//	two integer arguments
																			//	fun fact: the argument must not
																			//	have an argument name, because
																			//	it won't be compiled
	for(int i = 0; i < 10; i++) {
		printf("%d\n", (*f)(i, i-1));										//	calling this given function
	}
}

int main(void) {
	/*	calling the function(s)	*/
	puts("---------");
	funny_function(add);
	puts("---------");
	funny_function(mul);
	puts("---------");

	/*
		Unlike in C++ in C you'll get
		"just" a warning. On runtime,
		a segmentation fault appears.
	*/
	//funny_function(add(1,2));

	return EXIT_SUCCESS;
}