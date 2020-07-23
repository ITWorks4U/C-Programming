/*	demonstration of thread return usage	*/

#ifndef THREAD_RETURN_H
#define	THREAD_RETURN_H

#define	BUFFER			127
#define	NBR_OF_THREADS	16

struct SContent {
	int data;
	char text[BUFFER];
};

void *threadFunction(void *arg);

#endif
