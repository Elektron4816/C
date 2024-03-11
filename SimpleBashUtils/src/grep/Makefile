CC=gcc
CFLAGS= -Wall -Wextra -Werror

all: s21_grep clean

s21_grep: grep_info.o s21_grep.o
		$(CC) $(CFLAGS) s21_grep.o grep_info.o -o s21_grep

grep_info: grep_info.h grep_info.c
		$(CC) -c $(CFLAGS) grep_info.c
s21_grep.o: s21_grep.c
		$(CC) -c $(CFLAGS) s21_grep.c grep_info.c

clean: 
		rm -rf *.o

rebuild: clean all