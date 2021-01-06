#include<stdio.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
void selectionSort(int arr[],int n){
  int i,j,minidx;
  for(i=0;i<n;i++){
    minidx=i;
    for(j=i+1;j<n;j++)
      if(arr[j]<arr[minidx])
        minidx=j;
    swap(&arr[i],&arr[minidx]);
  }
}

int main()
{
  int i,n;
  printf("Enter the no of elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array elements\n");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  selectionSort(arr,n);
  printf("Sorted array: \n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
