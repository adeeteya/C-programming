#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int menu();
int menuchoice(){
  int choice;
  printf("\n---------------------------------------------------------");
  printf("\nReturn to the main menu(1 for yes anything else for no): ");
  scanf("%d",&choice);
  if(choice==1)menu();
  else  return 0;
}
int open(){
  system("cls");
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File Does not exist");free(filename);
    fclose(ptr);
    menuchoice();return 0;
  }
  while(!feof(ptr))
    printf("%c",fgetc(ptr));
  free(filename);fclose(ptr);
  menuchoice();
  return 0;
}
int write(){
  system("cls");
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"w+");
  if(ptr==NULL){
    printf("File Unable to Write");free(filename);
    fclose(ptr);
    menuchoice();return 0;
  }
  char *line=(char*)malloc(100);int choice=1;
  while(choice==1){
    printf("Enter the line\n");
    fflush(stdin);
    scanf("%[^\n]s",line);
    fputs(line,ptr);
    fputs("\n",ptr);
    printf("Enter another line?(1 for yes anything else for no): ");
    scanf("%d",&choice);
  }
  printf("\nFile Written Successfully");
  free(filename);free(line);fclose(ptr);
  menuchoice();
  return 0;
}
int append(){
  system("cls");
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"a");
  if(ptr==NULL){
    printf("File Does not exist");free(filename);
    fclose(ptr);
    menuchoice();return 0;
  }
  char *line=(char*)malloc(100);int choice=1;
  while(choice==1){
    printf("Enter the line\n");
    fflush(stdin);
    scanf("%[^\n]s",line);
    fputs(line,ptr);
    fputs("\n",ptr);
    printf("Enter another line?(1 for yes anything else for no): ");
    scanf("%d",&choice);
  }
  printf("\nFile Written Successfully");
  free(filename);free(line);fclose(ptr);
  menuchoice();
  return 0;
}
int renamefile(){
  system("cls");
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File Does not exist");free(filename);
    fclose(ptr);
    menuchoice();return 0;
  }
  char *newfilename=(char*)malloc(20);
  printf("Enter the new name of the file(with extension): ");
  scanf("%s",newfilename);
  realloc(filename,strlen(filename)+1);
  fclose(ptr);
  if(rename(filename,newfilename)==0)printf("File Renamed Successfully.");
  else printf("Unable to Rename file");
  free(filename);free(newfilename);
  menuchoice();
  return 0;
}
int copy(){
  system("cls");
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File Does not exist");free(filename);
    fclose(ptr);
    menuchoice();return 0;
  }
  char *newfilename=(char*)malloc(20);
  printf("Enter the new name of the file(with extension): ");
  scanf("%s",newfilename);
  realloc(filename,strlen(filename)+1);
  FILE *newptr=fopen(newfilename,"w+");
  while(!feof(ptr))
    fprintf(newptr,"%c",fgetc(ptr));
  printf("File Copied Succesfully\n");
  free(filename);free(newfilename);fclose(ptr);fclose(newptr);
  menuchoice();
  return 0;
}
int delete(){
  system("cls");
  char *filename=(char*)malloc(20);
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  realloc(filename,strlen(filename)+1);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File Does not exist");free(filename);
    fclose(ptr);
    menuchoice();return 0;
  }
  fclose(ptr);
  if(remove(filename)==0)printf("File removed Successfully");
  else printf("Error Unable to remove file");
  free(filename);
  menuchoice();return 0;
}
int menu(){
  system("cls");
  int choice;
  printf("------Menu------\n");
  printf("|1.Open\t\t|\n|2.Write\t|\n|3.Append\t|\n|4.Rename\t|\n|5.Copy\t\t|\n|6.Delete\t|\n|7.Exit\t\t|");
  printf("\n-----------------\nEnter your choice: ");
  scanf("%d",&choice);
  switch(choice){
    case 1:open();break;
    case 2:write();break;
    case 3:append();break;
    case 4:renamefile();break;
    case 5:copy();break;
    case 6:delete();break;
    case 7:return 0;break;
    default:printf("Invalid Input,try again(press anything) ");getch();menu();
  }
  return 0;
}
int main(){
  menu();
}
