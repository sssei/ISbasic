#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
  int number;
  struct stack *next;
} Stack;

void Push(Stack** list, int num){
  Stack* new;
  new = malloc(sizeof(Stack));
  new->number = num;
  new->next = *list;
  *list = new;
}

void PrintListMember(Stack* list){
  Stack* ptr = list;
  while(ptr != NULL){
    printf("%d ",ptr->number);
    ptr = ptr->next;
  }
  printf("\n");
}

int Pop(Stack** list){
    Stack* ptr = *list;
    int res = ptr->number;
    *list = (*list)->next;
    free(ptr);
    return res;
}

int main(void)
{
  int i;
  Stack* list = NULL;
  char S[100];
  scanf("%s", S);
  int len = strlen(S);
  for(i = 0; i < len; i++){
    if(S[i] == '('){
      Push(&list, i);
    }
    if(S[i] == ')'){
      int n = Pop(&list);
      printf("(%d,%d) ", n, i);
    }
  }
  printf("\n");
    
  return 0;
}
