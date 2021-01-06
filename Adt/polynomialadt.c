#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct{
  int coefficient[MAX+1];
  int highpower;
}*polynomial;

void display(polynomial poly){
  int i=0;
  for(i=0;i<=poly->highpower;i++){
    if(poly->coefficient[i]!=0){
      if(i==0)
        printf("1+");
      else
        printf("%dy%d+",poly->coefficient[i],i+1);
    }
  }
}
polynomial inputpolynomial(){
  polynomial poly;
  poly=malloc(sizeof(polynomial));
  int i,pow,coeff,max=0,choice=1;
  for(i=0;i<MAX;i++)
    poly->coefficient[i]=0;
  poly->highpower=0;
  while(choice!=0){
    printf("Enter the power: ");
    scanf("%d",&pow);
    if(pow>max)max=pow;
    if(pow==0)poly->coefficient[0]=1;
    else{
      printf("Enter the co-efficient: ");
      scanf("%d",&coeff);
      poly->coefficient[pow-1]=coeff;
    }
    printf("Continue Entering?(0 to stop any other number to continue): ");
    scanf("%d",&choice);
  }
  poly->highpower=max;
  return poly;
}

void addpolynomial(polynomial a,polynomial b){
  polynomial result;
  int i;
  for(i=0;i<MAX;i++)
    result->coefficient[i]=0;
  if(a->highpower>b->highpower)result->highpower=a->highpower;
  else result->highpower=b->highpower;
  for(i=result->highpower;i>=0;i--)
    result->coefficient[i]=a->coefficient[i]+b->coefficient[i];
  display(result);
}

int main(){
  printf("Input the First Polynomial\n");
  polynomial a=inputpolynomial();
  display(a);
  printf("\b \b\nInput the Second Polynomial\n");
  //fflush(stdout);
  polynomial b=inputpolynomial();
  display(b);printf("\b \b");
  //fflush(stdout);
  printf("\nTheir sum is:\n");
  addpolynomial(a,b);printf("\b \b");
  return 0;
}
