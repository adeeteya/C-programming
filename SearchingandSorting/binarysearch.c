#include<stdio.h>
int arr[100];
int binarysearch(int search,int low,int high){
  if(high<low)
    return -1;
  int mid=low+(high-low)/2;
  if(arr[mid]==search)
    return mid;
  else if(arr[mid]<search)
    binarysearch(search,mid+1,high);
  else
    binarysearch(search,low,mid-1);
}
int main(){
  int i,n,search,pos;
  printf("Enter the no of array elements: ");
  scanf("%d",&n);
  printf("Enter a Sorted Array\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the Element to be found: ");
  scanf("%d",&search);
  pos=binarysearch(search,0,n);
  if(pos==-1)printf("Element Not Found in the Array");
  else printf("Element Found at index %d",pos);
  return 0;
}
