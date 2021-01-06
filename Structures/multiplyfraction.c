#include<stdio.h>

typedef struct{
  int numerator;
  int denominator;
}Fraction;

void readfraction(Fraction *fr);
void multiplyfraction(Fraction *fr1,Fraction *fr2,Fraction *fr);
void printfraction(Fraction *fr1,Fraction *fr2,Fraction *fr);
int main(){
  Fraction fr1,fr2,result;
  readfraction(&fr1);
  readfraction(&fr2);
  multiplyfraction(&fr1,&fr2,&result);
  printfraction(&fr1,&fr2,&result);
  return 0;
}
void readfraction(Fraction *fr1){
  printf("Enter the Numerator/Denominator: ");
  scanf("%d/%d",&fr1->numerator,&fr1->denominator);
  return;
}
void multiplyfraction(Fraction *fr1,Fraction *fr2,Fraction *fr){
  (*fr).numerator=fr1->numerator*fr2->numerator;
  fr->denominator=fr1->denominator*fr2->denominator;
  return;
}
void printfraction(Fraction *fr1,Fraction *fr2,Fraction *fr){
  printf("\nThe Result is %d/%d ",fr->numerator,fr->denominator);
  return;
}
