#include "../../gui/cli/front.h"
#include "tetris.h"

int main() {
  tetblock template[] = {
      {0}, {1}, {0}, {0}, {0}, {1}, {0}, {0},
      {0}, {1}, {0}, {0}, {0}, {1}, {0}, {0},

      {0}, {0}, {0}, {0}, {0}, {1}, {1}, {0},
      {0}, {1}, {1}, {0}, {0}, {0}, {0}, {0},

      {0}, {0}, {0}, {0}, {0}, {1}, {1}, {0},
      {1}, {1}, {0}, {0}, {0}, {0}, {0}, {0},

      {0}, {0}, {0}, {0}, {1}, {1}, {1}, {0},
      {0}, {1}, {0}, {0}, {0}, {0}, {0}, {0},

      {0}, {0}, {0}, {0}, {1}, {1}, {0}, {0},
      {0}, {1}, {1}, {0}, {0}, {0}, {0}, {0},

      {0}, {0}, {0}, {0}, {0}, {0}, {1}, {0},
      {1}, {1}, {1}, {0}, {0}, {0}, {0}, {0},

      {0}, {0}, {0}, {0}, {1}, {0}, {0}, {0},
      {1}, {1}, {1}, {0}, {0}, {0}, {0}, {0},
  };

  WIN_INIT;

  tetgame_t *tet_g = create_tet_game(MAX_WIDTH, MAX_HEIGTH, 4, 7, template);
  tetplayer player;

  player.action = PLAYER_NOP;
  tet_g->player = &player;

  drop_new_figure(tet_g);
  print_field();
  get_high_score(tet_g);

  srand(time(NULL));

  int speed = 40;
  int count_lvl = 1;

  while (tet_g->play != GAMEOVER) {
    napms(speed);

    switch (getch()) {
      case KEY_UP:
        player.action = PLAYER_UP;
        break;

      case KEY_DOWN:
        tet_g->ticks = 1;
        break;

      case KEY_LEFT:
        player.action = PLAYER_LEFT;
        break;

      case KEY_RIGHT:
        player.action = PLAYER_RIGHT;
        break;

      case 'q':
        tet_g->play = GAMEOVER;
        get_high_score(tet_g);
        break;

      case 'p':
        player.action = PLAYER_NOP;
        break;

      default:
        player.action = PLAYER_NOP;
        break;
    }
    calculate_tet(tet_g);
    print_tet_game(tet_g);

    mvprintw(1, 20, "%d", tet_g->score);
    if ((tet_g->score >= 600 * count_lvl) && count_lvl < 10) {
      count_lvl++;
      if (speed > 4) {
        speed -= 4;
      }
    }
    mvprintw(4, 20, "%d", count_lvl);
  }

  clear();

  while (true) {
    if (getch() == 'q') {
      break;
    }
    if (tet_g->play == GAMEOVER) {
      print_end_box(tet_g);
    }
  }

  free_tet_game(tet_g);
  endwin();
  return 0;
}