#include <stdio.h>

/*
 * グローバル変数に何も代入しないと「0」として初期化されます 。
 * main関数の中では別のランダム？の値が代入されます。
 */
int i;

int counter(); /* プロトタイプ宣言 */

int main(void)
{
  int num;
  printf("%d\n", i);
  printf("%d\n", num);

  /* scanf()をすると「&」が要る */
  printf("数字を入力してください：");
  scanf("%d", &num);
  printf("%dを入力しましたね\n", num);

  counter();
  counter();
  counter();
  /* outlastはcounter()の静的変数であるため、次の行を実行するとエラーが発生されます */
  printf("%d", outlast);

  return 0;
}

/*
 * 普通はmain関数は最後の方に置くけど、プロトタイプ宣言を使うと関数の順番は関係なくなる
 */

int counter(void)
{
  /*
   * static（静的）変数は一回初期化されたら、また初期化されません。
   * プログラムが終わるまで、counter()関数の変数にも関わらず、関数が呼び出されても再び初期化されません。
   * また、この関数だけでこの関数を使うことができます
   */
  static int outlast = 0;
  outlast++;
  printf("static（静的）変数の状態：%d\n", outlast);
  return 0;
}

