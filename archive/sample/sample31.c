#include <stdio.h>

struct _map1 {
   int key;
   int value;
};
typedef struct _map1 map1;

typedef struct {
   int key;
   int id;
   int value;
} map2;

int main() {
  map1 m1 = {1, 10};
  map2 m2 = {2, 2, 20};
  printf("m1={%d, %d}\n", m1.key, m1.value);
  printf("m2={%d, %d, %d}\n", m2.key, m2.id, m2.value);
}

