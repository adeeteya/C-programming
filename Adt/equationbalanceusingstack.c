#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct{
  char stack[MAX];
  int top;
}s;

void push(char item){
  if(s.top==(MAX-1))
    printf("Stack is Full\n");
  else{
    s.top=s.top+1;
    s.stack[s.top]=item;
  }
}

void pop(){
  if(s.top==-1)
    printf("Stack is Empty\n");
  else
    s.top=s.top-1;
}

int main(){
  char exp[MAX];
  int i=0;
  s.top=-1;
  printf("Enter the Expression: ");
  scanf("%s",exp);
  for(i=0;i<strlen(exp);i++){
    if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
      push(exp[i]);
    else if(exp[i]==')'){
      if(s.stack[s.top]=='(')
        pop();
      else{
        s.top=0;break;
      }
    }
    else if(exp[i]=='}'){
      if(s.stack[s.top]=='{')
        pop();
      else{
        s.top=0;break;
      }
    }
    else if(exp[i]==']'){
      if(s.stack[s.top]=='[')
        pop();
      else{
        s.top=0;break;
      }
    }
  }
  if(s.top==-1)
    printf("The Expression is Balanced.");
  else
    printf("The Expression is not balanced.");
  return 0;
}
