#include<stdio.h>
int main(){
  int i,j,n,min,max,temp;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=0;i<n;i+=2){
    min=i;max=i;
    for(j=i+1;j<n;j++){
      if(arr[min]>arr[j])
        min=j;
      if(arr[max]<arr[j])
        max=j;
    }
    if(i+1==n)
      break;
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    if(i+2==n)
      break;
    temp=arr[i+1];
    arr[i+1]=arr[max];
    arr[max]=temp;
  }
  printf("The new array is:\n");
  for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
  return 0;
}
