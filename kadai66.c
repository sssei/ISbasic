#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 100
#define MAX 1000
#define INF 1000000000

typedef struct lnode{
  char word[STRING_LENGTH];
  int num;
  struct lnode* right;
  struct lnode* left;
} Node;

int Adj[MAX][MAX];
int route[MAX];
int r = 0;
char name[MAX][STRING_LENGTH];

void init(){
  int i,j;
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      Adj[i][j] = 0;
    }
  }
  for(i = 0; i < MAX; i++) route[i] = -1;
}

Node* InsertNode(Node** tree, char w[], int n){
  if(*tree== NULL){
    *tree= malloc(sizeof(Node));
    strcpy((*tree)->word, w);
    (*tree)->num = n;
    (*tree)->right = NULL;
    (*tree)->left = NULL;
    return *tree;
  }else if(strcmp((*tree)->word, w) == 0){
    (*tree)->num = n;
    return *tree;
  }else if(strcmp((*tree)->word, w) > 0){
    if((*tree)->left == NULL){
      (*tree)->left = InsertNode(&((*tree)->left), w, n);
      return (*tree)->left;
    }else{
      return InsertNode(&((*tree)->left), w, n);
    }
  }else{
    if((*tree)->right == NULL){
      (*tree)->right = InsertNode(&((*tree)->right), w, n);
      return (*tree)->right;
    }else{
      return InsertNode(&((*tree)->right), w, n);
    }
  }
}

int SearchNode(Node* tree, char w[]){
  if(tree== NULL){
    return -1;
  }else if(strcmp(tree->word, w) == 0){
    return tree->num;
  }else if(strcmp(tree->word, w) > 0){
    return SearchNode(tree->left, w);
  }else{
    return SearchNode(tree->right, w);
  }
}


void PrintAdj(int n){
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", Adj[i][j]);
    }
    printf("\n");
  }
}

void PrintRoute(){
  int i;
  for(i = 0; i < r; i++){
    printf("%d ", route[i]);
  }
  printf("\n");
}

int warshallFloyd(int n, int a, int b){
  int d[n][n];
  int i,j,k;
  int res,p;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(i == j) d[i][j] = 0;
      else if(Adj[i][j] == 0) d[i][j] = INF;
      else d[i][j] = Adj[i][j];
    }
  }
  for(k = 0; k < n; k++){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	if(d[i][k] + d[k][j] < d[i][j]){
	  d[i][j] = d[i][k] + d[k][j];
	}
      }
    }
  }
  res = d[a][b];
  if(res == INF) return res;
  p = b;
  while(p != a){
    route[r] = p;
    r++;
    for(i = 0; i < n; i++){
      if(Adj[i][p] != 0 && d[a][i] + Adj[i][p] == d[a][p]){
	p = i;
	break;
      }
    }
  }
  route[r] = a;
  r++;
  return res;
}

int main(){
  FILE* fp;
  char start[STRING_LENGTH], end[STRING_LENGTH];
  char a[STRING_LENGTH], b[STRING_LENGTH];
  int i,weight;
  int idx = 0;
  int s, e, dis;
  Node* tree = NULL;
  
  init();

  fp = fopen("graph.txt", "r");
  fscanf(fp, "%s%s", start, end);
  
  while((fscanf(fp, "%s%s%d",a, b, &weight)) != EOF){
    int i = SearchNode(tree, a);
    int j = SearchNode(tree, b);
    if(i == -1){
      i = idx;
      InsertNode(&tree, a, idx);
      strcpy(name[idx], a);
      idx++;
    }
    if(j == -1){
      j = idx;
      InsertNode(&tree, b, idx);
      strcpy(name[idx], b);
      idx++;
    }
    Adj[i][j] = weight;
  }

  s = SearchNode(tree, start);
  e = SearchNode(tree, end);
  dis = warshallFloyd(idx, s, e);

  if(dis == INF){
    printf("(no route)\n");
  }else{
    for(i = r-1; i >= 0; i--){
      printf("%s\n", name[route[i]]);
    }
  }
}
