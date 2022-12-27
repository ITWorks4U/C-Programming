#include <stdio.h>
#include <stdlib.h>

/*
	Enumerations are a set of integers
	from 0 to n-1, whereas each number
	represents an expression.

	An enumeration must not contain a duplicate
	expression, whereas multiple enumerations must
	also not contain at least one duplicate element.

	Every expression can also be set with a given
	start value.

	An enumeration must contain at least one element.
*/

enum Status {
	OK, DEBUG, INFO, WARNING, ERROR, NOTHING 
};

//	WARNING is already defined in Status.
//	'lt' is an acronym expression for 'LogType' 
enum LogType {
	LOG_DEBUG = 100, LOG_INFO, /*WARNING,*/ LOG_WARNING
} lt;

//	defining an own datatype by using 'typedef'
typedef enum {
	ON, OFF
}ToggleSwitch;

int main() {
	/*	accessing to enumerations	*/

	//	-----------
	//	Status
	//	-----------
	enum Status status = OK;
	printf("status = %d\n", status);										//	Surprised?

	for(enum Status s = OK; s <= NOTHING; s++) {							//	valid in C, invalid in C++
		printf("%d\n", s);
	}

	//	-----------
	//	LogType
	//	-----------
	for(lt = LOG_WARNING; lt >= LOG_DEBUG; lt--) {
		printf("%d\n", lt);
	}

	//	-----------
	//	custom data type
	//	-----------
	ToggleSwitch ts = ON;
	if (ts == ON) {
		puts("ToggleSwitch is ON!");
	} else {
		puts("ToggleSwitch is OFF!");
	}

	//	-----------
	//	Different amount of bytes? No!
	//	-----------
	//	for Windows: %llu, because sizeof there is unsigned long long
	printf("Status needs %lu bytes.\n", sizeof(enum Status));
	printf("lt (LogType) requires %lu bytes.\n", sizeof(lt));
	printf("ToggleSwitch requires %lu bytes.\n", sizeof(ToggleSwitch));

	return EXIT_SUCCESS;
}