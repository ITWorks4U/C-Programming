/*	demonstration about how to use threads in C programming language	*/
#ifndef THREADS_H
#define THREADS_H

/*
 *	We define a function which is able to cooperate
 *	with threads. This function is of type void*
 *	and comes with a single argument of type void*.
 */
void *threadFunction(void *argument);

void failureOperation(const char *message);						/*	if any error occurred	*/

#endif
