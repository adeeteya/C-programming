#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct node{
  int data;
  struct node *left;
  struct node *right;
}*root;
struct{
  struct node *q[MAX];
  int front;
  int rear;
}queue;

int qisEmpty(){
  if(queue.front==-1)
    return 1;
  else return 0;
}
void push(struct node *temp){
  if(qisEmpty())
    queue.front++;
  queue.q[++queue.rear]=temp;
}
void pop(){
  if(qisEmpty())
    return;
  queue.front++;
  if(queue.front>queue.rear)queue.front=queue.rear=-1;
}
struct node* Create();
void Insert();
void Inorder(struct node *temp);

int main(){
  int choice,data;
  queue.front=queue.rear=-1;
  while(1){
    printf("\n\t\tMain Menu\n");
    printf("1.Insert\n2.Display(In-Order)\n3.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:Insert();break;
      case 2:Inorder(root);break;
      case 3:exit(0);break;
      default:printf("Invalid Input,Please Try Again\n");continue;
    }
  }
  return 0;
}
struct node* Create(){
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter the value to be inserted: ");scanf("%d",&newnode->data);
  newnode->left=newnode->right=NULL;
  return newnode;
}
void Insert(){
  struct node *newnode=Create();
  if(root==NULL)
    root=newnode;
  else{
    struct node *temp;
    push(root);
    while(!qisEmpty()){
      temp=queue.q[queue.front];
      pop();
      if(temp->left==NULL){
        temp->left=newnode;break;
      }
      else if(temp->right==NULL){
        temp->right=newnode;break;
      }
      else{
        push(temp->left);push(temp->right);
      }
    }
    queue.front=queue.rear=-1;//resets the queue
  }
  printf("%d successfully inserted into the tree\n",newnode->data);
}

void Inorder(struct node *temp){
  if(temp==NULL)return ;
  Inorder(temp->left);
  printf("%d ",temp->data);
  Inorder(temp->right);
}
