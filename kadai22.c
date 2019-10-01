#include <stdio.h>

struct complex_number {
    double real;
    double imaginary;
};

struct complex_number complex_number_add(struct complex_number x, struct complex_number y){
  struct complex_number res;
  res.real = x.real + y.real;
  res.imaginary = x.imaginary + y.imaginary;
  return res;
}

struct complex_number complex_number_multiply(struct complex_number x,struct  complex_number y){
  struct complex_number res;
  res.real = x.real * y.real - x.imaginary * y.imaginary;
  res.imaginary = x.real * y.imaginary + x.imaginary * y.real;
  return res;
}

int main(void)
{
    struct complex_number a, b, c, d;
    scanf("%lf %lf", &a.real, &a.imaginary);
    scanf("%lf %lf", &b.real, &b.imaginary);
    
    c = complex_number_add(a,b);
    d = complex_number_multiply(a,b);

    printf("%f, %f\n", c.real, c.imaginary);  
    printf("%f, %f\n", d.real, d.imaginary); 
       
    return 0;
}
