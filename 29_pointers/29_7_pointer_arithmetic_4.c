#include <stdio.h>
#include <stdlib.h>

int main(void) {
/*
		pointer arithmetic means:	"incrementing / decrementing a pointer and see, which next value returns"
		Guess what? It's no guarantee, that this works always fine!

		Since a pointer has a known size of 8 bytes, this won't work with pointer arithmetic!
	*/

	//	How to "walk" trough your array / c-string without using strlen(expression)?
	char expression[] = "Pointers aren't hard to use, right?";

	//	first assuming:
	char c = expression[0];

	while(c != '\0') {
		printf("%c", c);
		// printf("%c (ASCII: %d)\n", c, (int) c);
		c++;
	}

	puts("-----------------");

	/*
		Explanation:

		Have you expected to see:
		Pointers ...?

		Well, now you know, you were wrong!

		Since c "points" to the first character of expression,
		by using c++ in the while loop, this DOESN'T mean, that
		the next character should be o, i, n, t, ...

		c++ returns the character from ASCII
		=> P (ASCII position 84)
		=> U (ASCII position 85)
		=> V (ASCII position 86)
		...
		continuing with the negative values from -128 to -1
		until c++ returns 0 (\0)
	*/

	/*	correct usage:	*/
	int ctr = 1;

	while(c != '\0') {
		printf("%c", c);
		c = *(expression + ctr);
		ctr++;
	}

	/*
		Explanation:

		To make sure to get the next character,
		we have to dereference the pointer to get the current character
		and we're using the next character by ctr, which gives us the
		next and expected character.
	*/

	/*	DON'T USE:	*/
	while(c != '\0') {
		printf("%c", c);
		c = *(expression + 1);
	}

	/*
		Explanation:

		This causes to get the next character of expression once only,
		because *(expression + 1) returns the next character from position 0!

		In a loop it returns Poooooooooooooooooo..... and you'll never get the termination character (\0)!
	*/

	return EXIT_SUCCESS;
}