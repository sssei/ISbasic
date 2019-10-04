#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int a = 1;
  int i = 2;
  while(a <= n){
    printf("%d ", a);
    a = a * 2;
    i = i + 1;
  }
  printf("\n");
}
