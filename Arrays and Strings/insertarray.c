#include<stdio.h>
//Program to insert array elements by Aditya.R
int main(){
  int i,n,pos,val,arr[100];
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the position to insert: ");
  scanf("%d",&pos);
  printf("Enter the value to insert: ");
  scanf("%d",&val);
  for(i=n-1;i>=pos;i--)
    arr[i+1]=arr[i];
  arr[pos]=val;n++;
  printf("Updated Array\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}
