#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
  char data[20];
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
    printf("\t\tBank Queue Management System\n");
    printf("1.Add a person to the Queue\n2.Remove the first person from the Queue\n3.First Person in the queue\n4.Last person in the Queue\n5.Display the people in the queue\n6.Delete the queue\n7.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:enqueue();break;
      case 2:dequeue();break;
      case 3:if(isEmpty())printf("There is Nobody in the Queue\n");else printf("The First Person in the queue is %s",front->data);printf("\nPress any key to continue");getch();break;
      case 4:if(isEmpty())printf("There is Nobody in the Queue\n");else printf("The Last Person in the queue is %s",rear->data);printf("\nPress any key to continue");getch();break;
      case 5:display();break;
      case 6:delete();break;
      case 7:exit(0);break;
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
  printf("Enter the name: ");
  fflush(stdin);
  gets(newnode->data);
  newnode->next=NULL;
  if(isEmpty())
    front=newnode;
  else
    rear->next=newnode;
  rear=newnode;
  printf("%s has been added to the queue successfully",rear->data);
  printf("\nPress any key to continue");getch();
}
void dequeue(){
  if(isEmpty())
    printf("There is Nobody in the Queue!");
  else{
    queue *delnode=front;
    front=front->next;
    printf("%s has been removed from the Queue",delnode->data);
    free(delnode);
    if(front==NULL)rear=NULL;
  }
  printf("\nPress any key to continue");getch();
}
void display(){
  if(isEmpty())
    printf("There is Nobody in the Queue!");
  else{
    queue *temp=front;
    printf("The People in the Queue are:\n");
    while(temp!=NULL){
      printf("%s\n",temp->data);
      temp=temp->next;
    }
  }
  printf("\nPress any key to continue");getch();
}
void delete(){
  if(isEmpty())
    printf("There is Nobody in the Queue!");
  else{
    queue *delnode=front;
    while(delnode!=NULL){
      front=front->next;
      free(delnode);
      delnode=front;
    }rear=NULL;
    printf("Everyone has been removed from the Queue Successfully");
  }
  printf("\nPress any key to continue");getch();
}
