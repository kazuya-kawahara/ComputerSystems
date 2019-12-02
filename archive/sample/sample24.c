#include <stdio.h>

int mul(int x, int y){
  return x * y;
}

void kuku() {
  int i, j;
  for (i = 1; i <=9; i++) {
    for (j = 1; j <= 9; j++) {
      printf("%3d", mul(i, j));
    }
    printf("\n");
  }
}

int main(){
  kuku();
}
