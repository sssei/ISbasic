#include <stdio.h>
#include <stdlib.h>
 
typedef struct lnode {
    int number;
    struct lnode *next;
} Node;

void AppendListMember(Node** list, int n){
  Node* new;
  new = malloc(sizeof(Node));
  new->number = n;
  new->next = *list;
  *list = new;
}

void PrintListMember(Node* list){
  Node* ptr = list;
  while(ptr != NULL){
    printf("%d ",ptr->number);
    ptr = ptr->next;
  }
  printf("\n");
}

int CountListSize(Node* list){
  Node* ptr = list;
  int cnt = 0;
  while(ptr != NULL){
    cnt++;
    ptr = ptr->next;
  }
  return cnt;
}

void DeleteListMember(Node** list, int n){
  if(n == 0){
    Node* ptr = *list;
    *list = (*list)->next;
    free(ptr);
  }else if(n < CountListSize(*list)){
    Node* ptr = *list;
    int i;
    for(i = 0; i < n-1; i++) ptr = ptr->next;
    Node* delete = ptr->next;
    ptr->next = ptr->next->next;
    free(delete);
  }
}

void InsertListMember(Node** list, int idx, int num){
  if(idx == 0){
    Node* new;
    new = malloc(sizeof(Node));
    new->number = num;
    new->next = *list;
    *list = new;
  }else if(idx  <= CountListSize(*list)){
    Node* new;
    new = malloc(sizeof(Node));
    new->number = num;
    Node* ptr = *list;
    int i;
    for(i = 0; i < idx-1; i++) ptr = ptr->next;
    new->next = ptr->next;
    ptr->next = new;
  }
}

int main(void)
{
    int i,count;
    Node* list = NULL;

    for (i = 9; i >= 0 ; i--) {
        AppendListMember(&list,i); //リストへの要素の追加
    }
    PrintListMember(list); //リストの要素表示

    count = CountListSize(list); //リストの要素数カウント
    printf("%d\n", count);
    
    DeleteListMember(&list, 5); //リストからの要素削除
    PrintListMember(list);

    InsertListMember(&list,9,11); //リストへの要素挿入
    PrintListMember(list);

    return 0;
}
