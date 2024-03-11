#ifndef _CALC_H_
#define _CALC_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack

typedef struct {
  long double *values;
  int length;
  int capacity;
} Stack;

Stack create_stack();
void push_stack(Stack *s, long double value);
long double stack_pop(Stack *s);
void free_stack(Stack *s);
void print_stack(Stack *s);

// main fucn

typedef struct {
  // int flag_40;
  // int flag_41;
  int flag_result;
  int flag_num;
  int flag_cos;
  int flag_trig_func;
  int flag_no_error;
  int flag_from_negative_degree;
} Flag;

long int s21_atoi(const char *str);
void calculation(Stack *s, Stack *ch, Flag *flag, int **return_num_err);
char free_buf(char *buf);
long double s21_atof(char *str);
int check_valid(int first, int next);
int find_trig_func(int input_char, char *input_string,
                   int count_from_string_buf, Flag *flag);
double main_func(char *input_string, double x, int *return_num_err);
int priority_low(Stack *sign);
int priority_gran(Stack *sign);
void parser(int input_char, Stack *numbers, Stack *sign, Flag *flag,
            int *return_num_err);
int check_unary(int input_char, char *input_string, int swap_count,
                int *count_from_string_buf, Stack *numbers, Stack *sign,
                Flag *flag, int **return_num_err);

#endif  // _CALC_H_
