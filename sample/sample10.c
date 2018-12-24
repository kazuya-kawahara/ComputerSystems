#include <stdio.h>
int main()
{
   int nx;
   double dx;
   int vc[3];
   printf("&nx   =%p\n", &nx);
   printf("&dx   =%p\n", &dx);
   printf("&vc   =%p\n", &vc);
   printf("&vc[0]=%p\n", &vc[0]);
   printf("&vc[1]=%p\n", &vc[1]);
   printf("&vc[2]=%p\n", &vc[2]);
}
