#include <string.h>
#include <stdio.h>

void swap(char* a, char* b){
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(char a[], int n){
  int i,j;
  for(i = 0; i < n-1; i++){
    for(j = i; j < n-1; j++){
      if(a[j] < a[j+1]) swap(&a[j], &a[j+1]);
    }
  }
}

int main(){
  char a[100],b[100];
  scanf("%s%s", a, b);
  int len1 = strlen(a);
  int len2 = strlen(b);
  sort(a, len1);
  sort(b, len2);
  printf("%s %s\n",a, b);
  if(len1 != len2){
    printf("NG\n");
  }else{
    int i;
    int flag = 1;
    for(i = 0; i < len1; i++){
      if(a[i] != b[i]) flag = 0;
    }
    if(flag) printf("OK\n");
    else printf("NG\n");
  }
}
