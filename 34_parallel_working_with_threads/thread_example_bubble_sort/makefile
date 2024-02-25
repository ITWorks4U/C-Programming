#####################
####	targets	#####
#####################

#	without threads
ex1:						34_basic_workflow.o 34_threads.o
							@gcc -g3 -Wall 34_basic_workflow.o 34_threads.o -lm -o application
							@rm *.o
							$(info application "without threads" built)

#	with posix threads
ex2:						34_posix_threads.o 34_threads.o
							@gcc -g3 -Wall 34_posix_threads.o 34_threads.o -lm -lpthread -o application
							@rm *.o
							$(info application "with threads" built)

#	compared with sub processes
ex3:						34_comparing_with_fork.o 34_threads.o
							@gcc -g3 -Wall 34_comparing_with_fork.o 34_threads.o -lm -o application
							@rm *.o
							$(info application "with sub processes" built)

#####################
####	sources	#####
#####################

34_basic_workflow.o:		34_basic_workflow.c 34_threads.h
							@gcc -c 34_basic_workflow.c

34_posix_threads.o:			34_posix_threads.c 34_threads.h
							@gcc -c 34_posix_threads.c

34_comparing_with_fork.o:	34_comparing_with_fork.c 34_threads.h
							@gcc -c 34_comparing_with_fork.c

34_threads.o:				34_threads.c 34_threads.h
							@gcc -c 34_threads.c

#####################
###	clean up	#####
#####################
clean:
							@rm application
							$(info application removed)