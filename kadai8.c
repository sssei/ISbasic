#include <stdio.h>

int main(){
  int x;
  scanf("%d", &x);
  int i;
  for(i = 1; i <= x; ++i){
    int j;
    for(j = 1; j <= x - i; ++j){
      printf(" ");
    }
    for(j = 1; j <= 2 * (i-1) + 1; ++j){
      printf("*");
    }
    printf("\n");
  }
}
