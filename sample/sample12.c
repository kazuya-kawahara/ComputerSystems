#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main()
{ 
  int num1 = 10, num2 = 20;
  int *p1, *p2;
  
  printf("num1=%d, num2=%d\n", num1, num2);
  swap(&num1, &num2);
  printf("num1=%d, num2=%d\n", num1, num2);
  
  p1 = &num1; p2 = &num2;
  swap(p1, p2);
  printf("num1=%d, num2=%d\n", num1, num2);
  return 0;
}
