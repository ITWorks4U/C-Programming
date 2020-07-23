/*	demonstration about to cancel a thread */
#ifndef THREAD_CANCELLING_H
#define THREAD_CANCELLING_H

#define	NBR_OF_THREADS	16

unsigned int createRandomNumber();
void *threadFunction(void *arg);

#endif
