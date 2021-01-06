#include<stdio.h>
#include<math.h>
#ifndef PI
  #define PI 3.14159
#endif
#define area(y) (PI*y*y);
#define fib double phi=(1+sqrt(5))/2; \
  int fibno=round(pow(phi,i)/sqrt(5));
#define display printf("n%d=%d\n",i,fibno);
int main(){
  float area,side;
  printf("Enter Radius of the circle: ");
  scanf("%f",&side);
  area=area(side);
  printf("The area of the circle is: %.2f\n",area);
  int i,n;
  printf("Enter n= ");
  scanf("%d",&n);
  printf("The first %d fibonacci number are\n",n);
  for(i=0;i<n;i++){
    fib;
    display;
  }
  return 0;
}
