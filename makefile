all: file.h wav.h file.c wav.c main.c
	clang main.c file.c wav.c -Wall -g -o reverse
