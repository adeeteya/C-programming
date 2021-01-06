#include<stdio.h>
#include<stdlib.h>
struct node{
  float data;
  struct node *next;
}*top;
typedef struct node stack;

stack* Create();//creates a node
void Push();//pushes a node to the stack
void Pop();//removes the element at top of the stack
void Top();//displays the element at the top of the stack
void Display();//display's the whole stack
int main(){
  int choice;
  while(1){
    printf("\t\tMain Menu\n");
    printf("1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit");
    printf("\nEnter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:Push();break;
      case 2:Pop();break;
      case 3:Top();break;
      case 4:Display();break;
      case 5:exit(0);break;
      default:printf("Invalid Input,Please Try Again\n");
    }
  }
  return 0;
}
stack* Create(){
  stack *newnode=(stack *)malloc(sizeof(stack));
  printf("Enter the Diameter of the Plate: ");
  scanf("%f",&newnode->data);
  return newnode;
}
void Push(){
  stack *newnode=Create();
  float val=newnode->data;
  if(top==NULL){
    newnode->next=NULL;
    top=newnode;
  }
  else{
    stack *temp=top;
    while(temp->data<newnode->data && temp->next!=NULL)
      temp=temp->next;
    if(temp->data>newnode->data){
      newnode->data=temp->data;
      temp->data=val;
    }
    newnode->next=temp->next;
    temp->next=newnode;
  }
  printf("%.2f cm successfully inserted into the stack\n",val);
}
void Pop(){
  if(top==NULL)
    printf("Stack is Empty\n");
  else{
    stack *delnode=top;
    top=delnode->next;
    printf("The Popped Element is %.2f cm\n",delnode->data);
    free(delnode);
  }
}
void Top(){
  if(top==NULL)
    printf("The Stack is Empty\n");
  else
    printf("The value of the Element at the top is %.2f cm\n",top->data);
}
void Display(){
  if(top==NULL)
    printf("The Stack is Empty\n");
  else{
    stack *temp=top;
    printf("The Diameters of the plates are:\n");
    while(temp!=NULL){
      printf("%.2f cm\n",temp->data);
      temp=temp->next;
    }
  }
}
