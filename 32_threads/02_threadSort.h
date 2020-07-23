/*	demonstration about how to sort array elements by using threads	*/

#ifndef NO_THREADS_H
#define NO_THREADS_H

#define	NBR_OF_ELEMENTS		250000			/*	250,000 elements to sort	*/
#define	MINUTES				60
#define	NBR_OF_THREADS		4				/*	4 threads to use			*/

void *bubbleSort(void *argument);
void fillArrayWithElements();
void resetArray();

void failureOperation(const char *message);

#endif
