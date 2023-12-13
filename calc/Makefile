CC=gcc
CFLAGS=-Wall -Werror -Wextra -fsanitize=address -std=c11
GCOV=-fprofile-arcs -ftest-coverage

all: calc.a gcov_report

%.o: %.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@
calc.a: calc_func.o calc.o
		ar rc calc.a $^
		ranlib calc.a

test: test.c calc.a
		$(CC) $(CFLAGS) $(GCOV) *.c -lcheck -lm -L. calc.a -o test
		./test

gcov_report: test
		lcov -t "./gcov" -o gcov.info --no-external -c -d .
		genhtml -o gcov gcov.info
		open ./gcov/index.html

clean:
		rm -rf *.o *.info *.gcda *.gcno ./gcov test calc.a

rebuild: clean all