# A simple commentary is here...

include macros.mk

#building
all:				main.o
					@gcc -g3 -Wall -o $(TARGET) main.o
					@rm main.o

					$(info Building successful.)

main.o:				main.c
					@gcc -c main.c

clean:
					rm $(TARGET)
