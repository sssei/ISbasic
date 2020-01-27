#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
int main(void)
{
    int *a,*b,*c;
    int n = 1000;
    a = malloc(sizeof(int)*n*n);
    b = malloc(sizeof(int)*n*n); 
    c = malloc(sizeof(int)*n*n);
    for (int i = 0; i < n*n; i++) {
        a[i] = rand()%1000;
        b[i] = rand()%1000;
        c[i] = 0;
    }

    clock_t start, end;
    start = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i*n+j] += a[i*n+k]*b[k*n+j];
            }
        }
    }
    end = clock();

    printf("%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
