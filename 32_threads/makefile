#using the given parameter for our purpose
05_parameter_usage:			05_param.h 05_param.c
							gcc -g -Wall -o 05_param.run 05_param.h 05_param.c -lpthread

#using thread return value
06_return_value:			06_return.h 06_return.c
							gcc -g -Wall -o 06_return.run 06_return.h 06_return.c -lpthread

#detaching a thread
07_thread_detach:			07_detach.h 07_detach.c
							gcc -g -Wall -o 07_detach.run 07_detach.h 07_detach.c -lpthread

#canceling a thread
08_cancel_thread:			08_cancel_thread.h 08_cancel_thread.c
							gcc -g -Wall -o 08_cancel_thread.run 08_cancel_thread.h 08_cancel_thread.c -lpthread

#set a condition for a thread
09_thread_condition:		09_thread_condition.h 09_thread_condition.c
							gcc -g -Wall -o 09_thread_condition.run 09_thread_condition.h 09_thread_condition.c -lpthread

04_thread_synchro:			04_threadSynchro.c 04_threadSynchro.h
							gcc -g -Wall -o 04_thread_synchro.run 04_threadSynchro.h 04_threadSynchro.c -lpthread

clean:
							rm *.run
