#include <stdio.h>
#include <stdlib.h> /* これは必要です */


/* メモリリークに関する記事
 * http://qiita.com/sawasaka/items/2df474fc00ec2105acab
 * https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%A2%E3%83%AA%E3%83%AA%E3%83%BC%E3%82%AF
 */

/*
 * malloc() (Memory Allocateという意味) とfree()を使います
 * 普段は配列の大きさを一発で定義するのですが、
 * realloc() (Reallocateという意味) を使えば
 * 配列の大きさを再び定義することができます
 */

 /* 396ページ：「mallocの実態」
  *  malloc関数は、好きなように好きなサイズの動的配列を作ることができるので、
  * 非常に便利ですが、実は、その仕組みは、メモリに印をつけているだけです。
  *  これは、冷蔵庫に入っているお菓子に名前を書いておくのと同じことで、家族みんな
  * がその名前に従い、他人のお菓子を食べなければ問題はありませんが、勘違いによって
  * ほかの人にお菓子が食べられてしまう可能性は十分あります。
  *  malloc関数にも似たような性質があり、うまく使うのは意外に難しいです。
  * 従って、プログラムの時は、できる限り普通の配列を使うようにして、どうしても
  * 必要な部分だけmalloc関数を使うようにした方が良いでしょう。
  */

int main(void){

  int *heap;
  heap = (int *)malloc(sizeof(int) * 10);
  if(heap == NULL) exit(0);

  int i;
  for(i = 0; i < 10; i++){
    heap[i] = i;
  }

  printf("%d\n", heap[5]);

  /* realloc()による配列の再定義 */
  heap = (int *)realloc(heap, sizeof(int) * 100);

  free(heap);

  return 0;

}

