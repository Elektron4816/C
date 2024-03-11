CC=gcc
CFLAGS=-Wall -Werror -Wextra -fsanitize=address -std=c11
GCOV=-fprofile-arcs -ftest-coverage

all: install

%.o: %.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@
calc.a: calc_func.o calc.o
		ar rc calc.a $^
		ranlib calc.a

test: test.c calc.a
		$(CC) $(CFLAGS) $(GCOV) *.c -lcheck -lm -L. calc.a -o test
		./test

install:
		rm -rf s21_smart_calc
		mkdir s21_smart_calc
		qmake s21_SmartCalc.pro -o s21_smart_calc
		cd s21_smart_calc && make && cd ../
		chmod +x s21_smart_calc/s21_SmartCalc.app
		ln -s ${PWD}/s21_smart_calc/s21_SmartCalc.app ${HOME}/Desktop

uninstall:
		rm -rf s21_smart_calc
		rm -rf /Users/verlinej/Desktop/s21_SmartCalc.app

gcov_report: test
		lcov -t "./gcov" -o gcov.info --no-external -c -d .
		genhtml -o gcov gcov.info
		open ./gcov/index.html

clang: 
	clang-format -n *.c *.cpp *.h

clean:
		rm -rf *.o *.info *.gcda *.gcno ./gcov test calc.a

rebuild: clean all