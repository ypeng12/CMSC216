# Project #8 public tests makefile

# (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
# not to provide it to anyone else.

CC = gcc
CFLAGS= -g -ansi -pedantic-errors -Wall -fstack-protector-all -Werror

# create all public tests

all: public01.x public02.x public03.x public04.x public05.x \
     public06.x public07.x public08.x public09.x public10.x \
     public11.x

# link object files to form executables

public01.x: public01.o fakefile.o split.o safe-fork.o
	$(CC) public01.o fakefile.o split.o safe-fork.o -o public01.x

public02.x: public02.o fakefile.o split.o safe-fork.o
	$(CC) public02.o fakefile.o split.o safe-fork.o -o public02.x 

public03.x: public03.o fakefile.o split.o safe-fork.o
	$(CC) public03.o fakefile.o split.o safe-fork.o -o public03.x

public04.x: public04.o fakefile.o split.o safe-fork.o
	$(CC) public04.o fakefile.o split.o safe-fork.o -o public04.x

public05.x: public05.o fakefile.o split.o safe-fork.o
	$(CC) public05.o fakefile.o split.o safe-fork.o -o public05.x 

public06.x: public06.o fakefile.o split.o safe-fork.o
	$(CC) public06.o fakefile.o split.o safe-fork.o -o public06.x 

public07.x: public07.o fakefile.o split.o safe-fork.o make-target.o
	$(CC) public07.o fakefile.o split.o safe-fork.o make-target.o \
              -o public07.x

public08.x: public08.o fakefile.o split.o safe-fork.o make-target.o
	$(CC) public08.o fakefile.o make-target.o split.o safe-fork.o \
              -o public08.x

public09.x: public09.o fakefile.o split.o safe-fork.o make-target.o
	$(CC) public09.o fakefile.o split.o safe-fork.o make-target.o \
              -o public09.x 

public10.x: public10.o fakefile.o split.o safe-fork.o make-target.o
	$(CC) public10.o fakefile.o split.o safe-fork.o make-target.o \
              -o public10.x 

public11.x: public11.o fakefile.o split.o safe-fork.o memory-checking.o
	$(CC) public11.o fakefile.o split.o safe-fork.o memory-checking.o \
              -o public11.x 

# create object files

public01.o: public01.c fakefile.h fakefile-datastructure.h
	$(CC) $(CFLAGS) -c public01.c

public02.o: public02.c fakefile.h fakefile-datastructure.h
	$(CC) $(CFLAGS) -c public02.c

public03.o: public03.c fakefile.h fakefile-datastructure.h
	$(CC) $(CFLAGS) -c public03.c

public04.o: public04.c fakefile.h fakefile-datastructure.h
	$(CC) $(CFLAGS) -c public04.c

public05.o: public05.c fakefile.h fakefile-datastructure.h
	$(CC) $(CFLAGS) -c public05.c

public06.o: public06.c fakefile.h fakefile-datastructure.h
	$(CC) $(CFLAGS) -c public06.c

public07.o: public07.c fakefile.h fakefile-datastructure.h make-target.h
	$(CC) $(CFLAGS) -c public07.c

public08.o: public08.c fakefile.h fakefile-datastructure.h make-target.h
	$(CC) $(CFLAGS) -c public08.c

public09.o: public09.c fakefile.h fakefile-datastructure.h make-target.h
	$(CC) $(CFLAGS) -c public09.c

public10.o: public10.c fakefile.h fakefile-datastructure.h make-target.h
	$(CC) $(CFLAGS) -c public10.c

public11.o: public11.c fakefile.h fakefile-datastructure.h memory-checking.h
	$(CC) $(CFLAGS) -c public11.c

fakefile.o: fakefile.c fakefile.h fakefile-datastructure.h split.h safe-fork.h
	$(CC) $(CFLAGS) -c fakefile.c

clean:
	rm -f public*.o public*.x fakefile.o
