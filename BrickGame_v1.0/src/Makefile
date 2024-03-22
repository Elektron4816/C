CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
GCOV=-fprofile-arcs -ftest-coverage

PATH_FR = ./gui/cli/
PATH_BK = ./brick_game/tetris/


SRC_FR = $(wildcard $(PATH_FR)*.c)
SRC_BK = $(wildcard $(PATH_BK)*.c)
OBJ_FR = $(patsubst $(PATH_FR)%.c, ./out/%.o, $(SRC_FR))
OBJ_BK = $(patsubst $(PATH_BK)%.c, ./out/%.o, $(SRC_BK))

ifeq ($(shell uname -s),Linux)
OFLAGS=-lcheck -lsubunit -lm -lrt -lpthread -lncurses
endif
ifeq ($(shell uname -s),Darwin)
OFLAGS=-lcheck -lm -lpthread -lncurses
endif


all: install

install: $(OBJ_FR) $(OBJ_BK)
	$(CC) $(CFLAGS)  $^ -o tetris -lncurses

uninstall: clean

./out/%.o: ./brick_game/tetris/%.c
	$(CC) $(CFLAGS) -c $< -o $@

./out/%.o: ./gui/cli/%.c
	$(CC) $(CFLAGS) -c $< -o $@

tet.a: $(OBJ_FR) $(OBJ_BK)
	ar rc tet.a $^
	ranlib tet.a

test: test.c tet.a
	$(CC) $(CFLAGS) $(GCOV) $(PATH_FR)*.c $(PATH_BK)back.c *.c $(OFLAGS) -L. tet.a -o test
	./test

gcov_report: test
	lcov -t "./gcov" -o gcov.info --no-external -c -d .
	genhtml -o gcov gcov.info
	open ./gcov/index.html

	
clean:
	rm -rf ./out/*.o tetris tet.a test *.gcno *.gcda *.info ./gcov

clang:
	clang-format -n brick_game/tetris/*.c brick_game/tetris/*.h
	clang-format -n gui/cli/*.c gui/cli/*.h

dvi:
	open ../README.md

dist:
	mkdir dist/
	mkdir dist/src/
	cp -r Makefile brick_game/ gui/ dist/src/
	tar cvzf ${HOME}/Desktop/dist.tgz dist/
	rm -rf dist*

rebuild: clean all