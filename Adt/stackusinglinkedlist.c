#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
  int data;
  struct node *next;
}*top;
typedef struct node stack;

void push();
void pop();
void peek();
void size();
void display();
void delete();

int main(){
  int choice;
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Size\n5.Display\n6.Delete\n7.Exit");
    printf("\nEnter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:push();break;
      case 2:pop();break;
      case 3:peek();break;
      case 4:size();break;
      case 5:display();break;
      case 6:delete();break;
      case 7:exit(0);break;
      default:printf("Invalid Input,Press any key to try again");getch();
    }
  }
  return 0;
}

void push(){
  stack *newnode;
  newnode=(stack *)malloc(sizeof(stack));
  printf("\nEnter The value of the new node: ");
  scanf("%d",&newnode->data);
  if(top==NULL)
    newnode->next=NULL;
  else
    newnode->next=top;
  top=newnode;
  printf("\nPress any key to continue");getch();
}
void pop(){
  if(top==NULL)
    printf("Stack is Empty");
  else{
    stack *delnode=top;
    top=delnode->next;
    printf("The Popped Element is %d",delnode->data);
    free(delnode);
  }
  printf("\nPress any key to continue");getch();
}
void peek(){
  if(top==NULL)
    printf("The Stack is Empty");
  else
    printf("The value of the Element at the top is %d",top->data);
  printf("\nPress any key to continue");getch();
}
void size(){
  stack *temp=top;int count=0;
  while(temp!=NULL){
    temp=temp->next;
    count++;
  }
  printf("The size of the stack is %d",count);
  printf("\nPress any key to continue");getch();
}
void display(){
  if(top==NULL)
    printf("The Stack is Empty");
  else{
    stack *temp=top;
    printf("The Elements of the stack are:\n");
    while(temp!=NULL){
      printf("%d\n",temp->data);
      temp=temp->next;
    }
  }
  printf("\nPress any key to continue");getch();
}

void delete(){
  if(top==NULL)
    printf("The Stack is Already Empty!");
  else{
    stack *delnode=top;
    while(top!=NULL){
      top=top->next;
      free(delnode);
      delnode=top;
    }
    printf("The Stack is Deleted Successfully");
  }
  printf("\nPress any key to continue");getch();
}
