#include <stdio.h>

int sumup(int x){
  int res = 0;
  int i;
  for(i = 1; i <= x; i++){
    res += i;
  }
  return res;
}

int main(void)
{
    int x = 0;
 
    scanf("%d", &x);
 
    printf("%d\n", sumup(x));
 
    return 0;
}
