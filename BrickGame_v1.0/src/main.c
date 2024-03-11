#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGTH 20
#define MAX_WIDTH 10

typedef struct {
  int x_start;
  int y_start;
  int move_x;
  int move_y;
} position_t;

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_piece(position_t *coordinat, char currentPiece[4][4]);

int main() {
  char currentPiece[4][4] = {0};
  char currentPieceColor = 0;

  char pieces[7][4][4] = {{{'0', '0', '0', '0'},
                           {'#', '#', '#', '#'},
                           {'0', '0', '0', '0'},
                           {'0', '0', '0', '0'}},

                          {{'0', '0', '0', '0'},
                           {'#', '#', '0', '0'},
                           {'#', '#', '0', '0'},
                           {'0', '0', '0', '0'}},

                          {{'0', '0', '0', '0'},
                           {'0', '#', '#', '0'},
                           {'#', '#', '0', '0'},
                           {'0', '0', '0', '0'}},

                          {{'0', '0', '0', '0'},
                           {'#', '#', '#', '0'},
                           {'0', '#', '0', '0'},
                           {'0', '0', '0', '0'}},

                          {{'0', '0', '0', '0'},
                           {'#', '#', '0', '0'},
                           {'0', '#', '#', '0'},
                           {'0', '0', '0', '0'}},

                          {{'0', '0', '0', '0'},
                           {'0', '0', '#', '0'},
                           {'#', '#', '#', '0'},
                           {'0', '0', '0', '0'}},

                          {{'0', '0', '0', '0'},
                           {'#', '0', '0', '0'},
                           {'#', '#', '#', '0'},
                           {'0', '0', '0', '0'}}};

  srand(time(NULL));
  currentPieceColor = 0; // rand() % 7;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      currentPiece[i][j] = pieces[currentPieceColor][i][j];
    }
  }

  initscr();
  curs_set(0);
  keypad(stdscr, true);
  int flag_exit = 0;

  position_t coordinat;
  coordinat.x_start = 3;
  coordinat.y_start = 0;
  coordinat.move_x = 0;
  coordinat.move_y = 0;
  int speed = 10;

  while (true) {
    halfdelay(speed);
    print_rectangle(0, MAX_HEIGTH, 0, MAX_WIDTH);
    print_rectangle(0, 2, 11, 22);
    print_rectangle(3, 5, 11, 22);
    print_rectangle(6, 8, 11, 22);
    print_rectangle(9, 11, 11, 22);
    mvprintw(1, 13, "SCORE");
    mvprintw(4, 13, "REMOVED");
    mvprintw(7, 13, "LEVEL");
    mvprintw(10, 13, "NEXT");
    refresh();

    print_piece(&coordinat, currentPiece);

    if (coordinat.move_y > 19) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printw("%c",currentPiece[i][j]);
          ..mvaddch(19, 3, currentPiece[i][j]);
        }
      }
    }

    printw("y = %d x = %d", coordinat.move_y, coordinat.move_x);
    switch (getch()) {
      case KEY_LEFT:
        if (coordinat.x_start != 1) {
          coordinat.x_start--;
        }
        break;
      case KEY_RIGHT:
        if (currentPieceColor == 1) {
          if (coordinat.x_start + coordinat.move_x - 2 != 10) {
            coordinat.x_start++;
          }
        } else if (currentPieceColor == 0) {
          if (coordinat.x_start + coordinat.move_x != 10) {
            coordinat.x_start++;
          }
        } else {
          if (coordinat.x_start + coordinat.move_x - 1 != 10) {
            coordinat.x_start++;
          }
        }
        break;
      case KEY_DOWN:
        speed = 1;
        break;
      case 'q':
        flag_exit = 1;
        break;
    }

    if (flag_exit) {
      break;
    }
    clear();
  }

  endwin();  // завершение работы с ncurses
}

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

void print_piece(position_t *coordinat, char currentPiece[4][4]) {
  for (int i = 0; i < 4; i++) {
    coordinat->move_x = 0;
    for (int j = 0; j < 4; j++) {
      if (currentPiece[i][j] != '0' && (j != 3 || j != 0)) {
        mvaddch(coordinat->y_start + coordinat->move_y,
                coordinat->x_start + coordinat->move_x, currentPiece[i][j]);
      }
      coordinat->move_x++;
    }
    coordinat->y_start++;
  }
  coordinat->y_start = 0;
  coordinat->move_y++;
}