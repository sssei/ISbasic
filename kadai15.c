#include <stdio.h>

int str_chnum(const char* s, char c){
  int i = 0;
  int cnt = 0;
  while(s[i]){
    if(s[i] == c) cnt++;
    i++;
  }
  return cnt;
}

int main(void)
{
    char s[100] = "";
    char c = 'a';

    scanf("%99s", s);
 
    printf("%d\n", str_chnum(s,c));
 
    return 0;
}
