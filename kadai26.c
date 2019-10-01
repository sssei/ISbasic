#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(void)
{
    char *src1 = "Hello,world!";
    char *src2;
    int len;

    len = strlen(src1);
    len++;
    src2 = malloc(len);
    if(src2 != NULL){
      strcpy(src2,src1);
      printf("%s\n", src2);
      free(src2);
    }
    return 0;
}
