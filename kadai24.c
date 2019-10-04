#include <stdio.h>

void copy(char s1[], char s2[]){
  int i;
  for(i = 0; s1[i] != '\0'; i++){
    s2[i] = s1[i];
  }
  s2[i] = '\0';
}

void reverse(char a[][10], int n){
  int i;
  char tmp[n][10];
  for(i = 0; i < n; i++){
    copy(a[i], tmp[i]);
  }
  for(i = 0; i < n; i++){
    copy(tmp[i], a[n-1-i]);
  }
}

int main(void)
{
    char a[5][10] = {"", "", "", "", ""};
    int i;
 
    for (i = 0; i < 5; i++)
        scanf("%9s", a[i]);
 
    reverse(a, 5);
 
    for (i = 0; i < 5; i++)
        printf("%s\n", a[i]);
 
    return 0;
}
