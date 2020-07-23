#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include "01_threads.h"

int main() {
	/*
	 *	Using two threads for our purpose, where `thread01` is
	 *	not our running program, it's in use for an own thread.
	 *	Same for `thread02`.
	*/
	pthread_t thread01, thread02;

	/*	---		starting threads	---	*/

	/*
	 * 	int pthread_create(pthread_t *thread, const pthread_attr_t *attribute, void *(*function)(void *), void *argument);
	 * 	starting a new thread by given arguments, where:
	 *
	 * 	 -  thread → the thread to use
	 * 	 -	atrribute → adding some extra attributes, like priority, stack size etc. | NULL → without extra attributes
	 * 	 -	function → a void pointer function with a single parameter of type void poiner
	 * 	 -	argument → a single argument, that may be passed to function, where a cast to void * is required | NULL → no arguments is to be passed
	 *
	 * 	 returning:		0, if successful
	 */
	if ((pthread_create(&thread01, NULL, threadFunction, NULL)) != 0) {
		failureOperation(" pthread_create (thread01)");
	}

	if ((pthread_create(&thread02, NULL, threadFunction, NULL)) != 0) {
		failureOperation(" pthread_create (thread02)");
	}
	
	/*	---	waiting for running threads	---	*/

	/*
	 *	int pthread_join(pthread_t thread, void **thread_return);
	 *	let the main thread wait until the created sub thread has been terminated, where:
	 *
	 *	- thread → the thread to wait for
	 *	- thread_return → may hold the exit status of the current thread | NULL → we're not interested about the return value
	 *
	 *	returning:		0, if successful
	 */
	if ((pthread_join(thread01, NULL)) != 0) {
		failureOperation(" pthread_join (thread01)");
	}

	if ((pthread_join(thread02, NULL)) != 0) {
		failureOperation(" pthread_join (thread02)");
	}
	
	return EXIT_SUCCESS;
}

