/*	demonstration of using the parameter for a thread	*/
#ifndef THREAD_PARAM_H
#define THREAD_PARAM_H

#define	NBR_OF_THREADS	4

unsigned int createANewRandomNumber(int nbr);
void *threadFunction(void *argument);

#endif
