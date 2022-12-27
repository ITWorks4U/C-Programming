#
#	building the application by
#	using a precompiled library

all:						main.c
							@gcc -g3 -Wall main.c ../library/library.dll -o application
							$(info	application created)

clean:
							rm application