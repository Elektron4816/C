#include "./info.h"

int main(int argc, char *argv[]) {
  struct opt opt = {0, 0, 0, 0, 0, 0, 0};
  while (1) {
    static struct option long_options[] = {
        {"number-nonblank", no_argument, NULL, 'b'},
        {"number", no_argument, NULL, 'n'},
        {"squeeze-blank", no_argument, NULL, 's'},
    };
    int sw = getopt_long(argc, argv, "beEnsTtv", long_options, NULL);
    if (sw == -1) {
      break;
    }
    switch (sw) {
      case 'b':
        opt.b = 1;
        break;
      case 'e':
        opt.e = 1;
        opt.v = 1;
        break;
      case 'E':
        opt.e = 1;
        break;
      case 'n':
        opt.n = 1;
        break;
      case 's':
        opt.s = 1;
        break;
      case 'T':
        opt.t = 1;
        break;
      case 't':
        opt.t = 1;
        opt.v = 1;
        break;
      case 'v':
        opt.v = 1;
        break;
      default:
        opt.err = 1;
        break;
    }
  }
  for (int j = optind; j < argc; j++) {
    FILE *fp = fopen(argv[j], "r");
    if (opt.err == 1) {
      printf("usage: cat [-benstv] [file ...]");
    } else {
      if (fp == NULL) {
        printf("File %s: No such file or directory\n", argv[j]);
      } else {
        read_opt(fp, opt);
      }
    }
  }
  return 0;
}