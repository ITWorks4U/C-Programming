/**	@author			ITWorks4U	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    /*  Count all characters of printf and print the result to the console, too.    */
    int nbrWords = printf("Hello World! How many characters contains this output?\n");
    printf("Solution: %d characters!\n", nbrWords);

    /*  unused variable --> more useful for the given makefile	*/
    char word[30];

    return EXIT_SUCCESS;
}
