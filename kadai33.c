#include <stdio.h>
#include <string.h>


int main(){
  char str[1000];
  char str2[1000];
  int len1,len2,c,i;
  int cnt[1000];
  scanf("%s",str);
  len1 = strlen(str);
  c = 1;
  len2 = 0;
  for(i = 1; i < len1; i++){
    if(str[i] == str[i-1]) c++;
    else{
      str2[len2] = str[i-1];
      cnt[len2] = c;
      c = 1;
      len2++;
    }
  }
  cnt[len2] = c;
  str2[len2] = str[i-1];
  len2++;
  if(len2 * 2 < len1){
    for(i = 0; i < len2; i++){
      printf("%c%d", str2[i], cnt[i]);
    }
    printf("\n");
  }else{
    printf("%s\n", str);
  }
}
