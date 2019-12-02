#include <stdio.h>

struct student {
  char *name;
  int height;
  double weight;
};

int main(){
  struct student sdt1 = {"hamano", 180, 68.5};
  struct student sdt2;
  sdt2.name = "watanabe";
  sdt2.height = 170;
  sdt2.weight = 60.2;
  
  printf("std1=%s, %d, %f\n", sdt1.name, sdt1.height, sdt1.weight);
  printf("std2=%s, %d, %f\n", sdt2.name, sdt2.height, sdt2.weight);
}
