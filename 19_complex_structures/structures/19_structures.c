/*
	structs are often used, because
	these fixes the disadvantages of a union
	
	a structure often has a larger amount of bytes,
	because every member requires it's own free space

	In C:
		-	a structure contains members only
		-	every member is unable to initialize inside of the struct
	In C++:
		-	may initialize up to one member
		-	may contain functions, constructors, ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	structs may contain nothing
struct EmptyStruct {};

struct MyStruct {
	char sign;
	int index;
	long identification;
	float percent;
	int another_index;
	char word[20];
	//...
};

int main() {
	struct EmptyStruct es;

	//	in C: 0 bytes, in C++: 1 byte!
	printf("amount of bytes for \"es\": %lu\n", sizeof(es));

	//	accessing to members
	struct MyStruct ms;
	ms.sign = 'A';
	ms.index = 100;
	ms.identification = 123L;
	ms.percent = 0.76;
	ms.another_index = 700;
	memset(ms.word, (int) 'F', 10);

	printf("amount of bytes for \"ms\": %lu\n", sizeof(ms));

	//	WYSIWYG
	printf(
		"%c, %d, %ld, %f, %d, %s\n",
		ms.sign, ms.index, ms.identification, ms.percent, ms.another_index, ms.word
	);

	return EXIT_SUCCESS;
}