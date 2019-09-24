#include <stdio.h>

int main(){
  int x,y;
  scanf("%d %d", &x, &y);
  double  ans = (double) x / y * 100;
  printf("%.2f\n", ans);
}
