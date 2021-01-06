#include<stdio.h>
#include<string.h>
#define MAX 20
int main(){
  int i,n,flag=0;
  printf("Enter the no of books: ");
  scanf("%d",&n);
  char books[n][MAX],search[MAX];
  printf("Enter the books\n");
  fflush(stdin);
  for(i=0;i<n;i++)
    gets(books[i]);
  printf("Enter the book to be searched: ");
  gets(search);
  for(i=0;i<n;i++){
    if(strcmp(books[i],search)==0){
      flag=1;break;
    }
  }
  if(flag==1)printf("The Book was found at position %d",i+1);
  else printf("The Book was not found");
  return 0;
}
