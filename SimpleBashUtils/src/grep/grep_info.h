#ifndef _GREP_INFO_H_
#define _GREP_INFO_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#define BUFFER_SIZE 1024

struct opt {
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
  int f;
  int flag;
};

void read_opt(char *argv[], regex_t re, FILE *fp, int j, int check,
              char *buffer, struct opt opt);

#endif