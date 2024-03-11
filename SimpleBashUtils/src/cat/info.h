#ifndef _INFO_H_
#define _INFO_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct opt {
  int b, e, n, s, t, err, v;
};
void read_opt(FILE *fp, struct opt opt);

#endif