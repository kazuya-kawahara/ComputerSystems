#include <stdio.h>

int main(void)
{
  int i;
  int vc[5] = {1,2,3,4,5};
  int *p = &vc[0];
  for (i = 0; i < 5; i++) {
    printf("vc[%d]=%d, p[%d]=%d, *(p+%d)=%d\n",i, vc[i], i, p[i], i, *(p+i));
  }
  return 0;
}
