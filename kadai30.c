#include <stdio.h>

int prime(int n){
  int i;
  for(i = 2; i < n; ++i){
    if(n % i == 0) return -1;
  }
  return n;
}

int main(){
  int x,i;
  scanf("%d", &x);
  for(i = 2; i <= x; ++i){
    if(prime(i) != -1) printf("%d\n", prime(i));
  }
}
