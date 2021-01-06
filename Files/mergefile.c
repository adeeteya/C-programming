#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *fptr1,*fptr2,*fptr3;
  char ch,fname1[20],fname2[20],fname3[30];
  printf("Merge two files and write it in a new file:\n");
  printf("Input the 1st file name: \n");
  scanf("%s",fname1);
  printf("Input the 2nd file name: \n");
  scanf("%s",fname2);
  printf("Input the new file name where to merge the above two files: ");
  scanf("%s",fname3);
  fptr1 = fopen(fname1,"r");
  fptr2 = fopen(fname2,"r");
  if(fptr1==NULL||fptr2==NULL){
    printf("File does not exist or error in opening\n");
    return 0;
  }
  fptr3=fopen(fname3,"w");
  if(fptr3==NULL){
    printf("File does not exist or error in opening.\n");
    return 0;
  }
  while((ch=fgetc(fptr1))!=EOF){
    fputc(ch,fptr3);
  }
  while((ch=fgetc(fptr2))!=EOF){
    fputc(ch,fptr3);
  }
  printf("The two files merged into %s file successfully\n\n",fname3);
  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr3);
}
