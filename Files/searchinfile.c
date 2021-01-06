#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(){
  char *word,filename[20],search[20],line[100];
  printf("Enter the name of the file(with extension): ");
  scanf("%s",filename);
  FILE *ptr=fopen(filename,"r");
  if(ptr==NULL){
    printf("File does not exist");
    return 1;
  }
  printf("Enter the word to be searched: ");
  scanf("%s",search);
  int wordno=0,lineno=0;
  while((fgets(line,100,ptr))!=NULL){
    wordno=0;int c,i=0,nwords=0;
    word=strtok(line," ");
    c=*(word);
    while(c!='\n'){
      if(c==' ')nwords++;
      c=*(word+i);
      i++;
    }
    while(word!=NULL){
      if(wordno==nwords){
        word=strtok(NULL,"\n");
        wordno++;
      }
      if(strcmp(word,search)==0){
        printf("The word is found at line no:%d , word no:%d",lineno+1,wordno+1);
        fclose(ptr);
        return 0;
      }
      word=strtok(NULL," ");
      wordno++;
    }
    lineno++;
  }
  printf("Word Not found");
  fclose(ptr);
}
