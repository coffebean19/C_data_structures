
CC=gcc

all: test btree

test: test.c
	$(CC) -o test.out test.c

btree: btree.c
	$(CC) -o btree.out btree.c

C = linkedlist.c main.c
H = linkedlist.h

clear:
	rm test.out