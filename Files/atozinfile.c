#include<stdio.h>

int main(){
  int choice,i,n;
  FILE *ptr=fopen("atoz.txt","w");
  printf("Enter 1 to print uppercase and anything else to print lowercase\n");
  scanf("%d",&choice);
  if(choice==1) i='A';
  else i='a';
  n=i+25;
  for(;i<=n;i++)
  fprintf(ptr,"%c\n",i);
  fclose(ptr);
}
