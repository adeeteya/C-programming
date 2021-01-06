#include<stdio.h>
int main(){
  int i,j,n,start=0,end=0,max=0;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      if(arr[i]==arr[j])
        if((j-i+1)>max)
          max=j-i+1;
  printf("The largest span between the same values in the array is: %d",max);
  return 0;
}
