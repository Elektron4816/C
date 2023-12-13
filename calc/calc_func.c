#include "calc.h"
#include "stack.h"

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

void calculation(Stack *numbers, Stack *sign, Flag *flag) {
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
    //printf("calc_case(+)\n");
    push_stack(numbers, result);
    break;
  case '-':
    b = stack_pop(numbers);
    a = stack_pop(numbers);
    result = a - b;
   // printf("calc_case(-)\n");
    push_stack(numbers, result);
    break;
  case '*':
    b = stack_pop(numbers);
    a = stack_pop(numbers);
    result = a * b;
   // printf("calc_case(*)\n");
    push_stack(numbers, result);
    break;
  case '/':
    b = stack_pop(numbers);
    a = stack_pop(numbers);
    result = a / b;
   // printf("calc_case(/)\n");
    push_stack(numbers, result);
    break;
  case '^':
    b = stack_pop(numbers);
    a = stack_pop(numbers);
    result = pow(a, b);
   // printf("calc_case(^)\n");
    push_stack(numbers, result);
    break;
  case 'A':
    b = stack_pop(numbers);
    result = sin(b);
    //printf("b(sin) = %Lf\n", b);
    push_stack(numbers, result);
    break;
  case 'B':
    b = stack_pop(numbers);
    result = cos(b);
    //printf("b(cos) = %Lf\n", b);
    push_stack(numbers, result);
    flag->flag_cos = 1;
    break;
  case 'C':
    b = stack_pop(numbers);
    result = tan(b);
    //printf("b(tan) = %Lf\n", b);
    push_stack(numbers, result);
    break;
  case 'D':
    b = stack_pop(numbers);
    result = asin(b);
    //printf("b(asin) = %Lf\n", b);
    push_stack(numbers, result);
    flag->flag_trig_func = 1;
    break;
  case 'E':
    b = stack_pop(numbers);
    result = acos(b);
    //printf("b(acos) = %Lf\n", b);
    push_stack(numbers, result);
    flag->flag_trig_func = 1;
    break;
  case 'F':
    b = stack_pop(numbers);
    result = atan(b);
    //printf("b(atan) = %Lf\n", b);
    push_stack(numbers, result);
    flag->flag_trig_func = 1;
    break;
  case 'G':
    b = stack_pop(numbers);
    result = sqrt(b);
    //printf("b(sqrt) = %Lf\n", b);
    push_stack(numbers, result);
    flag->flag_cos = 1;
    break;
  case 'H':
    b = stack_pop(numbers);
    result = log(b);
    //printf("b(ln) = %Lf\n", b);
    push_stack(numbers, result);
    break;
  case 'I':
    b = stack_pop(numbers);
    result = log10(b);
    //printf("b(log) = %Lf\n", b);
    push_stack(numbers, result);
    break;
  case 'J':
    b = stack_pop(numbers);
    a = stack_pop(numbers);
    //printf("b(mod) = %Lf\n", b);
    result = (int)a % (int)b;
    push_stack(numbers, result);
    break;
  default:
    // stack_pop(sign);
    break;
  }
  // print_stack(numbers);
}

void parser(int input_char, Stack *numbers, Stack *sign, Flag *flag) {
  switch (input_char) {
  case '-':
    if (sign->length > 0 && priority_low(sign)) {
      //printf("case -\n");
      calculation(numbers, sign, flag);
    }
    if (sign->length > 0 && priority_low(sign)) {
      //printf("case -two\n");
      calculation(numbers, sign, flag);
    }
    push_stack(sign, input_char);
    break;
  case '+':
    if (sign->length > 0 && priority_low(sign)) {
      //printf("case+\n");
      calculation(numbers, sign, flag);
    }
    if (sign->length > 0 && priority_low(sign)) {
     // printf("case +two\n");
      calculation(numbers, sign, flag);
    }
    push_stack(sign, input_char);
    break;
  case '/':
    if (sign->length > 0 && priority_gran(sign)) {
      //printf("case /\n");
      calculation(numbers, sign, flag);
    }
    if (sign->length > 0 && priority_gran(sign)) {
      //printf("case /two\n");
      calculation(numbers, sign, flag);
    }
    push_stack(sign, input_char);
    break;
  case '*':
    if (sign->length > 0 && priority_gran(sign)) {
      //printf("case *\n");
      calculation(numbers, sign, flag);
    }
    if (sign->length > 0 && priority_gran(sign)) {
     // printf("case *two\n");
      calculation(numbers, sign, flag);
    }
    push_stack(sign, input_char);
    break;
  case '^':
    if (sign->length > 0) {
      if (sign->values[sign->length - 1] <= 'J' &&
          sign->values[sign->length - 1] >= 'A') {
       // printf("case ^\n");
        calculation(numbers, sign, flag);
      }
    }
    push_stack(sign, input_char);
    break;
  case 'A': // sin
  case 'B': // cos
  case 'C': // tan
  case 'D': // asin
  case 'E': // acos
  case 'F': // atan
  case 'G': // sqrt
  case 'H': // ln
  case 'I': // log
  case 'J': // mod
    push_stack(sign, input_char);
    break;
  case '(':
    push_stack(sign, input_char);
    break;
  case ')':
    if (priority_low(sign)) {
      //printf("case )\n");
      calculation(numbers, sign, flag);
    }
    if (priority_low(sign)) {
      //printf("case )two\n");
      calculation(numbers, sign, flag);
    }
    if (sign->values[sign->length - 1] == '(') {
      sign->length -= 1;
    }
    break;
  case '=':
    while (sign->length > 0) {
      //printf("case=\n");
      calculation(numbers, sign, flag);
    }
    flag->flag_result = 0;
    break;
  default:
    break;
  }
}

int check_valid(int first, int next) {
  int res = 1;
  if ((first <= '/' && first >= '*') || first == '^') {
    if ((next <= '/' && next >= '*') || next == '^') {
      res = 0; // вернуть на значение 0, когда закончу делать унарный + и -,
               // также скорректировать условия.
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
      input_char = 'A'; // sin
    }
    if (input_char == 'c') {
      input_char = 'B'; // cos
      flag->flag_cos = 0;
    }
    if (input_char == 't' && flag->flag_cos) {
      input_char = 'C'; // tan
    }
  }
  if (input_char == 'a') {
    if (input_string[count_from_string_buf + 1] == 's') {
      input_char = 'D'; // asin
    }
    if (input_string[count_from_string_buf + 1] == 'c') {
      input_char = 'E'; // acos
    }
    if (input_string[count_from_string_buf + 1] == 't') {
      input_char = 'F'; // atan
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
                Flag *flag) {

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
  if (((input_char == '/' || input_char == '*') &&
       input_string[swap_count + 1] == '-')) {
    if (sign->length > 0 && priority_gran(sign)) {
      calculation(numbers, sign, flag);
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
  return input_char;
}
