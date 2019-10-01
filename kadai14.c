#include <stdio.h>

int main(){
  int ch;
  int i = 0;
  while((ch = getchar()) != EOF){
    if(ch == 'x'){
      i++;
    }
  }
  printf("%d\n", i);
}
