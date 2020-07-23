#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "03_threadPriority.h"

void printThreadPriority(pthread_t th) {
	int policy;

	/*
	 *	Data structure to describe a process' schedulability.
	 *	For more details: look into system file struct_sched_param.h
	*/
	struct sched_param param;

	if (pthread_getschedparam(th, &policy, &param) == 0) {
		printf(" let's see: ");
		switch (policy) {
			case SCHED_OTHER:
				printf("\"SCHED_OTHER\"");
				break;
			case SCHED_FIFO:											/*	fifo pipe											*/
				printf("\"SCHED_FIFO\"");
				break;
			case SCHED_RR:												/*	round robin											*/
				printf("\"SCHED_RR\"");
				break;
			default:
				printf("unknown schedule...");
		}

		printf("\n gotten priority: %d\n", param.sched_priority);
	}
}

void setThreadPriority(pthread_t th, int policy, int priority) {
	struct sched_param param;
	param.sched_priority = priority;

	/*	Set the scheduling parameters for TARGET_THREAD according to POLICY and *PARAM.  */
	if (pthread_setschedparam(pthread_self(), policy, &param) != 0) {
		fprintf(stderr, " Unable to set schedule parameter!\n");
		pthread_exit((void *) pthread_self());							/*	terminate the current thread						*/
	}
}

void *threadPriorityDemoFunction(void *arg) {
	printThreadPriority(pthread_self());								/*	asking for the current thread prioity				*/

	if (getuid() != 0) {												/*	only the user root is able to modify the priority	*/
		fprintf(stderr, " The user \"root\" is required.\n");
		return NULL;
	}

	setThreadPriority(pthread_self(), SCHED_RR, 2);
	printThreadPriority(pthread_self());								/*	again: asking for the current thread prioity		*/

	return NULL;
}
