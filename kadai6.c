#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int flag = 0;
  while(n){
    int a = n % 10;
    if(a || flag){
      printf("%d", a);
      flag = 1;
    } 
    n /= 10;
  }
  printf("\n");
}
