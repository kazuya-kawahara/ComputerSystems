#include <stdio.h>

void sum(int f, int l, int s, int a)
{
  int sum = 0;
  int i;
  for (i = f; i <= l; i++) {
    sum += i;
  }   
  s = sum;
  a = sum / (l - f + 1);
}

int main()
{
  int s = 0, a = 0;
  sum(1, 10, s, a);
  printf("s=%d, a=%d\n ", s, a);
  return 0;
}
