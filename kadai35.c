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
  double dis[3] = {};
  for(i = 0; i < 3; i++){
    for(j = 0; j < N; j++){
      if(c[j] == i){
	dis[i] += sqrt((xy[0] - x[j]) * (xy[0] - x[j]) + (xy[1] - y[j]) * (xy[1] - y[j]));
      }
    }
  }
  if(dis[0] < dis[1]){
    if(dis[0] < dis[2]) printf("0\n");
    else printf("2\n");
  }else{
    if(dis[1] < dis[2]) printf("1\n");
    else printf("2\n");
  }
}
