#include<stdio.h>
struct customer{
  char name[20];
  int accno;
  float balance;
};
void lowbalance(struct customer *ptr,int n){
  int i;
  for(i=0;i<n;i++){
    if((ptr+i)->balance<200)
      printf("%s\n",(ptr+i)->name);
  }
}
void increasebalance(struct customer *ptr,int n){
  int i;
  for(i=0;i<n;i++){
    if((ptr+i)->balance>=1000){
      (ptr+i)->balance+=100;
      printf("%s\t%.2f\n",(ptr+i)->name,(ptr+i)->balance);
    }
  }
}
int main(){
  int i,n;
  printf("Enter the number of customers: ");
  scanf("%d",&n);
  struct customer customers[n];
  for(i=0;i<n;i++){
    fflush(stdin);
    printf("Enter name: ");
    scanf("%[^\n]s",customers[i].name);
    printf("Enter Account no: ");
    scanf("%d",&customers[i].accno);
    printf("Enter Account Balance: ");
    scanf("%f",&customers[i].balance);
  }
  printf("Customers Having Balance below $200 are\n");
  lowbalance(customers,n);
  printf("New increased balance of customers are\n");
  increasebalance(customers,n);
  return 0;
}
