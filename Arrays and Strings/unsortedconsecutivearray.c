#include<stdio.h>
int main(){
  int i,j,n,min=0,k;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    if(arr[min]>arr[i])
      min=i;
  }
  min=arr[min];
  k=min;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(arr[j]==k){
        k+=1;
        continue;
      }
    }
  }
  if(k==(min+n))
    printf("The appearence of elements in the array are consecutive.");
  else
    printf("The appearence of elements in the array are not consecutive.");
}
