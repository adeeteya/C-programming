#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  char data[20];
  struct node *next;
}*head;
typedef struct node NODE;

void insert(char name[20],int pos);
void display(int pos);
void search_S();
void delete_red();

int main(){
  char name[20];
  int i=0,j=1;
  printf("Enter the members of the red team\n");
  for(i=0;i<11;i++){
    gets(name);
    if(i==0 && name[0]!='A'){
      printf("The name of the captain must start with only A,Please try again\n");
      i=-1;continue;
    }
    else if(i==10 && name[0]!='Z'){
      printf("The name of the last player must start with only Z,Please try again\n");
      i-=1;continue;
    }
    insert(name,i);
  }
  printf("\nName list(Red team members):\n");
  for(i=0;i<11;i++)
    display(i);
  printf("\nEnter the members of the blue team\n");
  for(i=0;i<11;i++){
    gets(name);
    if(i==0 && name[0]!='A'){
      printf("The name of the captain must start with only A,Please try again\n");
      i=-1;continue;
    }
    else if(i==10 && name[0]!='Z'){
      printf("The name of the last player must start with only Z,Please try again\n");
      i-=1;continue;
    }
    insert(name,j);j+=2;
  }
  printf("Player name at position 2 is ");display(2);
  printf("Player name at position 5 is ");display(5);
  printf("Player name at position 7 is ");display(7);
  printf("Player name at position 10 is ");display(10);
  printf("\nName and position of the team members whoose name starts with S\n");
  search_S();
  printf("\nName list(including blue team):\n");
  for(i=0;i<22;i++)
    display(i);
  delete_red();
  printf("\nName list(After Deleting Red team members):\n");
  for(i=0;i<11;i++)
    display(i);
  return 0;
}

void insert(char name[20],int pos){
  NODE *newnode;
  newnode=(NODE *)malloc(sizeof(NODE));
  strcpy(newnode->data,name);
  if(head==NULL){
    head=newnode;newnode->next=NULL;
  }
  else{
    NODE *temp=head;
    int i=0;
    while(i!=pos-1){
      temp=temp->next;
      i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
  }
  return;
}
void display(int pos){
  int i=0;
  NODE *temp=head;
  for(i=0;i<pos;i++)
    temp=temp->next;
  printf("%s\n",temp->data);
}
void search_S(){
  int i=0;
  NODE *temp=head;
  while(temp!=NULL){
    if(temp->data[0]=='S')
      printf("Name:%s\tPosition:%d\n",temp->data,i);
    temp=temp->next;i++;
  }
}
void delete_red(){
  NODE *delnode=head,*temp=head->next;
  free(delnode);head=temp;
  while(temp->next!=NULL){
    delnode=temp->next;
    temp->next=delnode->next;
    temp=temp->next;
    free(delnode);
  }
}
