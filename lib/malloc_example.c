#include <stdio.h>
#include <stdlib.h>
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

  int size;
  printf("何人分を作りますか？：");
  scanf("%d", &size);
  printf("%d人分ですね。\n", size);

  person *heap;
  /* ここに「size」を書いてもsizeof(*heap)が変わらないな。構造体であるstructの領域だけを出力する */
  heap = (person *)malloc(sizeof(person) * size);
  if(heap == NULL) exit(0);
  printf("heapの１つの要素のメモリの領域は：%luバイトです\n", sizeof(*heap));

  int i;
  for(i = 0; i < size; i++){
    person_insert(&heap[i]);
  }
  for(i = 0; i < size; i++){
    person_print(heap[i]);
  }

  free(heap);
  
  return 0;
}
