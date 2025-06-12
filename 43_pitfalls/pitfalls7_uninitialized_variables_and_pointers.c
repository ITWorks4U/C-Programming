/*	In modern languages an uninitialized variable / object gets it's default
*	value. Either on runtime or on compiling. In C (and also mostly in C++)
*	this doesn't happen. Depending on the OS, you're working on, the behavior
*	can also be different.
*/

#include <stdio.h>
#include <stdlib.h>
#define	BUFFER	100

/*	In a C structure no member can be initialized, just defined,
*	therefore on runtime these members have a different value.
*/
struct Person {
	/*	any integer value => seems "OK"	*/
	int id;

	/*	C-string with a fixed length of 100 bytes and contains
	*	random stuff => "seems "OK"
	*/
	char first_name[BUFFER];

	/*	"dynamically" C-string with an undefined content and also
	*	an undefined length => "critical";
	*
	*	usually, every pointer has a fixed size
	*	depending on the bit technology
	*
	*	64 bit => 8 bytes
	*	32 bit => 4 bytes
	*	16 bit => 2 bytes
	*	8 bit => 1 byte
	*/
	char *last_name;

	/*	an array of C-strings with an unknown number of elements,
	*	where each element holds a C-string with a fixed length
	*	of 100 bytes => "holy moly"
	*/
	char *email_addresses[BUFFER];

	/*	similar above, but a C-string with an undefined and unknown
	*	number of bytes to store => "pray to god"
	*/
	char **anything;
};

int main(void) {
	/*	What will happen if you try to run the application?	*/
	struct Person p;

	printf(" ID: %d\n first name: %s\n last name: %s\n", p.id, p.first_name, p.last_name);

	for (size_t i = 0; i < (sizeof(p.email_addresses) / sizeof(p.email_addresses[0])); i++) {
		printf("email-address %lu: %s\n", i, p.email_addresses[i]);
	}

	printf("anything...: (%p) %s\n", p.anything, *p.anything);

	return EXIT_FAILURE;
}
