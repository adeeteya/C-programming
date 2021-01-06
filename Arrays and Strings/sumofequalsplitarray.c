#include<stdio.h>
int main(){
  int i,j,lsum,rsum,n,check=0;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=0;i<n;i++){
    lsum=0;rsum=0;
    for(j=0;j<=i;j++)
      lsum+=arr[j];
    for(j=i+1;j<n;j++)
      rsum+=arr[j];
    if(lsum==rsum){
      check=1;
      break;
    }
  }
  if(check==0)
    printf("Array cannot be split");
  else
    printf("Array can be split at position %d",i+1);
}
