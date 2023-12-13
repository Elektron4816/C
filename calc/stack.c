#include "calc.h"
#include "stack.h"

Stack create_stack() {
  Stack s = {
      .values = NULL,
      .length = 0,
      .capacity = 0,
  };
  return s;
}

void push_stack(Stack *s, long double value) {
  if (s->values == NULL || s->length == s->capacity) {
    s->capacity = (s->capacity + 1) * 2;
    s->values =
        (long double *)realloc(s->values, sizeof(long double) * s->capacity);
  }
  s->values[s->length] = value;
  s->length += 1;
}

long double stack_pop(Stack *s) {
  if (s->length == 0) {
    return INT_MIN;
  }
  s->length -= 1;
  return s->values[s->length];
}

void free_stack(Stack *s) {
  if (s->values != NULL) {
    free(s->values);
  }
  s->length = 0;
  s->capacity = 0;
}

void print_stack(Stack *s) {
  for (int i = 0; i < s->length; i++) {
    printf("[%.6Lf]", s->values[i]);
  }
  printf("\n");
}
