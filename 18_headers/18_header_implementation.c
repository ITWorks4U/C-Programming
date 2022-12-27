#include <stdio.h>
#include <stdlib.h>
#include "18_header.h"							//	importing this header file

/*
	Often used: in header files only definition(s) exist(s),
	whereas in source file(s) the definition(s) are
	implemented with logic.
*/

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;								//	What happens for b = 0?		:o)
}

int modulo(int a, int b) {
	return a % b;
}