#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Program by Aditya.R
int main(){
  int i,j,n;
  printf("Enter the number of strings: ");
  scanf("%d",&n);
  char str[n][100],temp[100];
  printf("Enter the Strings\n");
  for(i=0;i<n;i++){
    scanf("%s",str[i]);
  }
  printf("The Sorted Strings are\n");
  for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++){
       if(strcmp(str[j],str[j+1])>0){
         strcpy(temp,str[j]);
         strcpy(str[j],str[j+1]);
         strcpy(str[j+1],temp);
       }
    }
  }
  for(i=0;i<n;i++)
    printf("%s\n",str[i]);
}
