/*	demonstration of thread synchronizing	*/

#ifndef THREAD_SYNCHRO_H
#define	THREAD_SYNCHRO_H

#define	BUFFER				512
#define	COUNTER				1000000				/*	1,000,000	*/
#define	FILE_TO_MODIFY		"threadFile.txt"
#define	MINUTES				60

typedef enum EOperation {
	READ_THE_FILE,
	WRITE_THE_FILE
}Operation;

void openFile(Operation op);
void closeFile();

void *writeIntoFile(void *arg);
void *readFromFile(void *arg);

#endif
