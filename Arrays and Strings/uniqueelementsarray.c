#include<stdio.h>
int main()
{
  int i,j,n,check;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  int arr[n];
  printf("Enter Array elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("The unique elements of the array are:\n");
  for(i=0;i<n;i++)
  {
    check=0;
    for(j=0;j<n;j++)
    {
      if(arr[i]==arr[j])
        check+=1;
    }
    if(check==1)
      printf("%d\n",arr[i]);
  }
}
