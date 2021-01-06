#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10
int Queue[MAX],front=-1,rear=-1;

int isEmpty();
int isFull();
void enqueue();
void dequeue();
void display();
void delete();

int main(){
  int choice;
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.Display the queue\n6.Delete the queue\n7.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:enqueue();break;
      case 2:dequeue();break;
      case 3:if(isEmpty())printf("The queue is Empty\n");else printf("The queue is not Empty\n");printf("\nPress any key to continue");getch();break;
      case 4:if(isFull())printf("The queue is Full\n");else printf("The queue is not Full\n");printf("\nPress any key to continue");getch();break;
      case 5:display();break;
      case 6:delete();break;
      case 7:exit(0);break;
      default:printf("Invalid Input,Press any key to try again..");getch();
    }
  }
}

int isEmpty(){
  if(front==-1 || front>rear)
    return 1;
  else
    return 0;
}
int isFull(){
  if(rear==MAX-1)
    return 1;
  else
    return 0;
}
void enqueue(){
  if(isFull())
    printf("Queue Overflow");
  else{
    if(isEmpty())
      front=0;
    rear+=1;
    printf("Enter the value to be inserted: ");
    scanf("%d",&Queue[rear]);
    printf("%d has been inserted into the queue successfully",Queue[rear]);
  }
  printf("\nPress any key to continue");getch();
}
void dequeue(){
  if(isEmpty())
    printf("Queue Underflow");
  else{
    printf("Deleted Element: %d",Queue[front]);
    front+=1;
    if(front>rear){front=rear=-1;}
  }
  printf("\nPress any key to continue");getch();
}
void display(){
  if(isEmpty())
    printf("The Queue is Empty!");
  else{
    int i;
    printf("The Elements of The Queue are:\n");
    for(i=front;i<=rear;i++)
      printf("%d\n",Queue[i]);
  }
  printf("\nPress any key to continue");getch();
}
void delete(){
  if(isEmpty())
    printf("Queue Underflow");
  else{
    front=rear=-1;
    printf("Queue Deleted Successfully");
  }
  printf("\nPress any key to continue");getch();
}
