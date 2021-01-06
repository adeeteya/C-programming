#include <stdio.h>
typedef struct{
  int real;
  int imaginary;
}complex;

complex add(complex a,complex b)
{
  complex result;
  result.real=a.real+b.real;
  result.imaginary=a.imaginary+b.imaginary;
  return result;
}

complex sub(complex a,complex b)
{
  complex result;
  result.real=a.real-b.real;
  result.imaginary=a.imaginary-b.imaginary;
  return result;
}

complex multiply(complex a,complex b)
{
  complex result;
  result.real=(a.real*b.real)-(a.imaginary*b.imaginary);
  result.imaginary=(a.real*b.imaginary)+(a.imaginary*b.real);
  return result;
}

int main()
{
  complex n1,n2;
  printf("Enter the complex number n1 in the format a+bi: ");
  scanf("%d+%di",&n1.real,&n1.imaginary);
  printf("Enter the complex number n2 in the format a+bi: ");
  scanf("%d+%di",&n2.real,&n2.imaginary);
  complex result=add(n1,n2);
  printf("ADDITION - %d+%di\n",result.real,result.imaginary);
  result=sub(n1,n2);
  printf("SUBRACTION - %d+%di\n",result.real,result.imaginary);
  result=multiply(n1,n2);
  printf("MULTIPLICATION - %d+%di\n",result.real,result.imaginary);
  return 0;
}
