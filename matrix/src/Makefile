CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
GCOV=-fprofile-arcs -ftest-coverage


ifeq ($(shell uname -s),Linux)
OFLAGS=-lcheck -lsubunit -lm -lrt -lpthread
endif
ifeq ($(shell uname -s),Darwin)
OFLAGS=-lcheck -lm -lpthread
endif


all: s21_matrix.a gcov_report

%.o: %.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

s21_matrix.a: s21_create_matrix.o check_true.o s21_eq_matrix.o s21_mult_number.o s21_remove_matrix.o s21_sub_matrix.o s21_sum_matrix.o s21_mult_matrix.o s21_transpose.o s21_determinant.o s21_calc_complements.o s21_inverse_matrix.o
		ar rc s21_matrix.a $^
		ranlib s21_matrix.a

test: test.c s21_matrix.a
		$(CC) $(CFLAGS) $(GCOV) *.c $(OFLAGS) -L. s21_matrix.a -o test
		./test

gcov_report: test
		lcov -t "./gcov" -o gcov.info --no-external -c -d .
		genhtml -o gcov gcov.info
		open ./gcov/index.html

clean:
		rm -rf *.o *.info *.gcda *.gcno ./gcov ./test ./s21_matrix.a

rebuild: clean all