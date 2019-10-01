#include <stdio.h>

void str_tolower(char* s){
  int i;
  for(i = 0; s[i] != '\0'; ++i){
    s[i] = s[i] + 0x20;
  }
}

int main(void)
{
    char s[100] = "";
 
    scanf("%99s", s);
 
    str_tolower(s);
 
    printf("%s\n", s);
 
    return 0;
}
