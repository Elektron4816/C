#ifndef _STACK_H_
#define _STACK_H_

#include "calc.h"

typedef struct {
  long double *values;
  int length;
  int capacity;
} Stack;

Stack create_stack();
void push_stack(Stack *s, long double value);
long double stack_pop(Stack *s);
void free_stack(Stack *s);
void print_stack(Stack *s);


#endif // _STACK_H_