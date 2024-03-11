#include "calc.h"

// stack

Stack create_stack() {
  Stack s = {
      .values = NULL,
      .length = 0,
      .capacity = 0,
  };
  return s;
}

void push_stack(Stack *s, long double value) {
  if (s->values == NULL || s->length == s->capacity) {
    s->capacity = (s->capacity + 1) * 2;
    s->values =
        (long double *)realloc(s->values, sizeof(long double) * s->capacity);
  }
  s->values[s->length] = value;
  s->length += 1;
}

long double stack_pop(Stack *s) {
  if (s->length == 0) {
    return INT_MIN;
  }
  s->length -= 1;
  return s->values[s->length];
}

void free_stack(Stack *s) {
  if (s->values != NULL) {
    free(s->values);
  }
  s->length = 0;
  s->capacity = 0;
}

// void print_stack(Stack *s) {
//   for (int i = 0; i < s->length; i++) {
//     printf("[%.6Lf]", s->values[i]);
//   }
//   printf("\n");
// }

// main func

char free_buf(char *buf) {
  int len = strlen(buf);
  for (int i = len; i > 0; i--) {
    buf[i] = '\0';
  }
  return *buf;
}

long int s21_atoi(const char *str) {
  long int res = 0;
  while (*str <= '9' && *str >= '0') {
    res = 10 * res + *str - '0';
    str++;
  }
  return res;
}

long double s21_atof(char *str) {
  long double int_part = s21_atoi(str);
  long double float_part = 0;
  int float_part_length = 0;

  for (size_t i = 0; i < strlen(str); i++) {
    if (*str == '.') {
      str++;
      while (*str <= '9' && *str >= '0') {
        float_part = 10 * float_part + (*str - '0');
        float_part_length++;
        str++;
      }
    }
    str++;
  }
  return int_part + float_part / pow(10, float_part_length);
}

void calculation(Stack *numbers, Stack *sign, Flag *flag,
                 int **return_num_err) {
  long double a = 0;
  long double b = 0;
  int test_sign = 0;
  long double result = 0;
  test_sign = stack_pop(sign);

  switch (test_sign) {
    case '+':
      b = stack_pop(numbers);
      a = stack_pop(numbers);
      result = a + b;
      push_stack(numbers, result);
      break;

    case '-':
      b = stack_pop(numbers);
      a = stack_pop(numbers);
      result = a - b;
      push_stack(numbers, result);
      break;

    case '*':
      b = stack_pop(numbers);
      a = stack_pop(numbers);
      result = a * b;
      push_stack(numbers, result);
      break;

    case '/':
      b = stack_pop(numbers);
      a = stack_pop(numbers);

      if (b != 0) {
        result = a / b;
        push_stack(numbers, result);
      } else {
        flag->flag_no_error = 0;
        **return_num_err = 0;
      }
      break;

    case '^':
      b = stack_pop(numbers);
      a = stack_pop(numbers);
      if (flag->flag_from_negative_degree == 0) {
        b *= -1;
        flag->flag_from_negative_degree = 1;
      }
      result = pow(a, b);
      push_stack(numbers, result);
      break;

    case 'A':
      b = stack_pop(numbers);
      result = sin(b);
      push_stack(numbers, result);
      break;

    case 'B':
      b = stack_pop(numbers);
      result = cos(b);
      push_stack(numbers, result);
      flag->flag_cos = 1;
      break;

    case 'C':
      b = stack_pop(numbers);
      result = tan(b);
      push_stack(numbers, result);
      break;

    case 'D':
      b = stack_pop(numbers);
      if (b <= 1 && b >= -1) {
        result = asin(b);
      } else {
        flag->flag_no_error = 0;
        **return_num_err = 2;
      }
      push_stack(numbers, result);
      flag->flag_trig_func = 1;
      break;

    case 'E':
      b = stack_pop(numbers);
      if (b <= 1 && b >= -1) {
        result = acos(b);
      } else {
        flag->flag_no_error = 0;
        **return_num_err = 2;
      }
      push_stack(numbers, result);
      flag->flag_trig_func = 1;
      break;

    case 'F':
      b = stack_pop(numbers);
      result = atan(b);
      push_stack(numbers, result);
      flag->flag_trig_func = 1;
      break;

    case 'G':
      b = stack_pop(numbers);
      result = sqrt(b);
      push_stack(numbers, result);
      flag->flag_cos = 1;
      break;

    case 'H':
      b = stack_pop(numbers);
      result = log(b);
      push_stack(numbers, result);
      break;

    case 'I':
      b = stack_pop(numbers);
      result = log10(b);
      push_stack(numbers, result);
      break;

    case 'J':
      b = stack_pop(numbers);
      a = stack_pop(numbers);
      result = (int)a % (int)b;
      push_stack(numbers, result);
      break;

    default:
      break;
  }
}

void parser(int input_char, Stack *numbers, Stack *sign, Flag *flag,
            int *return_num_err) {
  switch (input_char) {
    case '-':
      if (sign->length > 0 && priority_low(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }

      if (sign->length > 0 && priority_low(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }
      push_stack(sign, input_char);
      break;

    case '+':
      if (sign->length > 0 && priority_low(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }

      if (sign->length > 0 && priority_low(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }
      push_stack(sign, input_char);
      break;

    case '/':
      if (sign->length > 0 && priority_gran(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }

      if (sign->length > 0 && priority_gran(sign)) {
        // printf("case /two\n");
        calculation(numbers, sign, flag, &return_num_err);
      }
      push_stack(sign, input_char);
      break;

    case '*':
      if (sign->length > 0 && priority_gran(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }

      if (sign->length > 0 && priority_gran(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }
      push_stack(sign, input_char);
      break;

    case '^':
      if (flag->flag_from_negative_degree) {
        if (sign->length > 0) {
          if (sign->values[sign->length - 1] <= 'J' &&
              sign->values[sign->length - 1] >= 'A') {
            calculation(numbers, sign, flag, &return_num_err);
          }
        }
        push_stack(sign, input_char);
      }
      break;

    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
      push_stack(sign, input_char);
      break;

    case '(':
      push_stack(sign, input_char);
      break;

    case ')':
      if (priority_low(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }

      if (priority_low(sign)) {
        calculation(numbers, sign, flag, &return_num_err);
      }

      if (sign->values[sign->length - 1] == '(') {
        sign->length -= 1;
      }
      break;

    case '=':
      while (sign->length > 0) {
        calculation(numbers, sign, flag, &return_num_err);
      }
      flag->flag_result = 0;
      break;

    default:
      break;
  }
}

int check_valid(int first, int next) {
  int res = 1;

  if ((first == '/' || first == '*') || first == '^') {
    if ((next == '/' || next == '*') || next == '^') {
      res = 0;
    }
  }

  if (first == ')') {
    if (next <= 'z' && next >= 'a') {
      res = 0;
    }
  }
  return res;
}

int find_trig_func(int input_char, char *input_string,
                   int count_from_string_buf, Flag *flag) {
  if (input_char == 's' && input_string[count_from_string_buf + 1] == 'q') {
    input_char = 'G';
    flag->flag_cos = 0;
  }

  if (flag->flag_trig_func) {
    if (input_char == 's' && flag->flag_cos) {
      input_char = 'A';  // sin
    }

    if (input_char == 'c') {
      input_char = 'B';  // cos
      flag->flag_cos = 0;
    }

    if (input_char == 't' && flag->flag_cos) {
      input_char = 'C';  // tan
    }
  }

  if (input_char == 'a') {
    if (input_string[count_from_string_buf + 1] == 's') {
      input_char = 'D';  // asin
    }

    if (input_string[count_from_string_buf + 1] == 'c') {
      input_char = 'E';  // acos
    }

    if (input_string[count_from_string_buf + 1] == 't') {
      input_char = 'F';  // atan
    }
    flag->flag_trig_func = 0;
  }

  if (input_char == 'l') {
    if (input_string[count_from_string_buf + 1] == 'n') {
      input_char = 'H';
    }

    if (input_string[count_from_string_buf + 1] == 'o') {
      input_char = 'I';
    }
  }

  if (input_char == 'm' && input_string[count_from_string_buf + 1] == 'o') {
    input_char = 'J';
  }
  return input_char;
}

int priority_low(Stack *sign) {
  int result = 0;

  if ((sign->values[sign->length - 1] <= '/' &&
       sign->values[sign->length - 1] >= '*') ||
      sign->values[sign->length - 1] == '^' ||
      (sign->values[sign->length - 1] <= 'J' &&
       sign->values[sign->length - 1] >= 'A')) {
    result = 1;
  }

  return result;
}

int priority_gran(Stack *sign) {
  int result = 0;

  if (sign->values[sign->length - 1] == '*' ||
      sign->values[sign->length - 1] == '/' ||
      sign->values[sign->length - 1] == '^' ||
      (sign->values[sign->length - 1] <= 'J' &&
       sign->values[sign->length - 1] >= 'A')) {
    result = 1;
  }
  return result;
}

int check_unary(int input_char, char *input_string, int swap_count,
                int *count_from_string_buf, Stack *numbers, Stack *sign,
                Flag *flag, int **return_num_err) {
  if (input_char == '-' && input_string[swap_count + 1] == '-') {
    input_char = '+';
    swap_count += 1;
    *count_from_string_buf = swap_count;
  }

  if (input_char == '-' && input_string[swap_count + 1] == '+') {
    input_char = '-';
    swap_count += 1;
    *count_from_string_buf = swap_count;
  }

  if (input_char == '+' && input_string[swap_count + 1] == '-') {
    input_char = '-';
    swap_count += 1;
    *count_from_string_buf = swap_count;
  }

  if (input_char == '+' && input_string[swap_count + 1] == '+') {
    input_char = '+';
    swap_count += 1;
    *count_from_string_buf = swap_count;
  }

  if ((((input_char == '/' || input_char == '*')) &&
       input_string[swap_count + 1] == '-')) {
    if (sign->length > 0 && priority_gran(sign)) {
      calculation(numbers, sign, flag, return_num_err);
    }
    long double a = stack_pop(numbers);
    a *= -1;
    push_stack(numbers, a);
    swap_count += 1;
    *count_from_string_buf = swap_count;
  }

  if (((input_char == '/' || input_char == '*') &&
       input_string[swap_count + 1] == '+')) {
    swap_count += 1;
    *count_from_string_buf = swap_count;
  }

  if (input_char == '^' && input_string[swap_count + 1] == '-') {
    push_stack(sign, input_char);
    swap_count += 1;
    flag->flag_from_negative_degree = 0;
    *count_from_string_buf = swap_count;
  }
  return input_char;
}

// int check_first_sign(){}