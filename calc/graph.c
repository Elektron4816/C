#include "calc.h"
#include "stack.h"

#define XMAX 2
#define XMIN -2
#define YMAX 2
#define YMIN -2

int main() {

  char string[255] = "log(x)=";
  double y = 0;
  for (double x = XMIN; x <= XMAX; x += 0.1) {
    y = main_func(string, x);
    printf("y = %f, x = %f\n", y,x);
  }
  return 0;
}