#include<stdio.h>
int main(){
  int i,j,n,sum,value,check=0;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the Sum: ");
  scanf("%d",&value);
  for(i=0;i<n&&check==0;i++){
    sum=arr[i];
    for(j=i+1;j<n;j++){
      sum+=arr[j];
      if(sum==value){
        printf("Sum found between the indexes %d and %d",i,j);
        check=1;
        break;
      }
      else if(sum>value)break;
    }
  }
  if(check==0)
    printf("No Subarray with the sum %d found.",value);
}
