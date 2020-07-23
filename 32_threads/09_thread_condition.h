/*	demonstration of thread conditions	*/
#ifndef THREAD_CONDITION_H
#define	THREAD_CONDITION_H

#define	NBR_OF_THREADS	16
#define	BUFFER			255

struct SHolder {
	char text[BUFFER];
};

void *threadFunction(void *arg);
void exitHandlerFunction(void *arg);				/*	exit handler function with threads	*/

#endif
