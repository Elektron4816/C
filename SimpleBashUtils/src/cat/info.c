#include "./info.h"

void read_opt(FILE *fp, struct opt opt) {
  int next = '\n';
  int space_string = 0;
  int i = 0;
  int current = 0;
  while ((current = fgetc(fp)) != EOF) {
    if (opt.s && current == '\n' && next == '\n') {
      space_string++;
      if (space_string > 1) continue;
    } else {
      space_string = 0;
    }
    if (opt.b && next == '\n' && current != '\n') {
      i++;
      opt.n = 0;
      printf("%6d\t", i);
    }
    if (next == '\n' && opt.n) {
      i++;
      printf("%6d\t", i);
    }
    if (opt.t && current == '\t') {
      printf("^");
      current = 'I';
    }
    if (opt.e && current == '\n') {
      printf("$");
    }
    if (opt.v) {
      if ((current >= 0x00 && current < 0x09) ||
          (current > 0x0A && current <= 0x1F)) {
        printf("^");
        current += 64;
      }
      if (current == 0x7F) {
        printf("^");
        current = '?';
      }
    }
    printf("%c", current);
    next = current;
  }
  fclose(fp);
}
