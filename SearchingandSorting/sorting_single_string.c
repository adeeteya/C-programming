#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printarray(char arr[],int n){
  int i;
  for(i=0;i<=n;i++)
    printf("%c",arr[i]);
  printf("\n");
}
void swap(char *a,char *b){
  char temp=*a;
  *a=*b;
  *b=temp;
}
int partition(char arr[],int start,int end){
  int i=start-1,j;
  char pivot=arr[end];
  for(j=start;j<=end-1;j++){
    if(arr[j]<pivot){
      swap(&arr[++i],&arr[j]);
      printarray(arr,end);
    }
  }
  swap(&arr[i+1],&arr[end]);
  printarray(arr,end);
  return i+1;
}
void quickSort(char arr[],int start,int end){
  if(start<end){
    int pindex=partition(arr,start,end);
    quickSort(arr,start,pindex-1);
    quickSort(arr,pindex+1,end);
  }
}

int main(){
  char *arr;
  arr=(char *)malloc(100);
  printf("Enter the String\n");
  scanf("%s",arr);
  int n=strlen(arr);
  realloc(arr,n+1);
  printf("Sorting Steps:\n");
  quickSort(arr,0,n-1);
  printf("The Final Sorted String is: \n");
  printarray(arr,n-1);
  free(arr);
  return 0;
}
