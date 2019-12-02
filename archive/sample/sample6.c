#include <stdio.h>

int sum(int f, int l)
{
  int sum = 0;
  int i;
  for (i = f; i <= l; i++) {
    sum += i;
  }   
  return sum;
}

int main()
{
  int s;
  s = sum(1, 10);
  printf("sum=%d\n", s);
  return 0;
}
