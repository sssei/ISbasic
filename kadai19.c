#include <stdio.h>

void swap(int* n1, int *n2){
  int tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
}

void sort3(int* n1, int* n2, int* n3){
  if(*n2 > *n3){
    swap(n2,n3);
  }
  if(*n1 > *n2){
    swap(n1,n2);
  }
  if(*n2 > *n3){
    swap(n2,n3);
  }
}

int main(void)
{
    int x[3] = {0, 0, 0};
    int i;
 
    for (i = 0; i < 3; i++)
        scanf("%d", &x[i]);
 
    sort3(&x[0], &x[1], &x[2]);
 
    for (i = 0; i < 3; i++)
        printf("%d\n", x[i]);
 
    return 0;
}
