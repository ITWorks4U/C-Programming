/**
*	Contains different versions
*	of main functions in C.
*
*	attention:	only one of the main functions
*				below shall be active
*
*	@author			ITWorks4U
*/

/*	default main function	*/
int main() {
	puts("Default main function with a return value.");

	return EXIT_SUCCESS;
}

/*	alternate main function	*/
void main() {
	puts("Alternate main function without a return value.");
}

/*	main function with argumens	*/
int main(int argc, char **argv) {		//	alternative form: char []*argv
	int i;

	for (i = 0; i < argc; i++) {
		printf("position %d: %s\n", i, argv[i]);
	}

	return EXIT_SUCCESS;
}
