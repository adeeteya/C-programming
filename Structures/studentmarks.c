#include<Stdio.h>
struct Marks{
  int rollno;
  char name[20];
  int chem_marks,maths_marks,phy_marks;
};

int main(){
  int i,n,sum;
  printf("Enter the number of students: ");
  scanf("%d",&n);
  struct Marks students[n];
  for(i=0;i<n;i++){
    fflush(stdin);
    printf("Enter name: ");
    scanf("%[^\n]s",students[i].name);
    printf("Enter Roll no: ");
    scanf("%d",&students[i].rollno);
    printf("Enter marks in chemistry,mathematics,physics: ");
    scanf("%d,%d,%d",&students[i].chem_marks,&students[i].maths_marks,&students[i].phy_marks);
  }
  printf("Name\t\tRoll no\tPercentage\n");
  for(i=0;i<n;i++){
    sum=students[i].chem_marks+students[i].maths_marks+students[i].phy_marks;
    float percentage=(sum/3.0);
    printf("%s\t\t%d\t%.2f\n",students[i].name,students[i].rollno,percentage);
  }
  return 0;
}
