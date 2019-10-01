#include <stdio.h>

int main(){
  int x;
  scanf("%d", &x);
  int cnt = 0;
  int five = 5;
  while(five <= x){
    cnt += x / five;
    five *= 5;
  }
  printf("%d\n", cnt);
}
