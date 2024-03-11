#ifndef _S21_MATRIX_H_
#define _S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1
#define CALCULATION_ERROR 2
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns,
                      matrix_t *result);  // создание матрицы
int check_true(matrix_t *any_matrix);  // проверка что матрица возможна
void s21_remove_matrix(matrix_t *A);          // очистка матрицы
int s21_eq_matrix(matrix_t *A, matrix_t *B);  // сравние матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // сложение
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // вычитание
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // умножение на число
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  // умножение двух матриц
int s21_transpose(matrix_t *A, matrix_t *result);  //// транспонирование
int s21_calc_complements(
    matrix_t *A,
    matrix_t *result);  // Минор матрицы и матрица алгебраических дополнений
int s21_determinant(matrix_t *A, double *result);  // определитель матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);  // обратная матрица

double calculate_determinant(matrix_t *A,
                             int size);  // вычисление детерминанта доп.
void calculate_minor(double **A, double **minor, int excluded_row,
                     int excluded_column, int size);  // минор матрицы
#endif                                                // _S21_MATRIX_H_
