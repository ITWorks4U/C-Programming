#include <stdio.h>
#include <stdlib.h>

/*
	A function prototype. Since a function call comes before it's declared,
	it's required in C/C++ to call a function correctly.
*/
void weired_function();

int main() {
	weired_function();
	return EXIT_SUCCESS;
}

/*
	On compiling (C) you'll get a "warning", because this function is unknown, but
	the compiler interprets, that thus function below might be the called function,
	whereas in C++ you'll get an error, because the function call is unknown.

	Hint: When you're calling a function, make sure to declare it as a
	function prototype before.
*/
void weired_function() {
	puts("Hi there!");
}