#include <stdio.h>

void adjust_point(int* x){
  if(*x < 0) *x = 0;
  if(*x > 100) *x = 100;
}

int main(void)
{
    int x;
 
    scanf("%d", &x);
 
    adjust_point(&x);
 
    printf("%d\n", x);
 
    return 0;
}
