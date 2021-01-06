#include <stdio.h>
int main()
{
  printf("Enter numbers to calculate the sum of the numbers entered\nPress 0 to exit\n");
  int sum=0,n;
  do{
    scanf("%d",&n);
    sum+=n;
  }while(n!=0);
  printf("Sum = %d",sum);
}
