#include <stdio.h>

int main(){
  int M1[2][3];
  int M2[3][2];
  int A[2][2];
  int i,j;
  for(i = 0; i < 2; i++){
    for(j = 0; j < 3; j++){
      scanf("%d", &M1[i][j]);
    }
  }
  for(i = 0; i < 3; i++){
    scanf("%d%d", &M2[i][0], &M2[i][1]);
  }

  for(i = 0; i < 2; i++){
    printf("%d %d %d\n", M1[i][0], M1[i][1], M1[i][2]);
  }
  for(i = 0; i < 3; i++){
    printf("%d %d\n", M2[i][0], M2[i][1]);
  }

  for(i = 0; i < 2; i++){
    for(j = 0; j < 2; j++){
      A[i][j] = M1[i][0] * M2[0][j];
      printf("%d", A[i][j]);
    }
  }
  for(i = 0; i < 2; i++){
    for(j = 0; j < 2; j++){
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  
}
