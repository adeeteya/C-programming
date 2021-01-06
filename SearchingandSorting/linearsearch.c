#include<stdio.h>
int main(){
  int arr[100],i,n,search,flag=0;
  printf("Enter the no of array elements: ");
  scanf("%d",&n);
  printf("Enter the Array elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the Element to be found: ");
  scanf("%d",&search);
  for(i=0;i<n;i++){
    if(arr[i]==search){
      flag=1;break;
    }
  }
  if(flag==1)printf("%d is found at index %d",search,i);
  else printf("%d is not found in the Array",search);
  return 0;
}
