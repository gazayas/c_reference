#include <stdio.h>

int main(void){

  int ary[] = {1, 10, 8};
  int i;

  /* for(i = 0; i < ary.length; i++){} じゃない */
  for(i = 0; i < sizeof(ary)/sizeof(ary[0]); i++){
    printf("%d\n", ary[i]);
  }

  return 0;
}

