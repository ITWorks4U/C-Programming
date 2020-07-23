#build everything
all:			keywords.a
				gcc -g -Wall -o keywords.run keywords.a
				rm keywords.a

#cretate a static library
keywords.a:		keywords.o extern/extern.o register/register.o auto/auto.o static/static.o
				ar -cr keywords.a keywords.o extern/extern.o register/register.o auto/auto.o static/static.o
				rm keywords.o extern/extern.o register/register.o auto/auto.o static/static.o

#objective files from source files
extern.o:		extern/extern.c extern/extern.h
				gcc -c extern/extern.c

auto.o:			auto/auto.c keywords.h
				gcc -c auto/auto.c

static.o:		static/static.c keywords.h
				gcc -c static/static.c

register.o:		register/register.c keywords.h
				gcc -c register/register.c

keywords.o:		keywords.c keywords.h
				gcc -c keywords.c

#remove execution program
clean:
				rm keywords.run
