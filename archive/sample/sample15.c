#include <stdio.h>

int main() {
  char str1[] = "ABC";
  char str2[] = {'A', 'B', 'C', '\0'};
  char *strp  = "ABC";
  
  printf("str1=%s\n", str1);
  printf("str1=%s\n", &str1[0]);
  printf("str2=%s\n", str2);
  printf("strp=%s\n", strp);
}
