/*	demonstration of thread priority	*/
#ifndef THREAD_PRIORITY_H
#define THREAD_PRIORITY_H

#define	NBR_OF_THREADS	4
#include <pthread.h>

void printThreadPriority(pthread_t th);								/*	print the current thread priority	*/
void setThreadPriority(pthread_t th, int policy, int priority);		/*	set a new thread priority			*/

void *threadPriorityDemoFunction(void *arg);

#endif
