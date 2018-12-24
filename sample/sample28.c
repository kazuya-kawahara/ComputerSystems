#include <stdio.h>

typedef int (*Calc)(int, int);

int sum(int x, int y){ return x + y; }
int sub(int x, int y){ return x - y; }
int mul(int x, int y){ return x * y; }
int div(int x, int y){ return x / y; }

int main() {
  int x = 10, y = 2;
  Calc calc;
  
  calc = sum;
  printf("calc(%d, %d) = %d\n", x, y, calc(x, y));
  calc = sub;
  printf("calc(%d, %d) = %d\n", x, y, calc(x, y));
}
