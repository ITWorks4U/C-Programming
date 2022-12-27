#	a simple makefile which allows
#	you to build a project very easy
#
#	left side:		target(s)
#	right side:		command(s) for the given target(s)
#
#	Every target may contain dependencies.
#
#	the top target will be used automatically
#	by calling 'make'

#target							dependency for target 'all'
all:							16_makefile_example.o
								gcc -g3 -Wall 16_makefile_example.o -o application

#								a custom information for build process
								$(info Application successfully built.)
#								other messages by: $(warning text) $(error text)

#								removing object file => no longer in use
#								adding '@' in front of a command, the output
#								is suppressed
								@rm 16_makefile_example.o

16_makefile_example.o:			16_makefile_example.c
								gcc -c 16_makefile_example.c

#target must not be called 'clean', but it's often used
#doesn't handle the case, when the file doesn't exist
clean:
								rm application