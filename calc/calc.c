#include "calc.h"
#include "stack.h"

// int main() {

//   char string[255] = "sin(x)+x=";
//   double result = 0;
//   double x = 1.0;
//   result = main_func(string, x);
//   printf("%f\n", result);
//   return 0;
// }

double main_func(char *input_string, double x) {
  Stack numbers = create_stack();
  Stack sign = create_stack();
  Flag flag = {1, 0, 1, 1, 1};
  double grand_result = 0;
  int len_buf = strlen(input_string);
  if (len_buf > 255) {
    printf("Too many charecter - max is 255");
  } else if (input_string[len_buf - 1] != '=') {
    printf("last symbol need '=");
  } else {
    int input_char = 0;
    int count_from_number = 0;
    int count_from_string_buf = 0;
    char *buf_char_to_int = (char *)calloc(50, sizeof(char));
    long double result_int = 0;
    int previous_char = 0;
    while ((input_char = input_string[count_from_string_buf]) != '\0') {
      if (input_char == 'x'){
        push_stack(&numbers, x);
      }
      if (check_valid(previous_char, input_char)) {
        if ((input_char <= '9' && input_char >= '0') || input_char == '.') {
          buf_char_to_int[count_from_number] = input_char;
          count_from_number++;
          flag.flag_num = 1;
        } else {
          if (flag.flag_result && flag.flag_num) {
            count_from_number = 0;
            result_int = s21_atof(buf_char_to_int);
            push_stack(&numbers, result_int);
            if (strlen(buf_char_to_int) != 0) {
              free_buf(buf_char_to_int);
            }
            //print_stack(&numbers);
          }
          flag.flag_num = 0;
          input_char = find_trig_func(input_char, input_string,
                                      count_from_string_buf, &flag);
          int swap_count = count_from_string_buf;
          input_char =
              check_unary(input_char, input_string, swap_count,
                          &count_from_string_buf, &numbers, &sign, &flag);
          parser(input_char, &numbers, &sign, &flag);
        }
        previous_char = input_char;
      } else {
        printf("Enter wrong argument\n");
        flag.flag_no_error = 0;
        break;
      }
      count_from_string_buf++;
    }
    // double grand_result = 0;
    if (flag.flag_no_error) {
      grand_result = stack_pop(&numbers);
    }
    free_stack(&numbers);
    free_stack(&sign);
    free(buf_char_to_int);
  }
  return grand_result;
}
