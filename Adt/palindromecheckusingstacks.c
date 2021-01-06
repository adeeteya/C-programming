#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct{
  char s[MAX];
  int top;
}stack;

void push(char c){
  if(stack.top>=MAX)
    printf("OVERFLOW\n");
  else
    stack.s[++stack.top]=c;
}
char pop(){
  if(stack.top==-1)
    printf("UNDERFLOW\n");
  else
    return stack.s[stack.top--];
}

int main(){
  stack.top=-1;//initializing empty stack
  char str[MAX];
  printf("Enter the String: ");
  scanf("%s",str);
  int i,n=strlen(str),flag=1;
  for(i=0;i<n/2;i++)
    push(str[i]);
  if(n%2==1)n=(n/2)+1;
  else n=n/2;
  for(i=n;i<strlen(str);i++){
    if(pop()!=str[i]){
      flag=0;break;
    }
  }
  if(flag==0)printf("The String is not a Palindrome");
  else printf("The String is a Palindrome");
  return 0;
}
