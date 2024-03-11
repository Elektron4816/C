#include <check.h>

#include "s21_matrix.h"

START_TEST(s21_create) {
  matrix_t A;
  int result = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  matrix_t B;
  int result2 = s21_create_matrix(3, 0, &B);
  ck_assert_int_eq(result2, 1);

  matrix_t C;
  int result3 = s21_create_matrix(2, 2, &C);
  ck_assert_int_eq(result3, 0);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_eq) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int result_1 = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result_1, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 0, &B);
  int result_0 = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 2;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 8;
  B.matrix[1][1] = 4;

  int result_0_0 = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result_0_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int result_0 = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 0, &B);
  int result_1 = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(result_1, 1);
  s21_remove_matrix(&A);

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(2, 5, &B);
  int result_2 = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(result_2, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int result = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 0, &B);
  int result_1 = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result_1, 1);
  s21_remove_matrix(&A);

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(2, 5, &B);
  int result_2 = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result_2, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_NUM) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  int result_0 = s21_mult_number(&A, 3.0, &B);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(4, 0, &A);
  int result_1 = s21_mult_number(&A, 4.3, &B);
  ck_assert_int_eq(result_1, 1);
}
END_TEST

START_TEST(s21_mult_MAT) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int result_0 = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  s21_create_matrix(0, 3, &A);
  s21_create_matrix(3, 3, &B);
  int result_1 = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result_1, 1);
  s21_remove_matrix(&B);

  s21_create_matrix(3, 5, &A);
  s21_create_matrix(3, 3, &B);
  int result_2 = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result_2, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_trans) {
  matrix_t A, B, C;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  int result_0 = s21_transpose(&A, &C);
  ck_assert_int_eq(result_0, 0);
  int result_trans_1 = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(result_trans_1, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  s21_create_matrix(3, 0, &A);
  int result_1 = s21_transpose(&A, &C);
  ck_assert_int_eq(result_1, 1);
}
END_TEST

START_TEST(s21_det) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  double det = 0.0;
  int result_0 = s21_determinant(&A, &det);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);

  s21_create_matrix(1, 1, &A);
  det = 0.0;
  int result_0_0 = s21_determinant(&A, &det);
  ck_assert_int_eq(result_0_0, 0);
  s21_remove_matrix(&A);

  s21_create_matrix(3, 0, &A);
  det = 0.0;
  int result_1 = s21_determinant(&A, &det);
  ck_assert_int_eq(result_1, 1);

  s21_create_matrix(3, 2, &A);
  det = 0.0;
  int result_2 = s21_determinant(&A, &det);
  ck_assert_int_eq(result_2, 2);
  s21_remove_matrix(&A);

  s21_create_matrix(4, 4, &A);
  det = 0.0;

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 7;

  A.matrix[2][0] = 8;
  A.matrix[2][1] = 9;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 10;

  A.matrix[3][0] = 11;
  A.matrix[3][1] = 12;
  A.matrix[3][2] = 13;
  A.matrix[3][3] = 14;

  int result_0_3 = s21_determinant(&A, &det);
  ck_assert_int_eq(result_0_3, 0);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);

  double res = 0.0;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_determinant(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(res, -2);
}
END_TEST

START_TEST(s21_calc) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  int result_0 = s21_calc_complements(&A, &C);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);

  s21_create_matrix(3, 0, &A);
  int result_1 = s21_calc_complements(&A, &C);
  ck_assert_int_eq(result_1, 1);

  s21_create_matrix(3, 2, &A);
  int result_2 = s21_calc_complements(&A, &C);
  ck_assert_int_eq(result_2, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_invers) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = 2;
  int result_0 = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(result_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  int result_0_0 = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(result_0_0, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);

  s21_create_matrix(3, 0, &A);
  int result_1 = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(result_1, 1);

  s21_create_matrix(3, 2, &A);
  int result_2 = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(result_2, 2);
  s21_remove_matrix(&A);

  s21_create_matrix(3, 3, &A);
  int result_2_2 = s21_inverse_matrix(&A, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(result_2_2, 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_matrix_suite_create(void) {
  Suite *s21_matrix = suite_create("s21_matrix");
  TCase *s21_matrix_test = tcase_create("s21_matrix_test");

  tcase_add_test(s21_matrix_test, s21_create);
  tcase_add_test(s21_matrix_test, s21_eq);
  tcase_add_test(s21_matrix_test, s21_sum);
  tcase_add_test(s21_matrix_test, s21_sub);
  tcase_add_test(s21_matrix_test, s21_mult_NUM);
  tcase_add_test(s21_matrix_test, s21_mult_MAT);
  tcase_add_test(s21_matrix_test, s21_trans);
  tcase_add_test(s21_matrix_test, s21_det);
  tcase_add_test(s21_matrix_test, s21_calc);
  tcase_add_test(s21_matrix_test, s21_invers);

  suite_add_tcase(s21_matrix, s21_matrix_test);

  return s21_matrix;
}

int main() {
  Suite *s21_matrix = s21_matrix_suite_create();
  SRunner *s21_matrix_suite_runner = srunner_create(s21_matrix);
  int failed_cnt;
  srunner_run_all(s21_matrix_suite_runner, CK_NORMAL);
  failed_cnt = srunner_ntests_failed(s21_matrix_suite_runner);
  srunner_free(s21_matrix_suite_runner);

  if (failed_cnt != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
