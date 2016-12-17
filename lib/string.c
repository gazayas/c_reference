#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  /*
   * char型しかないので、文字列を作るにはchar型の配列を宣言します。
   * また、あとで「。」をstrcat()するので、すべての文字が入れるように30を定義しました。
   */
  char str[30] = "これは文字列です";
  printf("%s\n", str);

  /*
   * 文字列の最後に「EOS」（End Of String）というのがあります。
   * これは「文字列が終わったよ」という意味になります。
   * 文字列を定義すると自動的に代入されるけど、次のように配列の長さを定義したら、
   * \0が最後に入るように準備をしないといけない
   */
  char str2[4] = {'s', 't', 'r', '\0'}; /* \0はEOS */
  printf("%s\n", str2);

  /* Rubyの.to_iや.to_sみたいなメソッド */
  int x = 10;
  char y_str[] = "40";
  int y = atoi(y_str); /* #include <stdlib.h>が要る */
  printf("%d\n", (x + y));

  /* strlen(str)はlongを返すので%lu */
  printf("「これは文字列です」の長さは：%lu\n", strlen(str));
  printf("メモリ上では日本語はローマ字より大きいので%luが出てしまいます。\n", strlen(str));

  /* for文みたいに次の行で配列の長さが取得できます */
  int length = sizeof(str) / sizeof(str[0]);
  printf("\\0が入ってしまうのでsizeof(str)/sizeof(str[0])をしてもダメです：%dになります\n", length);
  printf("日本語の文字はメモリ上で４つの場所を占めてる？から、「strlen(str)/3」をしたらいいかもしれません\n");
  printf("str[3]は%c\n", str[3]);
  printf("本当の長さ？：%lu\n", strlen(str)/3);

  /* 連結 */
  char ten[] = "。";
  strcat(str, ten);
  printf("%s\n", str);

  /*
   * strcmp(), sprintf(), strcpy()もあるのでそちらも見といてください
   */

  /*
   * scanf()をする時は、入力された文字が配列の長さを超えないように、
   * 長さを定義することができる。入力された文字が超えたら、その余りは切り捨てられます。
   */
  char name[5];
  printf("下の名前を書いてください：");
  scanf("%4s", name);
  printf("名前の一部は切り捨てらたはず：%s\n", name);

  return 0;
}

