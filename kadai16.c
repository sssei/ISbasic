#include <stdio.h>

void rev_string(char* s){
  int n,i;
  for(n = 0; s[n] != '\0'; n++);
  char t[n];
  for(i = 0; i < n; i++){
    t[i] = s[n-i-1];
  }
  for(i = 0; i < n; i++){
    s[i] = t[i];
  }
}

int main(void)
{
    char s[100] = "";
 
    scanf("%99s", s);
 
    rev_string(s);
 
    printf("%s\n", s);
 
    return 0;
}
