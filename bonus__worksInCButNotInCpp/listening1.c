/*
 *	Try to call a function before it's declaration/definition.
 *	In C it may compile, but it won't work in C++.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	function();				//	call the function whithout a function prototype

	return EXIT_SUCCESS;
}

void function() {
	puts(" It works!");
}
