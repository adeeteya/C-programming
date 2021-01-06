#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
  int choice;char c;
  printf("Enter 1 to encrypt a file and 2 to Decrypt a file: ");
  scanf("%d",&choice);
  if(choice!=1 && choice!=2){
    printf("Invalid Choice");
    system("cls");main();return 0;
  }
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file: ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File doesn't exist");
    return 0;
  }
  FILE *ptr2=fopen("temp.txt","w+");
  if(ptr2==NULL){
    printf("Unable to Write to the file");
    return 0;
  }
  if(choice==1){
    c=fgetc(ptr);
    while(c!=EOF){
      fputc(c+100,ptr2);
      c=fgetc(ptr);
    }
    printf("File Successfully Encrypted");
  }
  else if(choice==2){
    c=fgetc(ptr);
    while(c!=EOF){
      fputc(c-100,ptr2);
      c=fgetc(ptr);
    }
    printf("File Successfully Decrypted");
  }
  fclose(ptr);fclose(ptr2);
  remove(filename);
  rename("temp.txt",filename);
  free(filename);
  return 0;
}
