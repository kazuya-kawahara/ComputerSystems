#include <stdio.h>

int main()
{
   int a;
   int b=200;
   int *p;
   p = &a;
   *p = 100;
   printf("*p=%d\n", *p);
   p = &b;
   printf("*p=%d\n", *p);
   *p = 300;
   printf("*p=%d\n", *p);  
   printf(" p=%p\n", p); 
   printf("&p=%p\n", &p);
}
