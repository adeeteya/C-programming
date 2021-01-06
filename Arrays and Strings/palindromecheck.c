#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Program by Aditya.R
int main(){
  int i,j,check=1;
  char *str;
  str=(char *)malloc(100);
  printf("Enter the String: ");
  scanf("%s",str);
  str=(char *)realloc(str,strlen(str)+1);
  j=strlen(str)-1;
  for(i=0;i<strlen(str)/2;i++){
    if(str[i]!=str[j]){
      check=0;
      break;
    }
    j--;
  }
  (check==1)?printf("%s is palindromic",str):printf("%s is not palindromic",str);
  free(str);
  return 0;
}
