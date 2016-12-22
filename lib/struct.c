#include <stdio.h>
#include <string.h>

typedef struct {
  int year;
  int klass;
  int number;
  char name[64];
  double height;
  double weight;
} student;

void student_print(student data)
{
  printf("学年：%d\n", data.year);
  printf("クラス：%d\n", data.klass);
  printf("出席番号：%d\n", data.number);
  printf("名前：%s\n", data.name);
  printf("身長：%f\n", data.height);
  printf("体重：%f\n\n", data.weight);
  return;
}

void pointer_student_print(student *data)
{
  printf("学年：%d\n", data->year);
  printf("クラス：%d\n", data->klass);
  printf("出席番号：%d\n", data->number);
  printf("名前：%s\n", data->name);
  printf("身長：%f\n", data->height);
  printf("体重：%f\n\n", data->weight);
  return; 
}


int main(void){

  student data;

  data.year = 3;
  data.klass = 4;
  data.number = 18;
  strcpy(data.name, "Mario");
  data.height = 168.2;
  data.weight = 72.4;

  student_print(data);

  /* ポインタを使って学年と名前を変えます */
  student *pdata;
  pdata = &data;
  (*pdata).year = 10;
  strcpy((*pdata).name, "太郎");

  student_print(data);

  /* 340ページ
   * 構造体のポインタ変数の場合も、*で通常変数モードに切り替えることができます。
   * ただし、.の方が優先されるので、かっこをつけて次のようにします。
   *     (構造体ポインタ変数名).要素名
   * ただ、(*)をつけるのは面倒なので、次の書き方で代用できるようになっています。
   * 楮たいポインタ変数名->要素名
   * ->は、引き算と比較演算子を組み合わせた演算子です。この書き方なら、*をつけなくても、
   * 各要素にアクセスできます。
   */

  /* pdata = &dataをしてから〜〜〜 */ 
  pdata->year = 3;
  strcpy(pdata->name, "ガブリエル");
  student_print(data);

  /* 構造体型のポインタを関数に渡す例 */  
  pointer_student_print(&data);

  return 0;

}

/*

#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[256];
  int age;
  int sex;
} person;

void person_insert(person *data)
{
  printf("名前：");
  scanf("%s", data->name);
  printf("年齢：");
  scanf("%d", &data->age);
  printf("性別（１-男性、２-女性）：");
  scanf("%d", &data->sex);
  printf("\n");
}

void person_print(person data)
{
  char sex[16];

  printf("名前：%s\n", data.name);
  printf("年齢：%d\n", data.age);

  if(data.sex == 1){
    strcpy(sex, "男性");
  } else {
    strcpy(sex, "女性");
  }

  printf("性別：%s", sex);
  printf("\n");

}

int main(void){

  person data[3];
  int i;

  for(i = 0; i < 3; i++){
    person_insert(&data[i]);
  }
  for(i = 0; i < 3; i++){
    person_print(data[i]);
  }
  
  return 0;
}

*/
