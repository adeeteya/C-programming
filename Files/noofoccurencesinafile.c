#include<stdio.h>
#include<string.h>
int main(){
  char filename[20],word[20],search[20];
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File does not exist");
    return 1;
  }
  printf("Enter the word to be searched: ");
  scanf("%s",search);
  int count=0;
  while((fscanf(ptr,"%s",word)!=EOF)){
    if(strcmp(word,search)==0)
      count++;
  }
  printf("The no of occurences of the given word are: %d",count);
  fclose(ptr);
}
