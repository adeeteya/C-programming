#include<stdio.h>
int linearsearch(int arr[],int x,int n){
  int i;
  for(i=0;i<n;i++)
    if(arr[i]==x)
      return i;
  return -1;
}
int main(){
  int i,n,x,pos;
  printf("Enter the no of elements in the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of the array\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the Array element to be searched: ");
  scanf("%d",&x);
  pos=linearsearch(arr,x,n);
  if(pos!=-1)printf("%d is found at position %d",x,pos);
  else printf("The element is not present in the array");
}
