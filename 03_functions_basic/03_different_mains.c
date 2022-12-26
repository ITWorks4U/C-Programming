#include <stdio.h>
#include <stdlib.h>

/*
	It makes no sense to define more than one main function. The main function represents the
	entry point of your application. You may also give the main function arguments to handle
	these input values.
*/

/*	mostly used	*/
int main() {
	return EXIT_SUCCESS;
}

/*	almost identical to function above without accepting any argument	*/
int main(void) {
	return EXIT_SUCCESS;
}

/*	used to handle n arguments for your application	*/
int main(int argc, char **argv) {
	return EXIT_SUCCESS;
}

/*	mostly used, however, you'll get a warning on compile time, because a main must be of type int	*/
void main() {
}

void main(void) {
}

void main(int argc, char *argv[]) {
}