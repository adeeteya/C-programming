#include<stdio.h>
int main(){
  int n,i,search;
  printf("Enter the no of employee: ");
  scanf("%d",&n);
  int employee[n],salary[n];
  for(i=0;i<n;i++){
    scanf("%d %d",&employee[i],&salary[i]);
  }
  printf("Enter employee no: ");
  scanf("%d",&search);
  for(i=0;i<n;i++){
    if(employee[i]==search){
      printf("salary= %d",salary[i]);
      break;
    }
  }
}
