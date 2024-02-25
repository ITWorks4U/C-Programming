/*
	A thread may have a priority to work earlier or later.

	Attention:
		- you need to run your application with sudo to change it
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void print_thread_priority(pthread_t thread) {
	int policy;
	struct sched_param param;

	if (pthread_getschedparam(thread, &policy, &param) == 0) {
		printf("let's take a look: ");

		switch(policy) {
			case SCHED_OTHER: {
				puts("SCHED_OTHER");
				break;
			} case SCHED_FIFO: {
				puts("SCHED_FIFO");
				break;
			} case SCHED_RR: {
				puts("SCHED_RR");
				break;
			} default: {
				puts("unknown schedule...");
				break;
			}
		}

		printf("the thread priority is: %d\n", param.sched_priority);
	}
}

void set_thread_priority(pthread_t thread, int policy, int priority) {
	struct sched_param param;
	param.sched_priority = priority;

	if (pthread_setschedparam(thread, policy, &param) != 0) {
		fprintf(stderr, "unable to set thread priority...\n");
		pthread_exit((void *) pthread_self());
	} else {
		puts("thread priority set");
	}
}

void *thread_priority_demo_function(void *arg) {
	print_thread_priority(pthread_self());

	/*	user root is required	*/
	if (getuid() != 0) {
		fprintf(stderr, "launch the application with sudo\n");
	} else {
		int *arg_val = (int *) arg;
		int policy = 0;						//	SCHED_OTHER

		switch(arg_val[0]) {
			case 1:
				policy = 1;					//	SCHED_FIFO
				break;
			case 2:
				policy = 2;					//	SCHED_RR
				break;
			default:
				break;
		}

		set_thread_priority(pthread_self(), policy, arg_val[0]);
		print_thread_priority(pthread_self());
	}

	return NULL;
}

int main(void) {
	pthread_t thread1, thread2;
	int thread_arg[] = {1, 2};

	pthread_create(&thread1, NULL, thread_priority_demo_function, (void *) &thread_arg[0]);
	pthread_create(&thread2, NULL, thread_priority_demo_function, (void *) &thread_arg[1]);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return EXIT_SUCCESS;
}