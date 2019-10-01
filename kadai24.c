#include <stdio.h>

void reverse(char a[][10], int n){
  int i,j;
  char tmp[10];
  for(i = 0; i < n; i++){
    int len = 0;
    for(j = 0; a[i][j] != '\0'; ++j){
      tmp[j] = a[i][j];
      len++;
    }
    for(j = 0; j < len; ++j){
      a[i][j] = tmp[len-j-1];
    }
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
