#include<stdio.h>
#include<string.h>

int main(){
  FILE *ptr1,*ptr2;
  char filename[20],word1[20],word2[20];
  printf("Enter the name of the file1(with extension): ");
  scanf("%s",filename);
  ptr1=fopen(filename,"r");
  if(ptr1==NULL){
    printf("File does not exist");
    return 1;
  }
  printf("Enter the name of the file2(with extension): ");
  scanf("%s",filename);
  ptr2=fopen(filename,"r");
  if(ptr2==NULL){
    printf("File 2 does not exist");
    return 1;
  }
  while(!(feof(ptr1) && feof(ptr2))){
    fscanf(ptr1,"%s",word1);
    fscanf(ptr2,"%s",word2);
    if(strcmp(word1,word2)!=0){
      printf("Both File's are not the same");
      fclose(ptr1);fclose(ptr2);
      return 1;
    }
  }
  printf("Both the files are the same");
  fclose(ptr1);fclose(ptr2);
}
