#include <stdio.h>

double line(double a[2], double b[2], double x[2]){
  return (a[1]-b[1]) * (x[0]-b[0]) - (a[0]-b[0]) * (x[1]-b[1]);
}

int main(){
  double x1[2],x2[2],y1[2],y2[2];
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1[0], &x1[1], &x2[0], &x2[1], &y1[0], &y1[1], &y2[0], &y2[1]);
  if(line(x1, x2, y1) * line(x1, x2, y2) < 0 && line(y1, y2, x1) * line(y1, y2, x2) < 0){
    printf("OK\n");
  }else{
    printf("NG\n");
  }
}
