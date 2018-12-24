#include <stdio.h>

typedef int (*Calc)(int, int);
typedef Calc T[];

int sum(int x, int y){ return x + y; }
int sub(int x, int y){ return x - y; }
int mul(int x, int y){ return x * y; }
int div(int x, int y){ return x / y; }

int main() {
  int x = 10, y=2;
  T calc = {sum, sub, mul, div};
  int i;
  for (i = 0; i < 4; i++) {
    printf("calc(%d, %d) = %d\n", x, y, calc[i](x,y));
  }
}
