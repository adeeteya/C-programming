#include<stdio.h>
int main()
{
  int i,j,n;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  int arr[n];
  printf("Enter Array elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  int max=arr[0],min=arr[0];
  for(i=0;i<n;i++)
  {
    if(min>arr[i])
      min=arr[i];
    if(max<arr[i])
      max=arr[i];
  }
  int max2=arr[0],min2=arr[0];
  for(i=0;i<n;i++)
  {
    if(min2>arr[i]&&arr[i]!=min)
      min2=arr[i];
    if(max2<arr[i]&&arr[i]!=max)
      max2=arr[i];
  }
  printf("The second largest value of the array is %d\n",max2);
  printf("The second smallest value of the array is %d\n",min2);
}
