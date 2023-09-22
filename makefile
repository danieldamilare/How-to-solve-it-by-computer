CC=gcc
CFLAGS = -g3 -Wall -Wextra -pedantic

all:

test: test_quicksort
	./test_quicksort
	@echo OK!

test_quicksort: test_quicksort.o tester.o quicksort.o
	$(CC) $(CFLAGS) -o $@ $^

test_quicksort.o: quicksort.h tester.h

quicksort.o: quicksort.h
