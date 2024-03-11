CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
GCOV=-fprofile-arcs -ftest-coverage

all: s21_math.a gcov_report

%.o: %.c s21_math.h
		$(CC) $(CFLAGS) -c $< -o $@
s21_math.a: s21_abs.o s21_fabs.o s21_floor.o s21_ceil.o s21_sin.o s21_cos.o s21_tan.o s21_exp.o s21_log.o s21_pow.o s21_fmod.o s21_sqrt.o s21_atan.o s21_asin.o s21_acos.o
		ar rc s21_math.a $^
		ranlib s21_math.a

test: test.c s21_math.a
		$(CC) $(CFLAGS) $(GCOV) *.c -lcheck -lm -L. s21_math.a -o test
		./test

gcov_report: test
		lcov -t "./gcov" -o gcov.info --no-external -c -d .
		genhtml -o gcov gcov.info
		open ./gcov/index.html


clean: 
		rm -rf *.o *.info *.gcda *.gcno ./gcov

rebuild: clean all