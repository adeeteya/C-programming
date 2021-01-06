#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  char *str,substr[20],newword[20],*psubstr;
  str=(char*)malloc(100);
  printf("Enter a string\n");
  scanf("%[^\n]s",str);
  realloc(str,strlen(str)+1);
  printf("Enter a substring to be found: ");
  scanf("%s",substr);
  psubstr=strstr(str,substr);
  if(psubstr==NULL){
    printf("Substring not found");
    return 0;
  }
  printf("Enter the new word to replace: ");
  scanf("%s",newword);
  char *newstr;
  newstr=(char*)malloc(strlen(str)-strlen(substr)+strlen(newstr)+1);
  int i=0,j=0;
  while(psubstr!=str+i){
    *(newstr+i)=*(str+i);
    i++;
  }
  while(newword[j]!='\0'){
    *(newstr+i)=newword[j];
    i++;j++;
  }
  psubstr=psubstr+strlen(substr);j=0;
  while(*(psubstr+j)!='\0'){
    *(newstr+i)=*(psubstr+j);
    i++;j++;
  }
  newstr[i]='\0';
  strcpy(str,newstr);
  printf("The new String is \n%s",str);
  free(newstr);free(str);
  return 0;
}
