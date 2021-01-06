#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
  int data;
  struct node *next;
}*front,*rear;
typedef struct node queue;

int isEmpty();
void enqueue();
void dequeue();
void display();
void delete();

int main(){
  int choice;
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Enqueue\n2.Dequeue\n3.isEmpty\n4.Element At Front\n5.Element at rear\n6.Display the queue\n7.Delete the queue\n8.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:enqueue();break;
      case 2:dequeue();break;
      case 3:if(isEmpty())printf("The queue is Empty\n");else printf("The queue is not Empty\n");printf("\nPress any key to continue");getch();break;
      case 4:if(isEmpty())printf("The queue is Empty\n");else printf("The Element at front is %d",front->data);printf("\nPress any key to continue");getch();break;
      case 5:if(isEmpty())printf("The queue is Empty\n");else printf("The Element at rear is %d",rear->data);printf("\nPress any key to continue");getch();break;
      case 6:display();break;
      case 7:delete();break;
      case 8:exit(0);break;
      default:printf("Invalid Input,Press any key to try again..");getch();
    }
  }
}

int isEmpty(){
  if(front==NULL)
    return 1;
  else
    return 0;
}

void enqueue(){
  queue *newnode;
  newnode=(queue *)malloc(sizeof(queue));
  printf("Enter the value to be inserted: ");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(isEmpty())
    front=newnode;
  else
    rear->next=newnode;
  rear=newnode;
  printf("%d has been inserted into the queue successfully",rear->data);
  printf("\nPress any key to continue");getch();
}
void dequeue(){
  if(isEmpty())
    printf("Queue Underflow");
  else{
    queue *delnode=front;
    front=front->next;
    printf("Deleted Element: %d",delnode->data);
    free(delnode);
    if(front==NULL)rear=NULL;
  }
  printf("\nPress any key to continue");getch();
}
void display(){
  if(isEmpty())
    printf("The Queue is Empty!");
  else{
    queue *temp=front;
    printf("The Elements of The Queue are:\n");
    while(temp!=NULL){
      printf("%d\n",temp->data);
      temp=temp->next;
    }
  }
  printf("\nPress any key to continue");getch();
}
void delete(){
  if(isEmpty())
    printf("Queue Underflow");
  else{
    queue *delnode=front;
    while(delnode!=NULL){
      front=front->next;
      free(delnode);
      delnode=front;
    }rear=NULL;
    printf("Queue Deleted Successfully");
  }
  printf("\nPress any key to continue");getch();
}
