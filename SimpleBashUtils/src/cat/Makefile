CC=gcc
CFLAGS= -Wall -Wextra -Werror

all: s21_cat


s21_cat: info.o s21_cat.o
		$(CC) $(CFLAGS) s21_cat.o info.o -o s21_cat

info.o: info.h info.c
		$(CC) -c $(CFLAGS) info.c
s21_cat.o: s21_cat.c
		$(CC) -c $(CFLAGS) s21_cat.c info.c

clean: 
		rm -rf *.o s21_cat

rebuild: clean all