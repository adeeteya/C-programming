#include<stdio.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int arr[],int start,int end){
  int i=start-1,j,pivot=arr[end];
  for(j=start;j<=end-1;j++)
    if(arr[j]<pivot)
      swap(&arr[++i],&arr[j]);
  swap(&arr[i+1],&arr[end]);
  return i+1;
}
void quickSort(int arr[],int start,int end){
  if(start<end){
    int pindex=partition(arr,start,end);
    quickSort(arr,start,pindex-1);
    quickSort(arr,pindex+1,end);
  }
}

int main(){
  int i,n;
  printf("Enter the no of elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  quickSort(arr,0,n-1);
  printf("Sorted array: \n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
