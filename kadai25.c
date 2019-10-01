#include <stdio.h>

double average(int a[], int n){
  double sum = 0;
  int i;
  for(i = 0; i < n; i++){
    sum += a[i];
  }
  return sum / n ;
}

int main(){
  FILE* fp;
  char fileName[100];
  int a[100];
  int i = 0;
  int tmp;
  fp = fopen("test.txt", "r");
  scanf("%s", fileName);
  while(fscanf(fp, "%d", &tmp) != EOF){
    a[i] = tmp;
    i++;
  }
  fclose(fp);
  fp = fopen(fileName, "w");
  fprintf(fp, "%f\n", average(a, i));
  fclose(fp);
  
}
