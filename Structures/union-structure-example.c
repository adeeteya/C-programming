#include <stdio.h>
union union_Job{
   float salary;
   int workerNo;
}j;
struct struct_Job{
  float salary;
  int workerNo;
}k;
int main() {
   float salary;int workerNo;
   printf("Enter salary: ");
   scanf("%f",&salary);
   printf("Enter no of workers: ");
   scanf("%d",&workerNo);
   j.salary=salary;k.salary=salary;
   j.workerNo=workerNo;k.workerNo=workerNo;
   printf("In Union\n");
   printf("Salary = %.1f\tNumber of workers = %d", j.salary,j.workerNo);
   printf("\nIn Structure\n");
   printf("Salary = %.1f\tNumber of workers = %d", k.salary,k.workerNo);
   return 0;
}
