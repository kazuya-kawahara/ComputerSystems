#include <stdio.h>

struct data {
  int key;
  int val;
};

int func1(struct data d) {
  d.val = 20;
}

int main() {
  struct data d = {1, 10};
  printf("d.val = %d\n", d.val);
  func1(d);
  printf("d.val = %d\n", d.val);
  return 0;
}

  
