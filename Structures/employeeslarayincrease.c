#include <stdio.h>

typedef struct employee{
  char name[30];
  float salary;
  int hoursofwork;
}EMPLOYEE;

int main()
{
  int i,n;
  printf("Enter the no of Employee's: ");
  scanf("%d",&n);
  EMPLOYEE a[n];
  for(i=0;i<n;i++){
    printf("Enter details of the Employee %d\n",i+1);
    printf("Enter name: ");
    scanf("%s",a[i].name);
    printf("Enter salary: ");
    scanf("%f",&a[i].salary);
    printf("Enter hours of work: ");
    scanf("%d",&a[i].hoursofwork);
    if(a[i].hoursofwork>=8 && a[i].hoursofwork<10)
      a[i].salary+=50;
    else if(a[i].hoursofwork>=10 && a[i].hoursofwork<12)
      a[i].salary+=100;
    else if(a[i].hoursofwork>=12)
      a[i].salary+=150;
  }
  printf("Name\tUpdated Salary\n");
  for(i=0;i<n;i++){
    printf("%s",a[i].name);
    printf("\t%.2f\n",a[i].salary);
}
}
