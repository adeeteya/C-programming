#include<stdio.h>
#include<conio.h>
int main(){
  char c,filename[20];
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File does not exist");
    return 1;
  }
  fseek(ptr,-50,SEEK_END);
  while((c=fgetc(ptr))!=EOF){
    printf("%c",c);
  }
  fclose(ptr);
}
