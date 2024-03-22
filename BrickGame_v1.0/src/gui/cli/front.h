#ifndef _FRONT_H_
#define _FRONT_H_

#include "../../brick_game/tetris/tetris.h"

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_tet_game(tetgame_t *tet_g);
void print_field();
void print_end_box(tetgame_t *tet_g);

#endif  // _FRONT_H_