#include <stdio.h>

int main(){
  int M1[2][3];
  int M2[3][2];
  int A[2][2];
  int i,j;
  for(i = 0; i < 2; i++){
    scanf("%d%d%d", &M1[i][0], &M1[i][1], &M1[i][2]);
  }
  for(i = 0; i < 3; i++){
    scanf("%d%d", &M2[i][0], &M2[i][1]);
  }
  for(i = 0; i < 2; i++){
    for(j = 0; j < 2; j++){
      A[i][j] = M1[i][0] * M2[0][j] + M1[i][1] * M2[1][j] + M1[i][2] * M2[2][j];
    }
    printf("%d %d\n", A[i][0], A[i][1]);
  }
}
