#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20
#define EMPTY 0
#define FULL 1
#define BLOCK 2

int shapes[7][4][4] = {
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}},  // I
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},  // O
    {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},  // T
    {{0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},  // L
    {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},  // J
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},  // S
    {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}   // Z
};

// Определение структуры фигуры
typedef struct {
  int x;  // Координата x левого верхнего угла фигуры
  int y;  // Координата y левого верхнего угла фигуры
  int shape;     // Номер формы фигуры
  int rotation;  // Номер поворота фигуры
} piece;


// Функция создания новой фигуры
void new_piece(piece *p) {
  // Случайным образом выбираем форму и поворот фигуры
  p->shape = rand() % 7;
  p->rotation = rand() % 4;
  // Устанавливаем координаты фигуры в центре верхней части игрового поля
  p->x = WIDTH / 2 - 2;
  p->y = 0;
}


int main(){
    piece current;

    new_piece(&current);


    return 0;
}