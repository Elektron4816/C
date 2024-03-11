#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20
#define EMPTY 0
#define FULL 1
#define BLOCK 2

// Определение форм и цветов фигур
int shapes[7][4][4] = {
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}},  // I
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},  // O
    {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},  // T
    {{0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},  // L
    {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},  // J
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},  // S
    {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}   // Z
};

int colors[7] = {9,  14, 13, 12,
                 10, 11, 15};  // Синий, желтый, фиолетовый, красный, зеленый,
                               // бирюзовый, белый

// Определение структуры фигуры
typedef struct {
  int x;  // Координата x левого верхнего угла фигуры
  int y;  // Координата y левого верхнего угла фигуры
  int shape;     // Номер формы фигуры
  int rotation;  // Номер поворота фигуры
} piece;

// Определение глобальных переменных
int board[HEIGHT][WIDTH];  // Двумерный массив, представляющий игровое поле
piece current;             // Текущая фигура
piece next;                // Следующая фигура
int score;                 // Счет игры
int speed;                 // Скорость падения фигур
int gameover;              // Флаг окончания игры

// Объявление функций
void init();       // Инициализация игры
void draw();       // Отрисовка игры
void input();      // Обработка ввода с клавиатуры
void update();     // Обновление состояния игры
void new_piece();  // Создание новой фигуры
int collision(int x, int y, int shape,
              int rotation);  // Проверка на столкновение фигуры с границами или
                              // заполненными клетками
void merge();        // Слияние фигуры с игровым полем
void clear_lines();  // Очистка заполненных линий
void set_color(int color);  // Установка цвета текста
void gotoxy(int x, int y);  // Перемещение курсора в заданную позицию

// Главная функция
int main() {
  init();              // Инициализация игры
  while (!gameover) {  // Пока игра не закончилась
    draw();            // Отрисовка игры
    input();           // Обработка ввода с клавиатуры
    update();          // Обновление состояния игры
  }
  // Вывод сообщения об окончании игры и счета
  set_color(15);
  gotoxy(0, 23);
  printf("Game over!\n");
  printf("Your score: %d\n", score);
  return 0;
}

// Функция инициализации игры
void init() {
  // Установка начальных значений переменных
  srand(time(NULL));  // Инициализация генератора случайных чисел
  score = 0;    // Счет игры равен нулю
  speed = 500;  // Скорость падения фигур равна 500 мс
  gameover = 0;  // Флаг окончания игры равен 0 (ложь)
  // Очистка игрового поля
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      board[i][j] = EMPTY;
    }
  }
  // Создание первой и второй фигуры
  new_piece(&current);
  new_piece(&next);
}
// Функция отрисовки игры
void draw() {
  // Очистка экрана
  system("cls");
  // Вывод рамки игрового поля
  setcolor(7);
  for (int i = 0; i < HEIGHT + 2; i++) {
    gotoxy(0, i);
    printf("%c", i == 0 || i == HEIGHT + 1 ? 205 : 186);
    gotoxy(WIDTH + 1, i);
    printf("%c", i == 0 || i == HEIGHT + 1 ? 205 : 186);
  }
  gotoxy(0, 0);
  printf("%c", 201);
  gotoxy(0, HEIGHT + 1);
  printf("%c", 200);
  gotoxy(WIDTH + 1, 0);
  printf("%c", 187);
  gotoxy(WIDTH + 1, HEIGHT + 1);
  printf("%c", 188);
  // Вывод заполненных клеток игрового поля
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (board[i][j] == FULL) {
        setcolor(boardij + WIDTH);
        gotoxy(j + 1, i + 1);
        printf("%c", 219);
      }
    }
  }
  // Вывод текущей фигуры
  setcolor(colors[current.shape]);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (shapes[current.shape][current.rotation][i * 4 + j]) {
        gotoxy(current.x + j + 1, current.y + i + 1);
        printf("%c", 219);
      }
    }
  }
  // Вывод следующей фигуры
  setcolor(7);
  gotoxy(WIDTH + 3, 2);
  printf("Next:");
  setcolor(colors[next.shape]);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      gotoxy(WIDTH + 5 + j, 4 + i);
      printf("%c", shapes[next.shape][next.rotation][i * 4 + j] ? 219 : 32);
    }
  }
  // Вывод счета игры
  setcolor(7);
  gotoxy(WIDTH + 3, 10);
  printf("Score: %d", score);
  // Вывод скорости игры
  gotoxy(WIDTH + 3, 12);
  printf("Speed: %d", speed);
}

// Функция обработки ввода с клавиатуры
void input() {
  // Если нажата какая-либо клавиша
  if (kbhit()) {
    // Получение кода нажатой клавиши
    int key = getch();
    // Обработка нажатой клавиши
    switch (key) {
      case 72:  // Стрелка вверх
        // Поворот фигуры по часовой стрелке, если это возможно
        if (!collision(current.x, current.y, current.shape,
                       (current.rotation + 1) % 4)) {
          current.rotation = (current.rotation + 1) % 4;
        }
        break;
      case 80:  // Стрелка вниз
        // Ускорение падения фигуры, если это возможно
        if (!collision(current.x, current.y + 1, current.shape,
                       current.rotation)) {
          current.y++;
        }
        break;
      case 75:  // Стрелка влево
        // Сдвиг фигуры влево, если это возможно
        if (!collision(current.x - 1, current.y, current.shape,
                       current.rotation)) {
          current.x--;
        }
        break;
      case 77:  // Стрелка вправо
        // Сдвиг фигуры вправо, если это возможно
        if (!collision(current.x + 1, current.y, current.shape,
                       current.rotation)) {
          current.x++;
        }
        break;
      case 32:  // Пробел
        // Падение фигуры до конца, если это возможно
        while (!collision(current.x, current.y + 1, current.shape,
                          current.rotation)) {
          current.y++;
        }
        break;
      case 27:  // Esc
        // Выход из игры
        gameover = 1;
        break;
    }
  }
}

// Функция обновления состояния игры
void update() {
  // Создание статической переменной для хранения времени последнего обновления
  static int last_time = 0;
  // Получение текущего времени в миллисекундах
  int current_time = clock();
  // Если прошло достаточно времени с последнего обновления
  if (current_time - last_time > speed) {
    // Обновление времени последнего обновления
    last_time = current_time;
    // Попытка сдвинуть фигуру вниз
    if (!collision(current.x, current.y + 1, current.shape, current.rotation)) {
      // Если это возможно, то увеличение координаты y фигуры
      current.y++;
    } else {
      // Если это невозможно, то слияние фигуры с игровым полем
      merge();
      // Очистка заполненных линий
      clear_lines();
      // Создание новой фигуры
      new_piece(&current);
      // Копирование следующей фигуры в текущую
      current = next;
      // Создание новой следующей фигуры
      new_piece(&next);
      // Проверка на окончание игры
      if (collision(current.x, current.y, current.shape, current.rotation)) {
        // Если текущая фигура не может двигаться, то установка флага окончания
        // игры в 1 (истина)
        gameover = 1;
      }
    }
  }
}

// Функция создания новой фигуры
void new_piece(piece *p) {
  // Случайным образом выбираем форму и поворот фигуры
  p->shape = rand() % 7;
  p->rotation = rand() % 4;
  // Устанавливаем координаты фигуры в центре верхней части игрового поля
  p->x = WIDTH / 2 - 2;
  p->y = 0;
}

// Функция проверки на столкновение фигуры с границами или заполненными клетками
int collision(int x, int y, int shape, int rotation) {
  // Проходим по всем клеткам фигуры
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // Если клетка фигуры не пустая
      if (shapes[shape][rotation][i * 4 + j]) {
        // Проверяем, не выходит ли она за границы игрового поля
        if (x + j < 0 || x + j >= WIDTH || y + i >= HEIGHT) {
          // Если выходит, то возвращаем 1 (истина)
          return 1;
        }
        // Проверяем, не пересекается ли она с заполненной клеткой игрового поля
        if (board[y + i][x + j] == FULL) {
          // Если пересекается, то возвращаем 1 (истина)
          return 1;
        }
      }
    }
  }
  // Если ни одна из проверок не сработала, то возвращаем 0 (ложь)
  return 0;
}