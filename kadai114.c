#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
int main(void)
{
    long *data;
    long n = 1e10;
    data = malloc(sizeof(long)*n); 
    for (long i = 0; i < n; i+=1000) {
        data[i] = rand()%1000;
    }

    long sum = 0;
    clock_t start, end;
    start = clock();
    for (long i = 0; i < n; i+=1000) {
        sum += data[i];
    }
    end = clock();

    printf("%ld %f\n",sum,(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
