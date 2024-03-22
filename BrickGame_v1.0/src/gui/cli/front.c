#include "front.h"

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  mvaddch(top_y, left_x, ACS_ULCORNER);

  int i = left_x + 1;

  for (; i < right_x; i++) mvaddch(top_y, i, ACS_HLINE);
  mvaddch(top_y, i, ACS_URCORNER);

  for (int i = top_y + 1; i < bottom_y; i++) {
    mvaddch(i, left_x, ACS_VLINE);
    mvaddch(i, right_x, ACS_VLINE);
  }

  mvaddch(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) mvaddch(bottom_y, i, ACS_HLINE);
  mvaddch(bottom_y, i, ACS_LRCORNER);
}

void print_tet_game(tetgame_t *tet_g) {
  tetfield *tf = tet_g->field;
  tetfigures *t = tet_g->figure;
  for (int i = 1; i < tf->heigth; i++) {
    for (int j = 1; j < tf->width; j++) {
      char to_print = ' ';
      if (tf->blocks[i * tf->width + j].b != 0) {
        to_print = '#';
      } else {
        int x = j - t->x;
        int y = i - t->y;
        if (x >= 0 && x < t->size && y >= 0 && y < t->size) {
          if (t->blocks[y * t->size + x].b != 0) {
            to_print = '#';
          }
        }
      }
      mvaddch(i, j, to_print);
    }
  }
}

void print_field() {
  print_rectangle(0, MAX_HEIGTH, 0, MAX_WIDTH);
  print_rectangle(0, 2, 12, 25);
  print_rectangle(3, 5, 12, 25);
  print_rectangle(6, 12, 12, 25);
  print_rectangle(0, 12, 26, 37);
  mvprintw(1, 14, "SCORE:");
  mvprintw(4, 14, "LEVEL:");
  mvprintw(7, 17, "NEXT");
  mvprintw(1, 27, "HIGH SCORE");
}

void print_end_box(tetgame_t *tet_g) {
  int rows, cols;
  getmaxyx(stdscr, rows, cols);
  print_rectangle(rows / 2 - 1, rows / 2 + 3, cols / 2 - 6, cols / 2 + 6);
  mvprintw(rows / 2, cols / 2 - 4, "GAME OVER");
  mvprintw(rows / 2 + 1, cols / 2 - 5, "YOURE SCORE");
  mvprintw(rows / 2 + 2, cols / 2, "%d", tet_g->score);
}
