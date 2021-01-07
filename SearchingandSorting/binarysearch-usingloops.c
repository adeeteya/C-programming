#include<stdio.h>
int binarysearch(int arr[],int x,int high){
  int low=0,mid;
  while(low<=high){
    mid=low+(high-low)/2;
    if(arr[mid]==x)
      return mid;
    else if(arr[mid]<x)
      low=mid+1;
    else
      high=mid-1;
  }
  return -1;
}
int main(){
  int i,n,x,pos;
  printf("Enter the no of elements in the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of the array in sorted order\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the Array element to be searched: ");
  scanf("%d",&x);
  pos=binarysearch(arr,x,n-1);
  if(pos!=-1)printf("%d is found at position %d",x,pos);
  else printf("The element is not present in the array");
  return 0;
}
