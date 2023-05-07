#	makefile for moonlanding simulation
OBJECT_FILES=moon_landing.o message_collector.o main.o
APPLICATION=moon_landing_simulation
MOON_FILE=moon_landing.c
MOON_HEADER=moon_landing.h
MESSAGE_FILE=message_collector.c
MESSAGE_HEADER=message_collector.h

all:					moonlanding message main
						@gcc -g3 -Wall -o $(APPLICATION) $(OBJECT_FILES)
						@rm $(OBJECT_FILES)
						$(info Application ready.)

moonlanding:			$(MOON_FILE) $(MOON_HEADER)
						@gcc -g3 -Wall -c $(MOON_FILE)
						$(info Building game.)

message:				$(MESSAGE_FILE) $(MESSAGE_HEADER)
						@gcc -g3 -Wall -c $(MESSAGE_FILE)
						$(info Building messages.)


main:					main.c $(MESSAGE_HEADER) $(MOON_HEADER)
						@gcc -g3 -Wall -c main.c
						$(info Building starting entry.)

clean:
						@rm $(APPLICATION)
						$(info Application removed.)
