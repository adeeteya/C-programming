#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  char data;//stores the character
  struct node *next;//pointer to the next character
}*head,*initial;
typedef struct node NODE;

void insert(char c);//inserts a char into the name chain
void insert_initial(char c);//inserts the initial
void display();//display's the name chain
void disp_vowels();//display's only the vowels
void sortedinsert(NODE **new_head,NODE *newnode);
void sort();//sorts the linked list using insertion sort
void disp_no_initial();//display's the name chain without the initials

int main(){
  char *str;
  str=(char*)malloc(20*sizeof(char));//assigns space to accept name string
  char init;//char variable to store the initial
  int i=0;//loop variable
  printf("Enter your name: ");
  scanf("%s",str);
  str=(char *)realloc(str,strlen(str)+1);//re-assigns the storage allocated to str
  if(strlen(str)<5){
    printf("Error,Minimum 6 characters required(including initials)");
    return 1;
  }
  while(*(str+i)!='\0'){
    insert(*(str+i));i++;
  }
  printf("Enter your initial: ");
  scanf(" %c",&init);
  insert_initial(init);
  printf("Name Chain:");display();
  printf("\nVowels:");disp_vowels();
  sort();
  printf("\nAfter Sorting(without initial):");disp_no_initial();
  printf("\nAfter Sorting(with initial):");display();
  printf("\nVowels:");disp_vowels();
  free(str);//free's the space occupied by the string
  return 0;
}

void insert(char c){
  //this function inserts char to the end of the chain
  NODE *newnode,*temp=head;
  newnode=(NODE *)malloc(sizeof(NODE));
  newnode->data=c;
  if(head==NULL)
    head=newnode;
  else{
    while(temp->next!=NULL)
      temp=temp->next;
    temp->next=newnode;
  }
  newnode->next=NULL;
}

void insert_initial(char c){
  //this function inserts initial to the start of the chain
  NODE *newnode;
  newnode=(NODE *)malloc(sizeof(NODE));
  newnode->data=c;
  newnode->next=head;
  head=newnode;initial=newnode;
}

void display(){
  //this function display's the elements of the name chain
  NODE *temp=head;
  if(head==NULL)
    printf("Empty Name Chain...");
  else{
    while(temp!=NULL){
      printf("%c",temp->data);
      temp=temp->next;
    }
  }
}

void disp_vowels(){
  //This function display's only the vowels of the name chain
  NODE *temp=head;
  if(head==NULL)
    printf("Empty Name Chain...");
  else{
    char c;
    while(temp!=NULL){
      c=temp->data;
      if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
    ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
        printf("%c",c);
      }
      temp=temp->next;
    }
  }
}
void sortedinsert(NODE **new_head,NODE *newnode){
  //This function compares and sorts the name chain accordingly
  NODE *temp;
  if(*new_head==NULL||(*new_head)->data >= newnode->data){
    newnode->next=*new_head;
    *new_head=newnode;
  }
  else{
    temp=*new_head;
    while(temp->next!=NULL && temp->next->data < newnode->data){
      temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
  }
}

void sort(){
  //This function sorts the name chain using insertion sort
  NODE *sorted=NULL,*temp=head;
  while(temp!=NULL){
    NODE *nextnode=temp->next;
    sortedinsert(&sorted,temp);
    temp=nextnode;
  }
  head=sorted;
}

void disp_no_initial(){
  //This function display's the name chain without the initial
  NODE *temp=head;
  if(head==NULL)
    printf("Empty Name Chain...");
  else{
    while(temp!=NULL){
      if(temp!=initial)
        printf("%c",temp->data);
      temp=temp->next;
    }
  }
}
