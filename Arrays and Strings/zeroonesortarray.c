#include<stdio.h>
int main(){
  int i,n,pos=0;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("The Sorted 0 and 1 array is:\n");
  for(i=0;i<n;i++){
    if(arr[i]==0){
      arr[i]=arr[pos];
      arr[pos]=0;
      pos+=1;
    }
  }
  for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
  return 0;
}
