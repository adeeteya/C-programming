#include<stdio.h>
void insertionsort(int arr[],int n){
  int i,key,j;
  for(i=1;i<n;i++){
    key=arr[i];
    for(j=i-1;j>=0 && arr[j]>key;j--)
      arr[j+1]=arr[j];
    arr[j+1]=key;
  }
}
int main(){
  int i,n;
  printf("Enter the no of elements in the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of the array\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  insertionsort(arr,n);
  printf("The Sorted Array is\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
