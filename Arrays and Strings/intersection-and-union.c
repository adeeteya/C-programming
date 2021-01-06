#include <stdio.h>
int main()
{
int a[10], b[10], flag = 0,i, j;
printf("\nEnter array1 element : ");
for(i = 0;i < 10;i++)
scanf("%d",&a[i]);
printf("\nEnter array2 element : ");
for(i = 0;i < 10;i++)
scanf("%d",&b[i]);
printf("Intersection of a and b is: ");
for(i = 0;i < 10;i++)
{
  for(j = 0;j < 10;j++)
  {
    if(a[i] == b[j])
    {
      flag = 1;
    }
  }
  if(flag == 1)
  {
    printf("%d ", a[i]);
  }
  flag = 0;
}
printf("Union of a and b is: ");
for(i = 0;i < 10;i++)
{
  for(j = 0;j < 10;j++)
  {
    if(a[i] == b[j])
    {
      flag = 1;
    }
  }
  if(flag == 0)
  {
    printf("%d ", a[i]);
  }
  flag = 0;
int min=12348844567,max=0;
for(i = 0;i < 10;i++)
{
  for(j = 0;j < 10;j++)
  {
   if(a[i]<b[j])
     if(min>a[i])
     min=a[i];
   else
    if(min>b[j])
      min=b[j];
   if(a[i]>b[j])
      if(max<a[i])
        max=a[i];
   else
      if(max<b[j])
        max=b[j];
 }
}
printf("The difference bettwen min and max is %d",(max-min));
}
