#include<stdio.h>
int binarysearch(int arr[],int x,int low,int high){
  if(high<low)
    return -1;
  int mid=low+(high-low)/2;
  if(arr[mid]==x)
    return mid;
  else if(arr[mid]>x)
    return binarysearch(arr,x,low,mid-1);
  else
    return binarysearch(arr,x,mid+1,high);
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
  pos=binarysearch(arr,x,0,n-1);
  if(pos!=-1)printf("%d is found at position %d",x,pos);
  else printf("The element is not present in the array");
}
