#include <stdio.h>

int sum(int x, int y){ return x + y; }
int sub(int x, int y){ return x - y; }
int mul(int x, int y){ return x * y; }
int div(int x, int y){ return x / y; }

int kuku(int nx, int ny, int calc(int, int)) {
  int i, j;
  for (i = 1; i <= nx; i++) {
    for (j = 1; j <= ny; j++) {
      printf("%3d", calc(i, j));
    }
    printf("\n");
  }
}

int main() {
  kuku(3, 3, sum);
  kuku(5, 5, mul);
}
