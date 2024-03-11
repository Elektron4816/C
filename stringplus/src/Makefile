CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
GCOV=-fprofile-arcs -ftest-coverage

all: s21_string.a gcov_report

%.o: %.c s21_string.h
	$(CC) $(CFLAGS) -c $< -o $@

s21_string.a: s21_strlen.o s21_strstr.o s21_strchr.o s21_strrchr.o s21_strncat.o s21_strncpy.o s21_strcspn.o s21_memcmp.o s21_memset.o s21_memcpy.o s21_memchr.o s21_strpbrk.o s21_strncmp.o s21_strerror.o s21_to_upper.o s21_to_lower.o s21_insert.o s21_trim.o s21_strtok.o s21_sprintf.o
		ar rc s21_string.a $^
		ranlib s21_string.a

test: test.c s21_string.a
		$(CC) $(CFLAGS) $(GCOV) *.c -lcheck -lm -L. s21_string.a -o test
		./test 

gcov_report: test
		lcov -t "./gcov" -o gcov.info --no-external -c -d .
		genhtml -o gcov gcov.info
		open ./gcov/index.html


clean:
		rm -rf *.o *.info *.gcda *.gcno ./gcov

rebuild: clean all