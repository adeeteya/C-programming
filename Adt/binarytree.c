#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
void remove_node(struct node *temp,struct node *delnode);
void delete(int data);
void search(int data);
void minimum();
void maximum();
void inorder(struct node *leaf);
void preorder(struct node *leaf);
void postorder(struct node *leaf);

int main(){
  int choice,data;
  queue.front=queue.rear=-1;
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Insert\n2.Remove\n3.Search\n4.Minimum\n5.Maximum\n6.Display\n7.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:printf("Enter the value to be inserted: ");scanf("%d",&data);insert(data);
      printf("%d successfully inserted into the tree",data);break;
      case 2:printf("Enter the value to be deleted: ");scanf("%d",&data);delete(data);break;
      case 3:printf("Enter the value to be searched: ");scanf("%d",&data);search(data);break;
      case 4:minimum();break;
      case 5:maximum();break;
      case 6:printf("\nEnter the type of Traversal\n1.Pre-order\n2.In-order\n3.Post-Order\n");
      printf("Enter your choice: ");scanf("%d",&choice);printf("The elements of the tree are\n");
      if(choice==1)preorder(root);
      else if(choice==2)inorder(root);
      else if(choice==3)postorder(root);break;
      case 7:exit(0);break;
      default:printf("Invalid Input,Press any key to try again..");getch();continue;
    }
    printf("\nPress any key to continue ");getch();
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
void remove_node(struct node *temp,struct node *delnode){
  if(temp==NULL)
    return;
  if(temp==delnode){
    free(delnode);temp=NULL;
    return;
  }
  else if(temp->left==delnode){
    free(delnode);temp->left=NULL;
    return;
  }
  else if(temp->right==delnode){
    free(delnode);temp->right=NULL;
    return;
  }
  remove_node(temp->left,delnode);
  remove_node(temp->right,delnode);
}
void delete(int data){
  if(root==NULL)
    printf("The Tree is Empty!");
  else if(root->left==NULL && root->right==NULL && root->data==data){
    free(root);
    root=NULL;
  }
  else{
    struct node *curnode,*delnode;
    push(root);
    while(!qisEmpty()){
      curnode=queue.q[queue.front];
      pop();
      if(curnode->data==data)delnode=curnode;
      if(curnode->left!=NULL)push(curnode->left);
      if(curnode->right!=NULL)push(curnode->right);
    }
    if(delnode!=NULL){
      delnode->data=curnode->data;
      remove_node(root,curnode);
      printf("Node Successfully Deleted");
    }
    else
      printf("Node not Found in the Tree!");
    queue.front=queue.rear=-1;
  }
}
void search(int data){
  int flag=0;
  if(root==NULL)
    printf("The Tree is Empty!");
  else{
    struct node *temp;
    push(root);
    while(!qisEmpty()){
      temp=queue.q[queue.front];
      pop();
      if(temp->data==data){
        printf("Element found in the Tree!");
        flag=1;break;
      }
      else{
        if(temp->left!=NULL)push(temp->left);
        if(temp->right!=NULL)push(temp->right);
      }
    }
    queue.front=queue.rear=-1;
  }
  if(flag==0)printf("Element does not exist in the tree");
}
void minimum(){
  if(root==NULL)
    printf("The Tree is Empty!");
  else{
    struct node *temp;
    push(root);
    int min=root->data;
    while(!qisEmpty()){
      temp=queue.q[queue.front];
      pop();
      if(temp->data<min)
        min=temp->data;
      if(temp->left!=NULL)push(temp->left);
      if(temp->right!=NULL)push(temp->right);
    }
    queue.front=queue.rear=-1;
    printf("Minimum Value: %d",min);
  }
}
void maximum(){
  if(root==NULL)
    printf("The Tree is Empty!");
  else{
    struct node *temp;
    push(root);
    int max=root->data;
    while(!qisEmpty()){
      temp=queue.q[queue.front];
      pop();
      if(temp->data>max)
        max=temp->data;
      if(temp->left!=NULL)push(temp->left);
      if(temp->right!=NULL)push(temp->right);
    }
    queue.front=queue.rear=-1;
    printf("Maximum Value: %d",max);
  }
}
void preorder(struct node *leaf){
  if(leaf==NULL)return ;
  printf("%d ",leaf->data);
  preorder(leaf->left);
  preorder(leaf->right);
}
void inorder(struct node *leaf){
  if(leaf==NULL)return ;
  inorder(leaf->left);
  printf("%d ",leaf->data);
  inorder(leaf->right);
}
void postorder(struct node *leaf){
  if(leaf==NULL)return ;
  postorder(leaf->left);
  postorder(leaf->right);
  printf("%d ",leaf->data);
}
