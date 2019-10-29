#include <stdio.h>
#include <math.h>

int main(){
  FILE* fp;
  int i,j;
  int N = 0;
  double  x[110],y[110];
  int c[110];
  fp = fopen("input_data.txt", "r");
  while(fscanf(fp, "%lf%lf%d", &x[N], &y[N], &c[N]) != EOF){
    N++;
  }
  double xy[2];
  scanf("%lf%lf", &xy[0], &xy[1]);
  double minDis = 1000000000;
  int class;
  for(i = 0; i < N; i++){
    double dis = sqrt((x[i] - xy[0]) * (x[i] - xy[0]) + (y[i] - xy[1]) * (y[i] - xy[1]));
    if(dis < minDis){
      class = c[i];
      minDis = dis;
    }
  }
  printf("%d\n", class);
}

