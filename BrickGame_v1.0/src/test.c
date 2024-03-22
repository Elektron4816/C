#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "./brick_game/tetris/tetris.h"
#include "./gui/cli/front.h"

START_TEST(test_1) {
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

  tetgame_t *tet_g = create_tet_game(MAX_WIDTH, MAX_HEIGTH, 4, 7, template);
  tetplayer player;
  player.action = PLAYER_NOP;
  tet_g->player = &player;
  drop_new_figure(tet_g);
  print_field();
  while (tet_g->play != GAMEOVER) {
    switch (getch()) {
      default:
        player.action = PLAYER_NOP;
        break;
    }
    calculate_tet(tet_g);
    print_tet_game(tet_g);
  }
  print_end_box(tet_g);
  free_tet_game(tet_g);
}
END_TEST

Suite *tetris_suite_create(void) {
  Suite *tetris = suite_create("tetris");
  TCase *tetris_test = tcase_create("tetris_test");

  tcase_add_test(tetris_test, test_1);
  suite_add_tcase(tetris, tetris_test);
  return tetris;
}

int main() {
  Suite *tetris = tetris_suite_create();
  SRunner *tetris_suite_runner = srunner_create(tetris);
  int failed_cnt;
  srunner_run_all(tetris_suite_runner, CK_NORMAL);
  failed_cnt = srunner_ntests_failed(tetris_suite_runner);
  srunner_free(tetris_suite_runner);

  if (failed_cnt != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}