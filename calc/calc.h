#ifndef _CALC_H_
#define _CALC_H_

#include "stack.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  // int flag_40;
  // int flag_41;
  int flag_result;
  int flag_num;
  int flag_cos;
  int flag_trig_func;
  int flag_no_error;
} Flag;

long int s21_atoi(const char *str);
void calculation(Stack *s, Stack *ch, Flag *flag);
char free_buf(char *buf);
long double s21_atof(char *str);
int check_valid(int first, int next);
int find_trig_func(int input_char, char *input_string,
                   int count_from_string_buf, Flag *flag);
double main_func(char *input_string, double x);
int priority_low(Stack *sign);
int priority_gran(Stack *sign);
void parser(int input_char, Stack *numbers, Stack *sign, Flag *flag);
int check_unary(int input_char, char *input_string, int swap_count,
         int *count_from_string_buf, Stack *numbers, Stack *sign, Flag *flag);

#endif // _CALC_H_
