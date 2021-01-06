#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
  int data;//contains data of the node
  struct node *next;//pointer to next location
}*head,*tail;
typedef struct node NODE;

void insert_beginning();
void insert_middle();
void insert_end();
void delete_beginning();
void delete_middle();
void delete_end();
void search();
void display();

int main(){
  int choice;
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:system("cls");
      printf("Insert at what Position?\n");
      printf("1.Beginning\n2.End\n3.Any other position\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      if(choice==1)insert_beginning();
      else if(choice==2)insert_end();
      else if(choice==3)insert_middle();
      else printf("Invalid option");break;
      case 2:system("cls");
      printf("Delete at what Position?\n");
      printf("1.Beginning\n2.End\n3.Any other position\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      if(choice==1)delete_beginning();
      else if(choice==2)delete_end();
      else if(choice==3)delete_middle();
      else printf("Invalid option");break;
      case 3:search();break;
      case 4:display();break;
      case 5:exit(0);break;
      default:printf("Invalid input");
      printf("\n\nPress any key to try again...");getch();
    }
  }
  return 0;
}

void insert_beginning(){
  NODE *newnode;
  newnode=(NODE *)malloc(sizeof(NODE));
  printf("\nEnter the value of the new node: ");
  scanf("%d",&newnode->data);
  if(head==NULL){
    newnode->next=newnode;
    head=newnode;tail=newnode;
  }
  else{
    newnode->next=head;
    tail->next=newnode;
    head=newnode;
  }
  printf("Node Successfully inserted at the beginning");
  printf("\n\nPress any key to return to the main menu...");getch();return;
}

void insert_middle(){
  NODE *newnode,*temp=head;
  newnode=(NODE *)malloc(sizeof(NODE));
  printf("\nEnter the value of the new node: ");
  scanf("%d",&newnode->data);
  if(head==NULL){
    newnode->next=newnode;
    head=newnode;tail=newnode;
    printf("Node inserted at the 0th position as linked list was empty");
  }
  else{
    int i=0,pos,flag=0;
    printf("Enter the position to insert the node(starts at zero): ");
    scanf("%d",&pos);
    if(pos==0){
      newnode->next=head;
      tail->next=newnode;
      head=newnode;flag=1;
    }
    else{
      while(temp!=tail){
        if(i==pos-1){
          newnode->next=temp->next;
          temp->next=newnode;
          flag=1;break;
        }
        temp=temp->next;i++;
      }
      if(i==pos-1 && temp->next==head){
        newnode->next=temp->next;
        temp->next=newnode;
        flag=1;
        tail=newnode;
      }
    }
    (flag==1)?printf("Node Successfully inserted at position %d",pos):printf("Given position does not exist");
  }
  printf("\n\nPress any key to return to the main menu...");getch();return;
}

void insert_end(){
  NODE *newnode,*temp=head;
  newnode=(NODE *)malloc(sizeof(NODE));
  printf("\nEnter the value of the new node: ");
  scanf("%d",&newnode->data);
  if(head==NULL)
    head=newnode;
  else{
    while(temp!=tail)
      temp=temp->next;
    temp->next=newnode;
  }
  newnode->next=head;
  tail=newnode;
  printf("Node Successfully inserted at the end");
  printf("\n\nPress any key to return to the main menu...");getch();return;
}

void delete_beginning(){
  NODE *temp=head;
  if(head==NULL)
    printf("\nThe linked list is empty...");
  else if(head->next==head){
    free(temp);
    head=NULL;tail=NULL;
    printf("Node Successfully deleted");
  }
  else{
    head=(head)->next;
    free(temp);
    tail->next=head;
    printf("Node Successfully deleted");
  }
  printf("\n\nPress any key to return to the main menu...");getch();return;
}

void delete_middle(){
  NODE *temp=head,*delete;
  int i=0,pos,flag=0;
  if(head==NULL){
    printf("\nThe linked list is empty...");
    printf("\n\nPress any key to return to the main menu...");getch();return;
  }
  else{
    printf("Enter the position to delete(starts from zero): ");
    scanf("%d",&pos);
    if(pos==0){
      if(head->next==head){
        head=NULL;tail=NULL;
        free(temp);flag=1;
      }
      else{
        head=head->next;
        free(temp);flag=1;
        tail->next=head;
      }
    }
    else{
      while(temp!=tail){
        if(i==pos-1 && temp->next!=head){
          delete=temp->next;
          temp->next=delete->next;
          free(delete);
          if(temp->next==head)
            tail=temp;
          flag=1;break;
        }
        temp=temp->next;i++;
      }
    }
  }
  (flag==1)?printf("Node Successfully deleted at position %d",pos):printf("Invalid Position");
  printf("\n\nPress any key to return to the main menu...");getch();return;
}

void delete_end(){
  NODE *temp=head;
  if(head==NULL)
    printf("\nThe linked list is empty...");
  else if(head->next==head){
    free(temp);
    head=NULL;tail=NULL;
    printf("Node Successfully deleted");
  }
  else{
    while(temp->next!=tail)
      temp=temp->next;
    free(temp->next);
    temp->next=head;
    tail=temp;
    printf("Node Successfully deleted");
  }
  printf("\n\nPress any key to return to the main menu...");getch();return;
}

void search(){
  NODE *temp=head;
  system("cls");
  if(temp==NULL)
    printf("Linked list is Empty");
  else{
    int search,flag=0,i=0;
    printf("Enter the item to be searched: ");
    scanf("%d",&search);
    while(temp!=tail){
      if(temp->data==search){
        printf("%d found at position %d\n",search,i);
        flag=1;
      }
      temp=temp->next;i++;
    }
    if(temp->data==search){
      printf("%d found at position %d\n",search,i);
      flag=1;
    }
    if(flag==0)printf("%d not present in the linked list\n",search);
  }
  printf("\n\nPress any key to return to the main menu......");getch();return;
}

void display(){
  system("cls");
  NODE *temp=head;
  if(temp==NULL)
    printf("Linked list is Empty");
  else{
    printf("The contents of the linked list are:\n");
    while(temp!=tail){
      printf("%d\n",temp->data);
      temp=temp->next;
    }
    printf("%d\n",temp->data);
  }
  printf("\n\nPress any key to return to the main menu......");getch();return;
}
