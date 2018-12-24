#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sort(int id[], int height[], int n)
{
  int k = n - 1;
  while ( k >= 1){
    int i;
    for (i = 1; i <= k; i++){
      if (height[i-1] > height[i]) {
	swap(&id[i-1],&id[i]);
        swap(&height[i-1],&height[i]);
      }
    }
    k -= 1;
  }
}

int main()
{
  int i;
  int len = 5;
  int id[] = {100,101,102,103,104};
  int height[] = {184,164,175,171,179};
  sort(id, height, len);
  for (i = 0; i < len; i++)
    printf("%d:%d(id=%d)\n",i, height[i], id[i]);
  return 0;
}
