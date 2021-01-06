#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int top=-1,SIZE;
int isEmpty();
int isFull(int SIZE);
int size();
void push(int *stack,int SIZE);
void pop(int *stack);
void peek(int *stack);
void display(int *stack);
void delete();

int main(){
  int choice;
  printf("Enter the size of the Stack: ");
  scanf("%d",&SIZE);
  int stack[SIZE];
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Size\n5.Display\n6.isEmpty\n7.isFull\n8.Delete the stack\n9.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:push(stack,SIZE);printf("Press any key to continue");getch();break;
      case 2:pop(stack);printf("Press any key to continue");getch();break;
      case 3:peek(stack);printf("Press any key to continue");getch();break;
      case 4:printf("Size of the stack= %d\nPress any key to continue",size());getch();break;
      case 5:display(stack);printf("Press any key to continue");getch();break;
      case 6:if(isEmpty())printf("The stack is Empty\n");else printf("The stack is not Empty\n");printf("Press any key to continue");getch();break;
      case 7:if(isFull(SIZE))printf("The stack is Full\n");else printf("The stack is not Full\n");printf("Press any key to continue");getch();break;
      case 8:delete();printf("Press any key to continue");getch();break;
      case 9:exit(0);break;
      default:printf("Invalid Input,Press any key to try again");getch();
    }
  }
}

int isEmpty(){
  if(top==-1)
    return 1;
  else
    return 0;
}
int isFull(int SIZE){
  if(size()>=SIZE)
    return 1;
  else
    return 0;
}
int size(){
  return top+1;
}
void push(int *stack,int SIZE){
  if(isFull(SIZE))
    printf("Stack Overflow\n");
  else{
    int data;
    printf("Enter the value of new element: ");
    scanf("%d",&data);
    *(stack+(++top))=data;
    printf("%d successfully inserted into the stack\n",data);
  }
}
void pop(int *stack){
  if(isEmpty())
    printf("Stack Underflow\n");
  else
    printf("Popped element=%d\n",*(stack+(top--)));
}
void peek(int *stack){
  if(isEmpty())
    printf("Stack Underflow\n");
  else
    printf("Element at the top is %d\n",*(stack+top));
}
void display(int *stack){
  if(isEmpty())
    printf("Stack is Empty\n");
  else{
    int i=0;
    printf("The elements of the stack are\n");
    for(i=top;i>=0;i--)
      printf("%d\n",*(stack+i));
  }
}
void delete(){
  if(isEmpty())
    printf("The Stack is already Empty\n");
  else{
    top=-1;printf("The Stack has been deleted successfully\n");
  }
}
