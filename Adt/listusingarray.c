#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();
int list[20],size;

void main() {
  int ch,size=0,data;
  char g='y';
  do{
    printf("\nMain Menu");
    printf("\n1.Create\n2.Delete\n3.Insert\n4.Display\n5.Exit\n");
    printf("\nEnter your Choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
      create();
      break;
    case 2:
      deletion();
      break;
    case 3:
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
      insert(data);
      printf("\nThe list after insertion\n");
      display();
      break;
    case 4:
      printf("The Elements of the List are:\n");
      display();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("\nEnter the correct choice,Please try again");
    }
    printf("\nDo u want to continue(y to continue): ");
    scanf("\n%c",&g);
  }
  while(g=='y'||g=='Y');
  getch();
}

void create(){
  int i,n;
  printf("\nEnter the number of nodes: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("\nEnter the Element in ascending order: ");
    scanf("%d",&list[i]);
  }
  size=n;
}

void insert(int data){
  if(data<600||data>699){
    printf("Operations in 600's range only\n");
    return;
  }
  int i,pos;
  for(i=0;i<size;i++){
    if(data<list[i]){
      pos=i;break;
    }
  }
  for(i=size;i>=pos;i--)
    list[i]=list[i-1];
  list[pos]=data;
}

void deletion(){
  int i,pos;
  printf("\nEnter the position u want to delete: ");
  scanf("%d",&pos);
  if(pos>=size)
    printf("\nInvalid Location");
  else{
    for(i=pos+1;i<size;i++)
      list[i-1]=list[i];
    size--;
  }
  printf("\nThe Elements after deletion\n");
  display();
}

void display(){
  int i;
  for(i=0;i<size;i++)
    printf("%d\n",list[i]);
}
