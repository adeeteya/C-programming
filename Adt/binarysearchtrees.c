#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
}*root;

struct node *insert(int data,struct node *leaf);
struct node *delete(int data,struct node *leaf);
int search(int data,struct node *leaf);
struct node *minimum(struct node*leaf);
struct node *maximum(struct node*leaf);
void inorder(struct node *leaf);
void preorder(struct node *leaf);
void postorder(struct node *leaf);

int main(){
  int choice,data;
  while(1){
    system("cls");
    printf("\t\tMain Menu\n");
    printf("1.Insert\n2.Remove\n3.Search\n4.Minimum\n5.Maximum\n6.Display\n7.Exit\n");
    printf("Enter your choice: ");scanf("%d",&choice);
    switch(choice){
      case 1:printf("Enter the value to be inserted: ");scanf("%d",&data);insert(data,root);
      printf("%d successfully inserted into the tree",data);break;
      case 2:printf("Enter the value to be deleted: ");scanf("%d",&data);
      if(search(data,root)==0)printf("%d not found in the tree",data);
      else {delete(data,root);printf("%d successfully deleted from the tree",data);}break;
      case 3:printf("Enter the value to be searched: ");scanf("%d",&data);
      if(search(data,root)==1)printf("Element Found in the tree!\n");
      else printf("Element not Found in the tree!\n");break;
      case 4:if(minimum(root)!=NULL)printf("The minimum Element is: %d",minimum(root)->data);
      else printf("The Binary Tree is Empty");break;
      case 5:if(maximum(root)!=NULL)printf("The maximum Element is: %d",maximum(root)->data);
      else printf("The Binary Tree is Empty");break;
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

struct node *insert(int data,struct node *leaf){
  if(leaf==NULL){
    leaf=(struct node *)malloc(sizeof(struct node));
    leaf->data=data;
    leaf->left=leaf->right=NULL;
    if(root==NULL)root=leaf;
  }
  else if(data>leaf->data)
    leaf->right=insert(data,leaf->right);
  else
    leaf->left=insert(data,leaf->left);
  return leaf;
}

struct node *delete(int data,struct node *leaf){
  if(leaf==NULL)
    return NULL;
  if(data>leaf->data)
    leaf->right=delete(data,leaf->right);
  else if(data<leaf->data)
    leaf->left=delete(data,leaf->left);
  else{
    if(leaf->left==NULL && leaf->right==NULL){
      free(leaf);
      return NULL;
    }
    else if(leaf->left==NULL || leaf->right==NULL){
      struct node *temp;
      if(leaf->left==NULL)
        temp=leaf->right;
      else
        temp=leaf->left;
      free(leaf);
      return temp;
    }
    else{
      struct node *temp=minimum(leaf->right);
      leaf->data=temp->data;
      leaf->right=delete(temp->data,leaf->right);
    }
  }
  return leaf;
}
int search(int data,struct node *leaf){
  if(leaf==NULL)
    return 0;
  else if(data==leaf->data)
    return 1;
  else if(data<leaf->data)
    search(data,leaf->left);
  else
    search(data,leaf->right);
}
struct node *minimum(struct node *leaf){
  if(leaf==NULL)
    return NULL;
  else if(leaf->left!=NULL)
    return minimum(leaf->left);
  return leaf;
}
struct node *maximum(struct node *leaf){
  if(leaf==NULL)
    return NULL;
  else if(leaf->right!=NULL)
    return maximum(leaf->right);
  return leaf;
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
