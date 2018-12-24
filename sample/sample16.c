#include <stdio.h>
int main(){
  char str[] = "ABC";
  char *p;

  for(p=str; *p != '\0'; p++) {
    printf("%c", *p+32);
  }
  printf("\n");
  printf("p=%p\n",p);
  printf("&str[3]=%p\n", &str[3]);
}
