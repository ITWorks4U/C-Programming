#####################
####	targets	#####
#####################

#	thread with arguments
ex4:						34_thread_with_arguments.o
							@gcc -g3 -Wall 34_thread_with_arguments.o -o application -lm -lpthread
							@rm *.o
							$(info application "thread with arguments" built)

#	thread priority
ex5:						34_thread_priority.o
							@gcc -g3 -Wall 34_thread_priority.o -o application -lpthread
							@rm *.o
							$(info application "thread priority" built)

#	detaching threads
ex6:						34_thread_detach.o
							@gcc -g3 -Wall 34_thread_detach.o -lpthread -lm -o application
							@rm *.o
							$(info application "detaching threads" built)

#	mutex and threads
ex7:						34_thread_mutex.o
							@gcc -g3 -Wall 34_thread_mutex.o -lm -lpthread -o application
							@rm *.o
							$(info application "mutex and threads" built)

#####################
####	sources	#####
#####################

34_thread_with_arguments.o:	34_thread_with_arguments.c
							@gcc -c 34_thread_with_arguments.c

34_thread_detach.o:			34_thread_detach.c
							@gcc -c 34_thread_detach.c

34_thread_mutex.o:			34_thread_mutex.c
							@gcc -c 34_thread_mutex.c

34_thread_priority.o:		34_thread_priority.c
							@gcc -c 34_thread_priority.c

#####################
###	clean up	#####
#####################
clean:
							@rm application
							$(info application removed)