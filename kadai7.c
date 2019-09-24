#include <stdio.h>

int main(){
  int x;
  scanf("%d", &x);
  int i;
  for(i = 1; i <= x; ++i){
    if(i % 3 == 0 && i % 5 == 0) printf("FizzBuzz\n");
    else if(i % 3 == 0) printf("Fizz\n");
    else if(i % 5 == 0) printf("Buzz\n");
    else printf("%d\n", i);
  }
}
