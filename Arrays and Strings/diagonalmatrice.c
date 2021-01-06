#include<stdio.h>
int main()
{
  int i,j,n;
  printf("Enter the value of n\n");
  scanf("%d",&n);
  int arr[n][n];
  printf("Enter array elements\n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&arr[i][j]);
  printf("The left diagonals are\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==j)
        printf("%d\t",arr[i][j]);
    }
  }
  printf("\nThe Right Diagonals are\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i+j==n-1)
        printf("%d\t",arr[i][j]);
    }
  }
}
