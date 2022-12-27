/*
	unions are rarely used, because
	the different members of a union
	always changes their value on access
	modifications

	an union requires less space, because the space
	will be determined on the largest member

	In C:
		-	an union contains members only
		-	every member is unable to initialize inside of the union
	In C++:
		-	may initialize up to one member
		-	may contain functions, constructors, ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	unions may contain nothing
union EmptyUnion {};

union MyUnion {
	char sign;
	int index;
	long identification;
	float percent;
	int another_index;
	char word[20];
	//...
};

int main() {
	union EmptyUnion eu;

	//	in C: 0 bytes, in C++: 1 byte!
	printf("amount of bytes for \"eu\": %lu\n", sizeof(eu));

	//	accessing to members
	union MyUnion mu;
	mu.sign = 'A';
	mu.index = 100;
	mu.identification = 123L;
	mu.percent = 0.76;
	mu.another_index = 700;
	memset(mu.word, (int) 'F', 10);										//	last accessing modifies the previous members

	printf("amount of bytes for \"mu\": %lu\n", sizeof(mu));

	//	Surprised?
	printf(
		"%c, %d, %ld, %f, %d, %s\n",
		mu.sign, mu.index, mu.identification, mu.percent, mu.another_index, mu.word
	);

	return EXIT_SUCCESS;
}