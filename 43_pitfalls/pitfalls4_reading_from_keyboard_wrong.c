/*	Reading from keyboard can be used in different ways, but these has also (nasty) side effects.
*	Remember:	every input a string by default
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BUFFER	100

int main(void) {
	char content[BUFFER];
	memset(content, '\0', (size_t) BUFFER);
	int a = 255;

	printf("Enter up to 100 characters: ");

	/*	Way 1:	Honestly, don't do this!
	*
	*	int gets(char *s); doesn't care about limitations, thus if you're exceeding the limit of
	*	BUFFER, "a" might have a different value instead of 255, but your application crashes
	*	due a stack smash
	*/
	/* gets(content); */

	/*	Way 2:	int scanf(const char *__restrict__ __format, ...); but this can also be a huge pitfall...
	*
	*	by using an input with at least one space every input in front of the space bar
	*	will be read; the rest stays in the buffer for the next input attempt an will be
	*	used automatically
	*
	*	By the way, %99s or else does not cut your input to 99 characters.
	*	"%s" tells, that the incoming input shall be formatted into a c-string for the
	*	certain content buffer, which is declared as a c-string as well
	*
	*	If you want to convert an input into a number, like integer, you could use:
	*	- int scanf("%d ", &address_pointer_for_integer);
	*	  =>	not recommended
	*	  =>	missing to transfer into the address of an integer causes an undefined behavior
	*	  =>	What happens, if you want "0" as a number?
	*
	*	- int atoi(const char *nptr);
	*	  =>	not recommended
	*	  =>	deprecated function
	*	  =>	doesn't care about size limitation
	*	  =>	use long strtol(const char *nptr, char **endptr, int base); instead
	*
	*	What will happen, if you're using any other format, or if "content" has not been
	*	defined as a c-string? => Undefined behavior. >:-)
	*
	*	If you're also exceeding the limit of BUFFER, your application will crash.
	*/
	/* scanf("%s", content); */

	/*	Way 3:	char *fgets(char *__restrict__ __s, int __n, FILE *__restrict__ __stream);
	*
	*	The "default" way to read an input correctly and ensures, that the limitation
	*	is able to handle, but guess what? This has also some pitfalls...
	*
	*	- the return character ("\n"; by enter; depending on which OS you're working on, it could ALSO be: "\r", "\r\n")
	*	  will also be added into your c-string
	*	  - to avoid to get the return character you can read BUFFER-1 or the last
	*	    character shall be removed from content or replaced
	*	- if you're exceeding your limit, every input below the limit will be handled, the
	*	  input left stays in the buffer for the next input command and will be filled
	*	  automatically
	*/
	/* fgets(content, BUFFER-1, stdin); */

	printf("content = %s, whereas a = %d\n", content, a);


	/*	Way 4:	using ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
	*
	*	Unlike to (forced) limit your input by using fgets(), perhaps getline could be the way to go...
	*
	*	Guess, what? This function also has side effects! *grinning*
	*	- you can't use a static c-string with a fixed length
	*	- "n" must be able to address to an integer
	*	- "lineptr" is a c-string with a "dynamic" length
	*/

	/* getline(&content, &BUFFER, stdin); */
	/*
	char *line = NULL;
	size_t buff = 0;
	getline(&line, &buff, stdin);
	printf("line = %s, whereas a = %d\n", line, a);
	*/

	/*	In summary, if you want to use integers from keyboard, use regular expressions instead.
	*	Take a look to part: 30_regular_expressions.
	*/

	return EXIT_FAILURE;
}