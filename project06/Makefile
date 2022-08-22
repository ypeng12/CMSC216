# Yuliang Peng
# Project06
# 118495965

CC = gcc 
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror

ournix.o: ournix.c  ournix.h ournix-datastructure.h
	$(CC) $(CFLAGS) -c ournix.c

all: public01.x  public02.x  public03.x  public04.x  public05.x \
public06.x  public07.x  public08.x public09.x  public10.x \
public11.x  public12.x public13.x public14.x public15.x

test: clean all
	public01.x |diff -b - public01.output
	public02.x |diff -b - public02.output
	public03.x |diff -b - public03.output
	public04.x |diff -b - public04.output
	public05.x |diff -b - public05.output
	public06.x |diff -b - public06.output
	public07.x |diff -b - public07.output
	public08.x |diff -b - public08.output
	public09.x |diff -b - public09.output
	public10.x |diff -b - public10.output
	public11.x |diff -b - public11.output
	public12.x |diff -b - public12.output
	public13.x |diff -b - public13.output
	public14.x |diff -b - public14.output
	public15.x |diff -b - public15.output

public01.x: ournix.o public01.o
	$(CC) ournix.o public01.o -o public01.x
public01.o: public01.c ournix.h
	$(CC) $(CFLAGS) -c public01.c


public02.x: ournix.o public02.o
	$(CC) ournix.o public02.o -o public02.x
public02.o: public02.c ournix.h
	$(CC) $(CFLAGS) -c public02.c


public03.x: ournix.o public03.o 
	$(CC) ournix.o public03.o -o public03.x
public03.o: public03.c ournix.h
	$(CC) $(CFLAGS) -c public03.c


public04.x: ournix.o public04.o 
	$(CC) ournix.o public04.o -o public04.x
public04.o: public04.c  ournix.h
	$(CC) $(CFLAGS) -c public04.c


public05.x: ournix.o public05.o 
	$(CC) ournix.o public05.o  -o public05.x
public05.o: public05.c  ournix.h
	$(CC) $(CFLAGS) -c public05.c


public06.x: ournix.o public06.o 
	$(CC) ournix.o public06.o  -o public06.x
public06.o: public06.c ournix.h
	$(CC) $(CFLAGS) -c public06.c


public07.x: ournix.o public07.o 
	$(CC) ournix.o public07.o  -o public07.x
public07.o: public07.c ournix.h
	$(CC) $(CFLAGS) -c public07.c


public08.x: ournix.o public08.o 
	$(CC) ournix.o public08.o  -o public08.x
public08.o: public08.c ournix.h
	$(CC) $(CFLAGS) -c public08.c



public09.x: ournix.o public09.o 
	$(CC) ournix.o public09.o  -o public09.x
public09.o: public09.c  ournix.h
	$(CC) $(CFLAGS) -c public09.c


public10.x: ournix.o public10.o driver.o
	$(CC) ournix.o public10.o driver.o -o public10.x
public10.o: public10.c driver.h ournix.h
	$(CC) $(CFLAGS) -c public10.c


public11.x: ournix.o public11.o 
	$(CC) ournix.o public11.o  -o public11.x
public11.o: public11.c ournix.h
	$(CC) $(CFLAGS) -c public11.c


public12.x: ournix.o public12.o 
	$(CC) ournix.o public12.o  -o public12.x
public12.o: public12.c ournix.h
	$(CC) $(CFLAGS) -c public12.c


public13.x: ournix.o public13.o
	$(CC) ournix.o public13.o -o public13.x
public13.o: public13.c ournix.h
	$(CC) $(CFLAGS) -c public13.c


public14.x: public14.o ournix.o memory-checking.o
	$(CC) public14.o ournix.o memory-checking.o -o public14.x


public14.o: public14.c ournix.h
	$(CC) $(CFLAGS) -g -c public14.c



public15.x: public15.o ournix.o memory-checking.o
	$(CC) public15.o ournix.o memory-checking.o -o public15.x

public15.o: public15.c ournix.h memory-checking.h
	$(CC) $(CFLAGS) -c public15.c


clean: 
	rm -rf *.x
	rm -rf public15.o public14.o public13.o public12.o
	rm -rf public11.o public10.o public09.o public08.o 
	rm -rf public07.o public06.o public05.o public04.o 
	rm -rf public03.o public02.o public01.o ournix.o


run: all
	public01.x
	public02.x
	public03.x
	public04.x
	public05.x
	public06.x
	public07.x
	public08.x
	public09.x
	public10.x
	public11.x
	public12.x
	public13.x
	public14.x
	public15.x

