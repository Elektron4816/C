#include "./grep_info.h"

int main(int argc, char *argv[]) {
  struct opt opt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int sw;
  int check = 0;
  regex_t re;
  while ((sw = getopt(argc, argv, "ivclnhsfo")) != -1) {
    switch (sw) {
      case 'i':
        opt.i = 1;
        break;
      case 'v':
        opt.v = 1;
        break;
      case 'c':
        opt.c = 1;
        break;
      case 'l':
        opt.l = 1;
        break;
      case 'n':
        opt.n = 1;
        break;
      case 'h':
        opt.h = 1;
        break;
      case 's':
        opt.s = 1;
        break;
      case 'f':
        opt.f = 1;
        break;
      case 'o':
        opt.o = 1;
        break;
      default:
        break;
    }
  }
  if (opt.i) {
    opt.flag = REG_ICASE;
  }
  if (opt.f) {
    FILE *pattern = fopen(argv[optind], "r");
    if (pattern != NULL) {
      char patt_str[BUFFER_SIZE];
      while (fgets(patt_str, BUFFER_SIZE, pattern) != NULL) {
        printf("%s", patt_str);
        regcomp(&re, patt_str, opt.flag);
      }
    }
    fclose(pattern);
  } else {
    regcomp(&re, argv[optind], opt.flag);
  }

  for (int j = optind + 1; j < argc; j++) {
    if (argv[j + 1] != NULL) {
      check = 1;
    }
  }
  for (int j = optind + 1; j < argc; j++) {
    char buffer[BUFFER_SIZE] = {0};
    FILE *fp = fopen(argv[j], "r");
    if (fp == NULL) {
      if (opt.s) {
        continue;
      } else {
        printf("s21_grep: %s: No such file or directory\n", argv[j]);
      }
    } else {
      read_opt(argv, re, fp, j, check, buffer, opt);
    }
    fclose(fp);
  }
  regfree(&re);
  return 0;
}