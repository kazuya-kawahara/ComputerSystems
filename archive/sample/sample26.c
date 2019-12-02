#include <stdio.h>

int sum(int x, int y){ return x + y; }
int sub(int x, int y){ return x - y; }
int mul(int x, int y){ return x * y; }
int div(int x, int y){ return x / y; }

int calc_upto3(int (*calc)(int, int)) {
  int i;
  for (i = 1; i <= 3; i++) {
    printf("calc(%d, %d) = %d\n", i, i, (*calc)(i, i));
  }
}

int main() {
  printf("calc sum:\n");
  calc_upto3(sum);
  printf("calc mul:\n");
  calc_upto3(mul);  
}
