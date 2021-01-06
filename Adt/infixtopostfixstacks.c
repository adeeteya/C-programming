#include<stdio.h>
#include<ctype.h>

char stack[50];
int top = -1;
void push(char x)
{
  stack[++top]=x;
}
char pop()
{
  if(top==-1)
    return -1;
  else
    return stack[top--];
}

int priority(char x)
{
  switch(x){
    case '(':return 0;break;
    case '+':
    case '-':return 1;break;
    case '*':
    case '/':return 2;break;
  }
  return 0;
}

int main()
{
  char exp[50],*c,x;
  printf("Enter the expression: ");
  scanf("%s",exp);
  for(c=exp;*c!='\0';c++){
    if(isalnum(*c))
      printf("%c",*c);
    else if(*c=='(')
      push(*c);
    else if(*c==')')
      while((x=pop())!='(')
        printf("%c",x);
    else{
      while(priority(stack[top])>=priority(*c))
        printf("%c",pop());
      push(*c);
    }
  }
  while(top!=-1)
    printf("%c",pop());
  return 0;
}
