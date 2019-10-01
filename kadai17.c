#include <stdio.h>

int main(){
  char s[100] = "";
  char t[100] = "";
  int i = 0;
  scanf("%s%s", s, t);
  int flag = 1;
  while(1){
    if(s[i] != t[i]) flag = 0;
    if(s[i] == '\0') break;
    i++;
  }
  if(flag) printf("OK\n");
  else printf("NG\n");
}
