#include<stdio.h>
//Program by Aditya.R to remove duplicate array elements
int main(){
  int i,n,j,k;
  printf("Enter the number of array elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Updated Array:\n");
  for(i=0;i<n;i++){
    for(j=i+1;j<n-1;j++){
      if(arr[i]==arr[j]){
        for(k=j;k<n-1;k++)
          arr[k]=arr[k+1];
        n-=1;
      }
    }
    if(arr[i]==arr[n-1] && i!=n-1)
      n-=1;
  }
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}
