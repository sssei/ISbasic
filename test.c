#include <string.h>
#include <stdio.h>

int main(){
  char a[100],b[100];
  int A[127] = {};
  int B[127] = {};
  scanf("%s%s", a, b);
  int len1 = strlen(a);
  int len2 = strlen(b);
  int i;
  if(len1 != len2){
    printf("NG\n");
  }else{
    for(i = 0; i < len1; i++){
      A[a[i]]++;
      B[b[i]]++;
    }
    int flag = 1;
    for(i = 0; i < 127; i++){
      if(A[i] != B[i]) flag = 0;
    }
    if(flag) printf("OK\n");
    else printf("NG\n");
  }
}
