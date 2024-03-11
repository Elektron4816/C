#include "./grep_info.h"

void read_opt(char *argv[], regex_t re, FILE *fp, int j, int check,
              char *buffer, struct opt opt) {
  int r = 0;
  int q = 0;
  regmatch_t pmatch[1];
  int flag_l = 0;
  while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
    q++;
    int regx = 0;
    if (opt.o && !opt.c && !opt.v) {
      for (int i = 0;; i++) {
        regx = regexec(&re, buffer, 1, pmatch, 0);
        if (regx) {
          break;
        }
        if (opt.l) {
          flag_l = 1;
          break;
        }
        if (buffer[pmatch[0].rm_eo] != '\n' && !opt.h && check != 0) {
          printf("%s:", argv[j]);
          if (opt.n) {
            printf("%d:", q);
          }
        }
        printf("%.*s\n", (int)(pmatch[0].rm_eo - pmatch[0].rm_so),
               buffer + pmatch[0].rm_so);
        buffer = buffer + pmatch[0].rm_eo;
      }
    } else {
      regx = regexec(&re, buffer, 1, pmatch, 0);
    }

    if (opt.v && !opt.l) {
      regx = !regexec(&re, buffer, 1, pmatch, 0);
    }
    if (opt.c && regx == 0 && !opt.l) {
      r++;
    }
    if (opt.l && regx == 0) {
      flag_l = 1;
      r = 1;
    } else if (opt.l && !regx == 0 && opt.v) {
      flag_l = 1;
      r = 1;
    }
    if (!opt.c && !opt.l) {
      if (check != 0 && regx == 0 && !opt.h) {
        printf("%s:", argv[j]);
      }
      if (opt.n && regx == 0) {
        printf("%d:", q);
      }
      if (regx == 0) {
        printf("%s", buffer);
      }
    }
  }
  if (opt.c && check != 0 && !opt.h) {
    printf("%s:%d\n", argv[j], r);
  } else if (opt.c) {
    printf("%d\n", r);
  }
  if (flag_l) {
    printf("%s\n", argv[j]);
  }
}