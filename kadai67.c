#include <stdio.h>
#include <string.h>
#define LEN 100

int main(){
  char a[LEN];
  char b[LEN];
  scanf("%s%s", a, b);
  int len1 = strlen(a);
  int len2 = strlen(b);
  int dp[len1+1][len2+1];
  int i,j;

  for(i = 0; i <= len1; i++) dp[i][0] = 0;
  for(i = 0; i <= len2; i++) dp[0][i] = 0;

  for(i = 1; i <= len1; i++){
    for(j = 1; j <= len2; j++){
      if(a[i-1] == b[j-1]){
	dp[i][j] = dp[i-1][j-1] + 1;
      }
    }
  }
}
