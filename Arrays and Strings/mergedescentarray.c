#include<stdio.h>
int main()
{
  int i,j=0,n,temp;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  int arr1[n],arr2[n],arr3[2*n];
  printf("Enter Array1 elements\n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr1[i]);
      arr3[j]=arr1[i];j+=1;
  }
  printf("Enter Array2 elements\n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr2[i]);
      arr3[j]=arr2[i];j+=1;
  }
  for(i=0;i<(2*n)-1;i++)
  {
    for(j=0;j<(2*n)-i-1;j++)
    {
      if(arr3[j]<arr3[j+1])
      {
        temp=arr3[j];
        arr3[j]=arr3[j+1];
        arr3[j+1]=temp;
      }
    }
  }
  for(i=0;i<2*n;i++)
      printf("%d\t",arr3[i]);
}
