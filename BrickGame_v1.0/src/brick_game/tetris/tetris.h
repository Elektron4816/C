#ifndef _TETRIS_H_
#define _TETRIS_H_

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TICKS_START 20
#define MAX_HEIGTH 20
#define MAX_WIDTH 11

#define WIN_INIT            \
  {                         \
    initscr();              \
    cbreak();               \
    noecho();               \
    curs_set(0);            \
    nodelay(stdscr, TRUE);  \
    scrollok(stdscr, TRUE); \
    keypad(stdscr, TRUE);   \
  }

enum { PLAYER_NOP = 0, PLAYER_UP, PLAYER_LEFT, PLAYER_RIGHT };

enum { GAMEOVER = 0, PLAYING };

typedef struct tetplayer {
  int action;
} tetplayer;

typedef struct tetblock {
  int b;
} tetblock;  // есть ли блок на поле

typedef struct tetfield {  // структура поля
  int width;
  int heigth;
  tetblock *blocks;  // массив из блоков
} tetfield;

typedef struct tetfigures {  // фигура
  int x;
  int y;
  int size;
  tetblock *blocks;
} tetfigures;

typedef struct tetfigures_t {  // повороты фигур
  int count;
  int size;
  tetblock *blocks;
} tetfigures_t;

typedef struct tetgame_t {
  tetfield *field;
  tetfigures *figure;
  tetfigures_t *figurest;
  tetplayer *player;
  int play;
  int ticks;
  int ticks_left;
  int score;
} tetgame_t;

tetgame_t *create_tet_game(int width, int heigth, int figure_size, int count,
                           tetblock *figure);
tetfield *create_tet_field(int width, int heigth);
tetfigures_t *create_tet_figurest(int count, int figure_size, tetblock *figure);
tetfigures *create_tet_figures(tetgame_t *tet_g);
tetfigures *rotate_figure(tetgame_t *tet_g);

void free_tet_figures_t(tetfigures_t *tet_f_t);
void free_tet_field(tetfield *tet_f);
void free_tet_game(tetgame_t *tet_g);
void free_tet_figures(tetfigures *tf);

void move_figure(tetgame_t *tet_g);
void move_figure_begin(tetgame_t *tet_g);
void move_left(tetgame_t *tet_g);
void move_right(tetgame_t *tet_g);

int collision(tetgame_t *tet_g);
void print_figure(tetgame_t *tet_g);
int clean_line(tetgame_t *tet_g);
int line_fill(int i, tetfield *cl);
void line_drop(int i, tetfield *cl);
void drop_new_figure(tetgame_t *tet_g);
void calculate_tet(tetgame_t *tet_g);

char free_buf(char *buf);
long int s21_atoi(const char *str);
void get_high_score(tetgame_t *tet_g);

#endif  // _TETRIS_H_
