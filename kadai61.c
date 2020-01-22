#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 100

typedef struct lnode{
  char word[STRING_LENGTH];
  char tango[STRING_LENGTH];
  struct lnode* right;
  struct lnode* left;
} Node;

Node* InsertNode(Node** tree, char w[], char t[]){
  if(*tree== NULL){
    *tree= malloc(sizeof(Node));
    strcpy((*tree)->word, w);
    strcpy((*tree)->tango, t);
    (*tree)->right = NULL;
    (*tree)->left = NULL;
    return *tree;
  }else if(strcmp((*tree)->word, w) == 0){
    strcpy((*tree)->tango, t);
    return *tree;
  }else if(strcmp((*tree)->word, w) > 0){
    if((*tree)->left == NULL){
      (*tree)->left = InsertNode(&((*tree)->left), w, t);
      return (*tree)->left;
    }else{
      return InsertNode(&((*tree)->left), w, t);
    }
  }else{
    if((*tree)->right == NULL){
      (*tree)->right = InsertNode(&((*tree)->right), w, t);
      return (*tree)->right;
    }else{
      return InsertNode(&((*tree)->right), w, t);
    }
  }
}

char* SearchNode(Node* tree, char w[]){
  if(tree== NULL){
    return "(not found)";
  }else if(strcmp(tree->word, w) == 0){
    return tree->tango;
  }else if(strcmp(tree->word, w) > 0){
    return SearchNode(tree->left, w);
  }else{
    return SearchNode(tree->right, w);
  }
}

Node* minDelete(Node* tree){
  if(tree->left == NULL){
    return tree;
  }
  return minDelete(tree->left);
}

Node* DeleteNode(Node** tree, char w[]){
  if(*tree == NULL){
    return NULL;
  }
  if(strcmp((*tree)->word, w) > 0){
    (*tree)->left = DeleteNode(&((*tree)->left), w);
    return *tree;
  }
  if(strcmp((*tree)->word, w) < 0){
    (*tree)->right = DeleteNode(&((*tree)->right), w);
    return *tree;
  }
  if((*tree)->right == NULL && (*tree)->left == NULL){
    free(*tree);
    return NULL;
  }
  Node* x;
  if((*tree)->right == NULL){
    x = (*tree)->left;
    free(*tree);
    return x;
  }
  if((*tree)->left == NULL){
    x = (*tree)->right;
    free(*tree);
    return x;
  }
  x = minDelete((*tree)->right);
  char tmp1[STRING_LENGTH], tmp2[STRING_LENGTH];
  strcpy(tmp1, x->word);
  strcpy(tmp2, x->tango);
  DeleteNode(tree, x->word);
  strcpy((*tree)->word, tmp1);
  strcpy((*tree)->tango, tmp2);
  return *tree;
}


void Print(Node* tree){
  Node* ptr = tree;
  if(ptr == NULL){
    return;
  }else{
    Print(ptr->left);
    printf("%s ",ptr->word);
    Print(ptr->right);
  }
}

int main(){
  Node* tree = NULL;
  char order[10];
  char TreeWord[100];
  char TreeTango[100];
  scanf("%s", order);
  while(order[0] != 'q'){
    if(order[0] == 'i'){
      scanf("%s%s", TreeWord, TreeTango);
      InsertNode(&tree, TreeWord, TreeTango);
    }else if(order[0] == 's'){
      scanf("%s", TreeWord);
      printf("%s\n", SearchNode(tree, TreeWord));
    }else{
      scanf("%s", TreeWord);
      DeleteNode(&tree, TreeWord);
    }
    scanf("%s", order);
  }
}
