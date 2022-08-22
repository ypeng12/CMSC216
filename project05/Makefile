# Yuliang Peng
# Project05
# 118495965

CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror

all:  main.x application.x tester.x


main.x: main.o init.o test-equal.o
	$(CC) main.o init.o test-equal.o -o main.x

application.x: application.o test-equal.o
	$(CC) application.o test-equal.o -o application.x

tester.x: init.o increment.o add-elements.o tester.o
	$(CC) init.o increment.o add-elements.o tester.o -o  tester.x


main.o: main.c init.h test-equal.h
	$(CC) $(CFLAGS) -c main.c

application.o: application.c test-equal.h 
	$(CC) $(CFLAGS) -c application.c

tester.o: tester.c init.h increment.h add-elements.h 
	$(CC) $(CFLAGS) -c tester.c

init.o: init.c init.h 
	$(CC) $(CFLAGS) -c init.c

test-equal.o: test-equal.c test-equal.h
	$(CC) $(CFLAGS) -c test-equal.c

increment.o: increment.c increment.h
	$(CC) $(CFLAGS) -c increment.c

add-elements.o: add-elements.c add-elements.h 
	$(CC) $(CFLAGS) -c add-elements.c

clean:
	rm -rf *.x
	rm -rf application.o main.o tester.o
	rm -rf init.o test-equal.o increment.o add-elements.o