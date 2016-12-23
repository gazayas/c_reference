#include <stdio.h>

/*
 * 定数を作る方法
 * 「；」は要らないことを注意してください
 */
#define PI 3.14159

/*
 * ミニ関数を作ることができ、とても便利な機能です
 */
#define GREETING(name) printf("ようこそ、%sさん\n", name)

int main(void){

  printf("%f\n", PI);

  /* また、こうやって定数を定義することができます */
  const char NAME[64] = "ガブリエル";
  printf("私の名前は%sです\n", NAME);

  GREETING("太郎");

  return 0;

}

