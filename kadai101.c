#include <stdio.h>

void bitChange(int n){
  int res = n;
  int order = 0;
  int i;
  for(i = 0; i < 32; i++){
    printf("%d", (n >> (31 - i)) & 1);
  }
  printf("\n");
}

int main(){
  int a;
  scanf("%d", &a);
  bitChange(a);
}
