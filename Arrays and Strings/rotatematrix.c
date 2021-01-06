#include <stdlib.h>
#include <stdio.h>
int main(){
  int i,j,n,k,temp;
  printf("Input the value of n: ");
  scanf("%d",&n);
  int arr[n][n],arrtrans[n][n];
  printf("Input the matrix\n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&arr[i][j]);
  printf("The Matrix is \n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      printf("%d\t",arr[i][j]);
    printf("\n");
  }
  printf("The Matrix After 90 degree Rotataion(Clockwise) is\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      arrtrans[j][i]=arr[i][j];
    }
  }
  for(i=0;i<n;i++){
    k=n-1;
    for(j=0;j<k;j++){
      temp=arrtrans[i][j];
      arrtrans[i][j]=arrtrans[i][k];
      arrtrans[i][k]=temp;
      k--;
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      printf("%d\t",arrtrans[i][j]);
    printf("\n");
  }
  printf("The Matrix After 90 degree Rotataion(Anti-Clockwise) is\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      arrtrans[j][i]=arr[i][j];
    }
  }
  for(i=0;i<n;i++){
    k=n-1;
    for(j=0;j<k;j++){
      temp=arrtrans[j][i];
      arrtrans[j][i]=arrtrans[k][i];
      arrtrans[k][i]=temp;
      k--;
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      printf("%d\t",arrtrans[i][j]);
    printf("\n");
  }
  return 0;
}
