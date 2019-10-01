#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  int N = 10000;
  double xy[2];
  int i,j;
  int cnt = 0;
  srand((unsigned)time(NULL));
  for(i = 0; i < N; ++i){
    for(j = 0; j < 2; ++j){
      xy[j] = (double)rand()/RAND_MAX;
    }
    if(xy[0]*xy[0] + xy[1]*xy[1] <= 1) cnt++;
  }
  printf("%f\n", 4.0*cnt/N);
}
