#include <stdio.h>

int main(){
  union{
    float f;
    unsigned int i;
  }x;
  scanf("%f", &x.f);
  unsigned int res = x.i;
  int i;
  for(i = 0; i < 32; i++){
    printf("%d", (res >> (31 - i)) & 1);
  }
  printf("\n");
}
