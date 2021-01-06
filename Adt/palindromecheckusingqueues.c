#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct{
  char q[MAX];
  int front,rear;
}queue;

void enqueue(char c){
  if(queue.rear>=MAX)
    printf("OVERFLOW\n");
  else{
    if(queue.front==-1)
      queue.front=0;
    queue.q[++queue.rear]=c;
  }
}
char dequeue(){
  if(queue.front>queue.rear ||queue.front==-1)
    printf("UNDERFLOW\n");
  else{
    char c=queue.q[queue.front];
    queue.front++;
    if(queue.front>queue.rear){
      queue.front=queue.rear=-1;
    }
    return c;
  }
}

int main(){
  queue.front=queue.rear=-1;//initializing empty queue
  char str[MAX];
  printf("Enter the String: ");
  scanf("%s",str);
  int i,n=strlen(str),flag=1;
  if(n%2==0)n=(n/2)-1;
  else n=n/2;
  for(i=strlen(str)-1;i>n;i--)
    enqueue(str[i]);
  if(n%2==0)n-=1;
  for(i=0;i<n;i++){
    if(dequeue()!=str[i]){
      flag=0;break;
    }
  }
  if(flag==0)printf("The String is not a Palindrome");
  else printf("The String is a Palindrome");
  return 0;
}
