#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  struct flag flag = {0};
  int res_i = 0, i = 0, nextsymbol = 0, q = 0;
  long result = 0;
  flag.dot_lenght = 6;
  char dest[100];
  va_list factor;
  va_start(factor, format);
  for (char *ch = (char *)format; *ch; ch++) {
    if (*ch != '%' && flag.flag_space == 0) {
      str[i] = *ch;
    } else {
      if (flag.flag_space) {
        ch--;
        flag.flag_space = 0;
      }
      switch (*++ch) {
        case '%':
          str[i] = '%';
          break;
        case ' ':
          str[i] = ' ';
          flag.flag_space = 1;
          flag.flag_space_for_lenght = 1;
          break;
        case '+':
          str[i] = ' ';
          flag.flag_plus = 1;
          flag.flag_space = 1;
          flag.flag_space_for_lenght = 1;
          break;
        case '.':
          str[i] = ' ';
          flag.flag_dot = 1;
          flag.flag_space = 1;
          flag.flag_dot_for_d = 1;
          break;
        case '-':
          str[i] = ' ';
          i--;
          flag.flag_space = 1;
          flag.flag_minus = 1;
          break;
        case 'h':
          str[i] = ' ';
          i--;
          flag.flag_length_h = 1;
          flag.flag_space = 1;
          break;
        case 'l':
          str[i] = ' ';
          i--;
          flag.flag_length_l = 1;
          flag.flag_space = 1;
          break;
        case 'L':
          str[i] = ' ';
          i--;
          flag.flag_length_upper_l = 1;
          flag.flag_space = 1;
          break;
        default:
          result = 0;
          q = 0;
          if (*ch == 48) {
            flag.flag_null = 1;
          }
          for (nextsymbol = *ch; nextsymbol >= 48 && nextsymbol <= 57;
               nextsymbol = *++ch, q++) {
            dest[q] = nextsymbol;
          }
          result = strtol(dest, NULL, 10);
          if (flag.flag_dot) {
            flag.dot_lenght = result;
          }
          if (flag.flag_dot_for_d) {
            result = strtol(dest, NULL, 10);
          }
          if (flag.flag_space_for_lenght) {
            result -= 1;
          }

          for (int j = q - 1; j >= 0; j--) {
            dest[j] = 0;
          }
          get_param(str, ch, i, result, factor, &res_i, flag);
          flag.flag_minus = 0;
          flag.flag_dot = 0;
          flag.flag_plus = 0;
          flag.flag_null = 0;
          flag.dot_lenght = 6;
          result = 0;
          i = res_i;
          break;
      }
    }
    i++;
  }
  va_end(factor);
  str[i] = '\0';
  return *str;
}
void get_param(char *str, char *ch, int i, long result, va_list factor,
               int *res_i, struct flag flag) {
  int *res_func_i = res_i;
  int flag_res_id = 0;
  switch (*ch) {
    case 'o':
      oct_spec(str, i, result, factor, res_func_i, flag);
      flag_res_id = 1;
      break;
    case 'd':
      int_spec(str, i, result, factor, res_func_i, flag);
      flag_res_id = 1;
      break;
    case 'f':
      float_spec(str, i, result, factor, res_func_i, flag);
      flag_res_id = 1;
      break;
    case 'c':
      char_spec(str, i, result, factor, res_func_i, flag);
      flag_res_id = 1;
      break;
    case 's':
      string_spec(str, i, result, factor, res_func_i, flag);
      flag_res_id = 1;
      break;
    case 'u':
      flag.flag_unsigned = 1;
      int_spec(str, i, result, factor, res_func_i, flag);
      flag_res_id = 1;
      break;
    default:
      break;
  }
  if (flag_res_id) {
    res_i = res_func_i;
  } else {
    *res_i = i;
  }
}

char dec_to_oct(char *buf, int n) {
  int k = n, t;
  char s[50];
  int i, j;
  for (i = 0; k > 0; i++) {
    t = k % 8;
    k = k / 8;
    s[i] = t | 0x30;
  }
  i--;
  for (j = 0; i >= 0; j++) {
    buf[j] = s[i];
    i--;
  }
  buf[j] = '\0';
  return *buf;
}
char int_to_string(char *buf, long int n) {
  long int k = n, t;
  char s[50];
  int i = 0, j;
  int sign = 0;
  if (k < 0) {
    sign = 1;
    k = -k;
  }
  if (k == 0) {
    t = 0;
    s[i] = t | 0x30;
    i++;
  }
  for (; k > 0; i++) {
    t = k % 10;
    k = k / 10;
    s[i] = t | 0x30;
  }
  if (sign == 1) {
    s[i] = '-';
    i++;
  }
  i--;
  for (j = 0; i >= 0; j++) {
    buf[j] = s[i];
    i--;
  }
  buf[j] = '\0';
  return *buf;
}

char float_to_string(char *buf, double n, struct flag flag) {
  int k = n, t;
  double x = 0;
  char s[50];
  int i = 0, j;
  int sign = 0;
  if (k < 0) {
    sign = 1;
    k = -k;
    n = -n;
  }
  float q = modf(n, &x);
  for (int m = 0; m < flag.dot_lenght; m++) {
    q *= 10;
  }
  int q_q = q;
  if (q_q == 0) {
    for (; i < flag.dot_lenght; i++) {
      s[i] = q_q | 0x30;
    }
  }

  for (; q_q > 0; i++) {
    t = q_q % 10;
    q_q = q_q / 10;
    s[i] = t | 0x30;
  }
  if (flag.dot_lenght != 0) {
    s[i] = '.';
    i++;
  }
  if (k == 0) {
    t = 0;
    s[i] = t | 0x30;
    i++;
  }
  for (; k > 0; i++) {
    t = k % 10;
    k = k / 10;
    s[i] = t | 0x30;
  }
  if (sign == 1) {
    s[i] = '-';
    i++;
  }
  i--;
  for (j = 0; i >= 0; j++) {
    buf[j] = s[i];
    i--;
  }
  buf[j] = '\0';
  return *buf;
}

void oct_spec(char *str, int i, long result, va_list factor, int *res_func_i,
              struct flag flag) {
  int k_o = i;
  int o = va_arg(factor, int);
  char tmp_o[100];
  dec_to_oct(tmp_o, o);
  int len_o = (int)s21_strlen(tmp_o);
  if (result < len_o) {
    result = len_o;
  }
  if (flag.flag_minus) {
    revers_oct(str, i, tmp_o, result, len_o, flag);
  } else {
    normal_oct(str, i, tmp_o, result, len_o, flag);
  }
  i = k_o + result - 1;
  result = 0;
  *res_func_i = i;
}

void int_spec(char *str, int i, long result, va_list factor, int *res_func_i,
              struct flag flag) {
  long int k_d = i;
  long int d;
  char tmp[100];

  if (flag.flag_length_l) {
    d = va_arg(factor, long);
  } else if (flag.flag_length_h) {
    d = (short)va_arg(factor, int);
  } else {
    d = va_arg(factor, int);
  }
  if (flag.flag_unsigned && d < 0) {
    d = d + 4294967296;
  }
  int_to_string(tmp, d);
  int len_d = (int)s21_strlen(tmp);
  if (result < len_d) {
    result = len_d;
  }
  if (flag.flag_minus) {
    revers_d(str, tmp, i, result, flag, len_d);
  } else {
    normal_d(str, tmp, i, result, flag, len_d);
  }

  i = k_d + result - 1;
  result = 0;
  *res_func_i = i;
}

void float_spec(char *str, int i, long result, va_list factor, int *res_func_i,
                struct flag flag) {
  int k_f = i;
  double f;
  char tmp_f[50];
  if (flag.flag_length_upper_l) {
    f = va_arg(factor, long double);
  } else {
    f = va_arg(factor, double);
  }
  float_to_string(tmp_f, f, flag);
  int len_f = s21_strlen(tmp_f);
  if (result < len_f) {
    result = len_f;
  }
  if (flag.flag_minus) {
    revers_float(str, i, tmp_f, result, len_f, flag);
    if (flag.flag_dot) {
      result -= 1;
    }
  } else {
    normal_float(str, i, tmp_f, result, len_f, flag);
    if (flag.flag_dot) {
      result -= 1;
    }
  }
  i = k_f + result - 1;
  result = 0;
  *res_func_i = i;
}

void string_spec(char *str, int i, long result, va_list factor, int *res_func_i,
                 struct flag flag) {
  int k_s = i;
  char *s = va_arg(factor, char *);
  int len_s = (int)s21_strlen(s);
  if (result < len_s) {
    result = len_s;
  }
  if (flag.flag_minus) {
    revers_string(str, s, i, result, len_s);
  } else {
    normal_string(str, s, i, result, len_s);
  }

  i = k_s + result - 1;
  result = 0;
  *res_func_i = i;
}

void char_spec(char *str, int i, long result, va_list factor, int *res_func_i,
               struct flag flag) {
  int k_c = i;
  char c = (char)va_arg(factor, int);
  if (result == 0) {
    result++;
  }
  if (flag.flag_minus) {
    revers_char(str, i, c, result);
  } else {
    normal_char(str, i, c, result);
  }
  i = k_c + result - 1;
  result = 0;
  *res_func_i = i;
}

void revers_d(char *str, char *tmp, int i, long result, struct flag flag,
              int len_d) {
  if (flag.flag_plus && !flag.flag_null && !flag.flag_dot_for_d) {
    i--;
    str[i++] = '+';
  }
  for (int j = 0; j < len_d; j++) {
    str[i] = tmp[j];
    i++;
  }
  for (int j = 0; j < result - len_d; j++) {
    if (flag.flag_null || flag.flag_dot) {
      str[i] = '0';
    } else {
      str[i] = ' ';
    }
    i++;
  }
}

void normal_d(char *str, char *tmp, int i, long result, struct flag flag,
              int len_d) {
  if ((flag.flag_null || flag.flag_dot_for_d) && flag.flag_plus) {
    i--;
    str[i++] = '+';
  }
  for (int j = 0; j < result - len_d; j++) {
    if (flag.flag_null || flag.flag_dot) {
      str[i] = '0';
    } else {
      str[i] = ' ';
    }
    i++;
  }
  if (flag.flag_plus && !flag.flag_null && !flag.flag_dot_for_d) {
    i--;
    str[i++] = '+';
  }
  for (int j = 0; j < result; j++) {
    str[i] = tmp[j];
    i++;
  }
}
void revers_string(char *str, char *s, int i, long result, int len_s) {
  for (int j = 0; j < len_s; j++) {
    str[i] = s[j];
    i++;
  }
  for (int j = 0; j < result - len_s; j++) {
    str[i] = ' ';
    i++;
  }
}
void normal_string(char *str, char *s, int i, long result, int len_s) {
  for (int j = 0; j < result - len_s; j++) {
    str[i] = ' ';
    i++;
  }
  for (int j = 0; j < result; j++) {
    str[i] = s[j];
    i++;
  }
}
void revers_char(char *str, int i, char c, long result) {
  str[i] = c;
  i++;
  for (int j = 0; j < result - 1; j++) {
    str[i] = ' ';
    i++;
  }
  i--;
}
void normal_char(char *str, int i, char c, long result) {
  for (int j = 0; j < result - 1; j++) {
    str[i] = ' ';
    i++;
  }
  str[i] = c;
}

void revers_oct(char *str, int i, char *tmp_o, long result, int len_o,
                struct flag flag) {
  for (int j = 0; j < len_o; j++) {
    str[i] = tmp_o[j];
    i++;
  }
  for (int j = 0; j < result - len_o; j++) {
    if (flag.flag_null) {
      str[i] = '0';
    } else {
      str[i] = ' ';
    }
    i++;
  }
}
void normal_oct(char *str, int i, char *tmp_o, long result, int len_o,
                struct flag flag) {
  for (int j = 0; j < result - len_o; j++) {
    if (flag.flag_null) {
      str[i] = '0';
    } else {
      str[i] = ' ';
    }
    i++;
  }
  for (int j = 0; j < result; j++) {
    str[i] = tmp_o[j];
    i++;
  }
}

void revers_float(char *str, int i, char *tmp_f, long result, int len_f,
                  struct flag flag) {
  if (flag.flag_dot) {
    i--;
  }
  if (flag.flag_plus && !flag.flag_null) {
    i--;
    str[i++] = '+';
  }
  for (int j = 0; j < len_f; j++) {
    str[i] = tmp_f[j];
    i++;
  }
  for (int j = 0; j < result - len_f; j++) {
    if (flag.flag_null) {
      str[i] = '0';
    } else {
      str[i] = ' ';
    }
    i++;
  }
}

void normal_float(char *str, int i, char *tmp_f, long result, int len_f,
                  struct flag flag) {
  if (flag.flag_dot) {
    i--;
  }
  if (flag.flag_null && flag.flag_plus) {
    i--;
    str[i++] = '+';
  }
  for (int j = 0; j < result - len_f; j++) {
    if (flag.flag_null) {
      str[i] = '0';
    } else {
      str[i] = ' ';
    }
    i++;
  }
  if (flag.flag_plus && !flag.flag_null) {
    i--;
    str[i++] = '+';
  }
  for (int j = 0; j < len_f; j++) {
    str[i] = tmp_f[j];
    i++;
  }
}
