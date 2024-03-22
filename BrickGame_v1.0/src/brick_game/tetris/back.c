#include "../../gui/cli/front.h"
#include "tetris.h"

tetgame_t *create_tet_game(int width, int heigth, int figure_size, int count,
                           tetblock *figure) {
  tetgame_t *tet_g = (tetgame_t *)calloc(1, sizeof(tetgame_t));
  tet_g->field = create_tet_field(width, heigth);
  tet_g->figurest = create_tet_figurest(count, figure_size, figure);
  tet_g->ticks = TICKS_START;
  tet_g->ticks_left = TICKS_START;
  tet_g->score = 0;
  tet_g->play = PLAYING;
  return tet_g;
}

tetfield *create_tet_field(int width, int heigth) {
  tetfield *tet_f = (tetfield *)calloc(1, sizeof(tetfield));
  tet_f->width = width;
  tet_f->heigth = heigth;
  tet_f->blocks = (tetblock *)calloc(1 * width * heigth, sizeof(tetblock));
  for (int i = 0; i < width * heigth; i++) {
    tet_f->blocks[i].b = 0;
  }
  return tet_f;
}

tetfigures_t *create_tet_figurest(int count, int figure_size,
                                  tetblock *figure) {
  tetfigures_t *tet_f_t = (tetfigures_t *)calloc(16, sizeof(tetfigures_t));
  tet_f_t->count = count;
  tet_f_t->size = figure_size;
  tet_f_t->blocks = figure;
  return tet_f_t;
}

void free_tet_figures_t(tetfigures_t *tet_f_t) {
  if (tet_f_t) {
    free(tet_f_t);
  }
}

void free_tet_field(tetfield *tet_f) {
  if (tet_f) {
    if (tet_f->blocks) {
      free(tet_f->blocks);
    }
    free(tet_f);
  }
}

void free_tet_game(tetgame_t *tet_g) {
  if (tet_g) {
    free_tet_field(tet_g->field);
    free_tet_figures_t(tet_g->figurest);
    free_tet_figures(tet_g->figure);
    free(tet_g);
  }
}

void move_figure(tetgame_t *tet_g) { tet_g->figure->y++; }
void move_figure_begin(tetgame_t *tet_g) { tet_g->figure->y--; }
void move_left(tetgame_t *tet_g) { tet_g->figure->x--; }
void move_right(tetgame_t *tet_g) { tet_g->figure->x++; }

int collision(tetgame_t *tet_g) {
  int res = 0;
  tetfigures *t = tet_g->figure;
  tetfield *t_f = tet_g->field;
  for (int i = 0; i < t->size; i++) {
    for (int j = 0; j < t->size; j++) {
      if (t->blocks[i * t->size + j].b != 0) {
        int fy = t->y + i;
        int fx = t->x + j;
        if (fx < 1 || fx >= t_f->width || fy < 0 || fy >= t_f->heigth) {
          res = 1;
        } else if (t_f->blocks[fy * t_f->width + fx].b != 0) {
          res = 1;
        }
      }
    }
  }
  return res;
}

void print_figure(tetgame_t *tet_g) {
  tetfigures *t = tet_g->figure;
  for (int i = 0; i < t->size; i++) {
    for (int j = 0; j < t->size; j++) {
      if (t->blocks[i * t->size + j].b != 0) {
        int fy = t->y + i;
        int fx = t->x + j;
        tet_g->field->blocks[fy * tet_g->field->width + fx].b =
            t->blocks[i * t->size + j].b;
      }
    }
  }
}

int clean_line(tetgame_t *tet_g) {
  tetfield *cl = tet_g->field;
  int count = 0;
  for (int i = cl->heigth - 1; i >= 0; i--) {
    while (line_fill(i, cl)) {
      line_drop(i, cl);
      count++;
    }
  }
  return count;
}

int line_fill(int i, tetfield *cl) {
  for (int j = 1; j < cl->width; j++) {
    if (cl->blocks[i * cl->width + j].b == 0) {
      return 0;
    }
  }
  return 1;
}

void line_drop(int i, tetfield *cl) {
  if (i == 0) {
    for (int j = 0; j < cl->width; j++) {
      cl->blocks[j].b = 0;
    }
  } else {
    for (int k = i; k > 0; k--) {
      for (int j = 0; j < cl->width; j++) {
        cl->blocks[k * cl->width + j].b = cl->blocks[(k - 1) * cl->width + j].b;
      }
    }
  }
}

tetfigures *create_tet_figures(tetgame_t *tet_g) {
  tetfigures *t = (tetfigures *)calloc(1, sizeof(tetfigures));
  t->x = 0;
  t->y = 0;
  t->size = tet_g->figurest->size;
  t->blocks = (tetblock *)calloc(t->size * t->size, (sizeof(tetblock)));
  return t;
}

void free_tet_figures(tetfigures *tf) {
  if (tf) {
    if (tf->blocks) {
      free(tf->blocks);
    }
    free(tf);
  }
}

void drop_new_figure(tetgame_t *tet_g) {
  tetfigures *t = create_tet_figures(tet_g);
  t->x = 4;
  t->y = 0;
  int f_num = rand() % tet_g->figurest->count;
  for (int i = 0; i < t->size; i++) {
    for (int j = 0; j < t->size; j++) {
      t->blocks[i * t->size + j].b =
          tet_g->figurest->blocks[f_num * t->size * t->size + i * t->size + j]
              .b;
    }
  }
  free_tet_figures(tet_g->figure);
  tet_g->figure = t;
}

tetfigures *rotate_figure(tetgame_t *tet_g) {
  tetfigures *t = create_tet_figures(tet_g);
  tetfigures *t_old = tet_g->figure;
  t->y = t_old->y;
  t->x = t_old->x;
  for (int i = 0; i < t->size; i++) {
    for (int j = 0; j < t->size; j++) {
      t->blocks[i * t->size + j].b =
          t_old->blocks[j * t->size + t->size - 1 - i].b;
    }
  }
  return t;
}

void calculate_tet(tetgame_t *tet_g) {  // один цикл

  if (tet_g->ticks_left <= 0) {
    tet_g->ticks_left = tet_g->ticks;
    move_figure(tet_g);
    if (collision(tet_g)) {
      move_figure_begin(tet_g);
      print_figure(tet_g);
      int check_score = clean_line(tet_g);
      if (check_score == 1) {
        tet_g->score += 100;
      } else if (check_score == 2) {
        tet_g->score += 300;
      } else if (check_score == 3) {
        tet_g->score += 700;
      } else if (check_score == 4) {
        tet_g->score += 1500;
      }
      drop_new_figure(tet_g);
      if (collision(tet_g)) {
        tet_g->play = GAMEOVER;
        get_high_score(tet_g);
        return;
      }
      tet_g->ticks = TICKS_START;
    }
  }

  switch (tet_g->player->action) {
    case PLAYER_RIGHT:
      move_right(tet_g);
      if (collision(tet_g)) {
        move_left(tet_g);
      }
      break;

    case PLAYER_LEFT:
      move_left(tet_g);
      if (collision(tet_g)) {
        move_right(tet_g);
      }
      break;

    case PLAYER_UP: {
      tetfigures *t = rotate_figure(tet_g);
      tetfigures *t_old = tet_g->figure;
      tet_g->figure = t;
      if (collision(tet_g)) {
        tet_g->figure = t_old;
        free_tet_figures(t);
      } else {
        free_tet_figures(t_old);
      }
    } break;
    case PLAYER_NOP:
    default:
      break;
  }
  tet_g->ticks_left--;
}

long int s21_atoi(const char *str) {
  long int res = 0;
  while (*str <= '9' && *str >= '0') {
    res = 10 * res + *str - '0';
    str++;
  }
  return res;
}

char free_buf(char *buf) {
  int len = strlen(buf);
  for (int i = len; i > 0; i--) {
    buf[i] = '\0';
  }
  return *buf;
}

void get_high_score(tetgame_t *tet_g) {
  FILE *fp_read = fopen("score.txt", "r");
  if (fp_read == NULL) {
    printf("error\n");
  } else {
    int current = 0;
    char *mas_char = (char *)calloc(10, sizeof(char));
    int mas_number[100];

    int i = 0;
    int j = 0;

    while ((current = fgetc(fp_read)) != EOF) {
      if (current <= '9' && current >= '0') {
        mas_char[i] = current;
        i++;
      } else {
        mas_number[j] = s21_atoi(mas_char);
        j++;
        i = 0;
        if (strlen(mas_char) != 0) {
          free_buf(mas_char);
        }
      }
    }
    fclose(fp_read);
    mas_number[j++] = tet_g->score;

    for (i = 0; i < j - 1; i++) {
      for (int k = 0; k < j - i - 1; k++) {
        if (mas_number[k] < mas_number[k + 1]) {
          int tmp = mas_number[k];
          mas_number[k] = mas_number[k + 1];
          mas_number[k + 1] = tmp;
        }
      }
    }
    FILE *fp_write = fopen("score.txt", "w");

    for (int j = 0; j < 10; j++) {
      fprintf(fp_write, "%d\n", mas_number[j]);
      mvprintw(j + 2, 27, "%d", mas_number[j]);
    }

    free(mas_char);
    fclose(fp_write);
  }
}