#include "extern.h"

extern void sum(int min, int max){
  printf("%d\n", (min + max));
}

int main(void){
  sum(10, 20);
  return 0;
}

