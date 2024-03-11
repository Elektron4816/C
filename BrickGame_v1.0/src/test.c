#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
int currentPiece[4][4] = {0};
int currentPieceColor = 0;
int currentX = 0, currentY = 0;

int pieces[7][4][4] = {
    {{0, 0, 0, 0},
     {1, 1, 1, 1}, 
     {0, 0, 0, 0}, 
     {0, 0, 0, 0}}, 

    {{0, 0, 0, 0}, 
     {0, 1, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}},

    {{0, 0, 0, 0}, 
     {0, 1, 1, 0}, 
     {1, 1, 0, 0},
     {0, 0, 0, 0}},

    {{0, 0, 0, 0},
     {1, 1, 1, 0},
     {0, 1, 0, 0}, 
     {0, 0, 0, 0}},

    {{0, 0, 0, 0}, 
     {1, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}},

    {{0, 0, 0, 0}, 
     {0, 0, 0, 0}, 
     {1, 1, 1, 0},
     {0, 0, 0, 0}},

    {{0, 0, 0, 0},
     {1, 0, 0, 0},    
     {1, 1, 1, 0},
     {0, 0, 0, 0}}};

void init() {
  srand(time(NULL));
  currentPieceColor = rand() % 7;
  currentX = BOARD_WIDTH / 2 - 2;
  currentY = 0;

  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      currentPiece[i][j] = pieces[currentPieceColor][i][j];
    }
  }
}

void draw() {
  refresh();
  printf("\n   ====[ TETRIS ]====\n\n");

  int i, j;
  for (i = 0; i < BOARD_HEIGHT; i++) {
    printf("   ");
    for (j = 0; j < BOARD_WIDTH; j++) {
      if (board[i][j] == 0)
        printf(". ");
      else
        printf("# ");
    }
    printf("\n");
  }
}

int checkCollision(int x, int y) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (currentPiece[i][j] && (board[y + i][x + j] || x + j < 0 ||
                                 x + j >= BOARD_WIDTH || y + i >= BOARD_HEIGHT))
        return 1;
    }
  }
  return 0;
}

void merge() {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (currentPiece[i][j]) board[currentY + i][currentX + j] = 1;
    }
  }
}

void handleInput() {
  // if (_kbhit()) {
  int key = getch();
  switch (key) {
    case 'a':
      if (!checkCollision(currentX - 1, currentY)) currentX--;
      break;

    case 'd':
      if (!checkCollision(currentX + 1, currentY)) currentX++;
      break;

    case 's':
      if (!checkCollision(currentX, currentY + 1)) currentY++;
      break;

    case 'q':
      exit(0);
      break;
  }
  // }
}

void update() {
  if (!checkCollision(currentX, currentY + 1)) {
    currentY++;
  } else {
    merge();
    init();
  }
}

int main() {
    initscr();
  init();

  while (1) {
    draw();
    // handleInput();
    update();
  }
    endwin();
  return 0;
}