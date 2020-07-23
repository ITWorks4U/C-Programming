/**
*	How to handle errors in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>													/*	contains the perror() function	*/
#include <stdlib.h>
#include <errno.h>													/*	required for variable errno		*/
#include <string.h>													/*	comes with strerror() function	*/

int main() {
	FILE *nonsense = fopen("accessDenied.txt", "r");		//	try to open an invalid file stream
	int exitCode = 0;												//	exit code for program

	/*	We also could use the assert() function to assume that the given FILE pointer should not be NULL. However, if the
	*	pointer is NULL, then the program is going to terminate by an abnormal way.
	*/
	//assert(nonsense != NULL);										//	will always fail
	if (nonsense == NULL) {
		exitCode = errno;											//	optional: copy the value of errno to errCode
		
		/*	try to figure out what kind of error occurred	*/
		switch(exitCode) {
			case ENOENT:											/*	"no such file or directory	"	*/
				perror(" file error");								/*	prints a detailed message		*/
				fprintf(stderr, " error: File not found!\n");		/*	prints your own message			*/
				printf(" %s\n", strerror(exitCode));				/*	prints a short detailed message	*/
				break;
			case EFAULT:											/*	bad address						*/
				perror(" Error with memory");
				break;
			case EACCES:											/*	permission denied				*/
				perror(" Error with access");				
				break;
			default:												/*	any other error					*/
				perror(" Any other error");
		}

		return exitCode;
	}
	
	puts(" ;-)");
	fclose(nonsense);
	return exitCode;
}
