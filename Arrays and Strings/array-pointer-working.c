#include<stdio.h>
#include<string.h>
int main(){
  char *pdays[7];
  char **plast;//pointer to a pointer
  pdays[0]="Sunday";
  pdays[1]="Monday";
  pdays[2]="Tuesday";
  pdays[3]="Wednesday";
  pdays[4]="Thursday";
  pdays[5]="Friday";
  pdays[6]="Saturday";
  plast=pdays+6;
  for(char **pwalker=pdays;pwalker<=plast;pwalker++){
    printf("%s\t%u\n",*pwalker,pwalker);
  }
  return 0;
}
