#include<stdio.h>
int main()
{
  int i,n,pos;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  int arr[n];
  printf("Enter Array elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the position to be deleted\n");
  scanf("%d",&pos);
  for(i=0;i<n;i++)
  {
    if(i==pos)
    {
      while(i<n-1)
      {
         arr[i]=arr[i+1];
         i=i+1;
      }
      break;
    }
  }
  n--;
  printf("The new Array elements are \n");
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
}
