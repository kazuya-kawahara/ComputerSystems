#include <stdio.h>

int main() {
  int a[3];
  int b[3] = {1, 2, 3};
  int c[]  = {1, 2, 3};
  int d[3] = {1, 2};
  int i;
  for (i = 0; i < 3; i++) {
    printf("a[%d]=%d, ", i, a[i]);
    printf("b[%d]=%d, ", i, b[i]);
    printf("c[%d]=%d, ", i, c[i]);
    printf("d[%d]=%d \n"  , i, d[i]);
  }
  printf("a[%d]=%d\n", 3, a[3]);
  return 0;
}
