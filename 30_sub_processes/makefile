#start a child process
subProcess01:			subProcess01.c
						gcc -g -Wall -o branchedProcess.run subProcess01.c

#create a process, which doesn't have a parent process
subProcess02:			subProcess02.c
						gcc -g -Wall -o orphanProcess.run subProcess02.c

#create a zombie process
subProcess03:			subProcess03.c
						gcc -g -Wall -o zombieProcess.run subProcess03.c

#remove all running programs
clean:
						rm *.run
