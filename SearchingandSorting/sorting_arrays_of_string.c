#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
//using quicksort algorithm

void printarray(char arr[][MAX],int n){
  int i=0;
  printf("-------------------The Change in this step are------------\n");
  for(i=0;i<=n;i++)
    printf("%s\n",arr[i]);
}
void swap(char *a,char *b){
  char *temp=(char *)malloc(strlen(a)+1);
  strcpy(temp,a);
  strcpy(a,b);
  strcpy(b,temp);
  free(temp);
}
int partition(char arr[][MAX],int start,int end){
  int i=start-1,j;
  char *pivot=(char *)malloc(strlen(arr[end]));
  strcpy(pivot,arr[end]);
  for(j=start;j<=end-1;j++){
    if(strcmp(arr[j],pivot)<0){
      swap(arr[++i],arr[j]);
      printarray(arr,end);
    }
  }
  swap(arr[i+1],arr[end]);
  printarray(arr,end);
  free(pivot);
  return i+1;
}
void quickSort(char arr[][MAX],int start,int end){
  if(start<end){
    int pindex=partition(arr,start,end);
    quickSort(arr,start,pindex-1);
    quickSort(arr,pindex+1,end);
  }
}

int main(){
  int i,n;
  printf("Enter the no of strings: ");
  scanf("%d",&n);
  char arr[n][MAX];
  printf("Enter the Strings\n");
  for(i=0;i<n;i++){
    fflush(stdin);
    gets(arr[i]);
  }
  printf("The Sorted Strings Are:\n");
  quickSort(arr,0,n-1);
  printf("\nThe Final Sorted Strings array: \n");
  for(i=0;i<n;i++)
    printf("%s\n",arr[i]);
  return 0;
}
