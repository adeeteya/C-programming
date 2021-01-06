#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
  char filename[20];
  int i=0,c;
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  FILE *f1=fopen(filename,"r");
  if(f1==NULL){
    printf("File does not exist");
    return 1;
  }
  char *str=(char*)malloc(1000);
  memset(str,'\0',1000);
    c=fgetc(f1);
    while(c!=EOF){
    str[i]=c;
    c=getc(f1);i++;
  }
  realloc(str,strlen(str)+1);
  fclose(f1);
  FILE *f2=fopen("output.txt","w+");
  for(i=strlen(str)-1;i>=0;i--){
    fputc((int)str[i],f2);
  }
  printf("File Reversed Successfully");
  fclose(f2);free(str);
  return 0;
}
