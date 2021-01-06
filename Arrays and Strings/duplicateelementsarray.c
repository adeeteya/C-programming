#include<stdio.h>
int main()
{
  int i,j,n,count=1;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  int arr[n],freq[n];
  printf("Enter Array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
    freq[i]=-1;
  }
  for(i=0;i<n;i++)
  {
    if(freq[i]!=0)
    {
      for(j=i+1;j<n;j++)
      {
        if(arr[i]==arr[j])
        {
          count+=1;
          freq[j]=0;
        }
      }
      freq[i]=count;count=1;
     }
   }count=0;
  for(i=0;i<n;i++)
    if(freq[i]>1)
      count+=1;
  printf("The number of duplicate elements are %d\n",count);
}
