#include <stdio.h>

int max_of(const int a[], int n){
  int i;
  int m = a[0];
  for(i = 0; i < n; i++){
    m = (m > a[i]) ? m : a[i];
  }
  return m;
}

int main(void)
{
    int a[5] = {0, 0, 0, 0, 0};
    int i,max;
 
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
 
    max = max_of(a, 5);

    printf("%d\n", max);
 
    return 0;
}
