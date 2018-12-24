#include <stdio.h>

#define NUMBER 5
int main()
{
  int i;
  int nums[NUMBER] = {0,1,2,3,4};
  
  for (i=0; i < NUMBER; i++){
    printf("%d\n",nums[i]);
  }
  return 0;
}
