#include<stdio.h>
void shellsort(int arr[],int n){
  int i,j,key,gap;
  for(gap=n/2;gap>0;gap/=2){
    for(i=gap;i<n;i++){
      key=arr[i];
      for(j=i;j>=gap && arr[j-gap]>key;j-=gap)
        arr[j]=arr[j-gap];
      arr[j]=key;
    }
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
  shellsort(arr,n);
  printf("The Sorted Array is\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
