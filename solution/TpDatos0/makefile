
CC=gcc
CFLAGS=-Wall -g -pg

all: tp

tp:tp.c
		$(CC) $(CFLAGS) tp.c -o tp

run: tp
	valgrind --track-origins=yes --leak-check=full ./tp
