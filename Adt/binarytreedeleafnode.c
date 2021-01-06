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

void insert(int data);
struct node *leafdelete(struct node *temp);
void inorder(struct node *temp);

int main(){
  int choice,data;
  queue.front=queue.rear=-1;
  while(1){
    printf("\n\n\t\tMain Menu\n");
    printf("1.Insert\n2.Remove a Leaf node\n3.In-order display\n4.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:printf("Enter the value to be inserted: ");scanf("%d",&data);insert(data);
      printf("%d successfully inserted into the tree",data);break;
      case 2:leafdelete(root);break;
      case 3:inorder(root);break;
      case 4:exit(0);break;
      default:printf("Invalid Input,Please try again.");continue;
    }
  }
  return 0;
}

void insert(int data){
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data;newnode->left=newnode->right=NULL;
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
}
struct node *leafdelete(){
  if(temp==NULL)
    return NULL;
  if(temp->left==NULL && temp->right==NULL){
    free(temp);
    return NULL;
  }
  temp->left=leafdelete(temp->left);
  temp->right=leafdelete(temp->right);
  return temp;
}
void inorder(struct node *temp){
  if(temp==NULL)return ;
  inorder(temp->left);
  printf("%d ",temp->data);
  inorder(temp->right);
}
