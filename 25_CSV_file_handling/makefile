all:			project.a preoptions.a
				gcc -g -Wall -o Elements.run project.a preoptions.a
				rm project.a preoptions.a

project.a:		preload.o Runner.o CSV_IO.o
				ar -cr project.a preload.o Runner.o CSV_IO.o
				rm preload.o Runner.o CSV_IO.o

preoptions.a:	conversions.o
				ar -cr preoptions.a conversions.o
				rm conversions.o

preload.o:		preload.c ElementProperties.h csvIO.h
				gcc -c preload.c

Runner.o:		Runner.c ElementProperties.h csvIO.h
				gcc -c Runner.c

CSV_IO.o:		CSV_IO.c ElementProperties.h csvIO.h
				gcc -c CSV_IO.c

conversions.o:	conversions.c ElementProperties.h csvIO.h
				gcc -c conversions.c

clean:
				rm Elements.run
