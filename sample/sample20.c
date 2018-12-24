#include <stdio.h>

struct data {
  int id;
  int height;
};

void swap(struct data *dx, struct data *dy)
{
  struct data d = *dx;
  *dx = *dy;
  *dy = d;
}

void sort(struct data d[], int n)
{
  int k = n - 1;
  while ( k >= 1){ 
    int i;
    for (i = 1; i <= k; i++){
      if (d[i-1].height > d[i].height) {
	swap(&d[i-1],&d[i]);
      }
    }
    k -= 1;
  }
}

int main()
{
  int i;
  int len = 5;
  struct data d[] = {
    {100, 184},
    {101, 164},
    {102, 175},
    {103, 171},
    {104, 179}
  };
  sort(d, len);
  for (i = 0; i < len; i++)
    printf("%d:%d(id=%d)\n",i, d[i].height, d[i].id);
  return 0;
}
