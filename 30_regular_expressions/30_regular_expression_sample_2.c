/*
	Regular expressions might be hard to understand, however, this is a well made
	way to check an expression against a filter.

	Unlike to the primitive way, you're defining a filter, which checks, if the certain
	word (alpha numerical characters, numerical characters, ...) passes through the
	filter or won't.
*/

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

/*
	The pattern is defined as:
	"Any expression in the range of A-Z OR a-z OR 0-9 with at least
	ONE character passes trough the filter."
*/
#define	REGEX_PATTERN	"^[A-Za-z0-9]+$"

int on_match(const char *string_to_compare);

int main(void) {
	/*	This word shall pass trough the filter.	*/
	char expression[] = "A400g3333";

	printf("result: \"%s\" does ", expression);

	switch(on_match(expression)) {
		case 0:
			puts("match!");
			break;
		case 1:
			puts("not match!");
			break;
		default:
			puts("not proceed, because there was an error...");
			break;
	}

	return EXIT_SUCCESS;
}

int on_match(const char *string_to_compare) {
	int result = 1;
	regex_t reg;

	/*
		int regcomp(regex_t *__restrict__ __preg, const char *__restrict__ __pattern, int __cflags);

		Compile your regular expression object on runtime.
		It's required, otherwise you'll receive a segmentation fault.

		returns:
			0:	no error
			-1:	error and ERRNO is set
	*/
	if (regcomp(&reg, REGEX_PATTERN, REG_EXTENDED) < 0) {
		return -1;
	}

	/*
		int regexec(const regex_t *__restrict__ __preg, const char *__restrict__ __String, size_t __nmatch, regmatch_t *__restrict__ __pmatch, int __eflags);

		Execute the regular expression procedure.

		preg:	pointer to a compiled regular expression to compare against STRING
		string:	pointer to a string to be matched
		nmatch:	number of sub-expressions to match (optional) => 0: doesn't care
		pmatch:	array of offsets into STRING which matched the corresponding sub-expressions in preg => NULL: doesn't care
		eflags:	bit flag defining customizable behavior of regexec()

		REG_NOTBOL
			indicates that the first character of STRING is not the beginning of the line
		REG_NOTEOL
			indicates that the first character of STRING is not the end of the line

		returns:
			0:	regular expression check was successful
			1:	regular expression check was not successful
	*/
	result = regexec(&reg, string_to_compare, 0, NULL, 0);

	/*
		void regfree(regex_t *__preg);

		Release allocated memory for regular expression object.
		The expression defined by preg is no longer a compiled
		regular or extended expression.
	*/
	regfree(&reg);

	return result;
}