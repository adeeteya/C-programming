#include<stdio.h>
typedef struct{
  int day,month,year;
}date;
int noofdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
int checkleapyear(int n){
  if(n%400==0)//2000
    return 1;
  else if(n%100==0)//2100
    return 0;
  else if(n%4==0)//2004
    return 1;
  else
    return 0;
}
int main(){
  date d1;
  int *day=&d1.day;
  int *month=&d1.month;
  int *year=&d1.year;
  printf("Enter dd/mm/yyyy: ");
  scanf("%d/%d/%d",day,month,year);//22/04/2001
  int i=0,n,choice;
  printf("Enter 1 to Add and 2 to Subtract: ");
  scanf("%d",&choice);
  printf("Enter No of days: ");
  scanf("%d",&n);
  if(choice==1){
    while(i<n){
      if(*month==2){
        if(*day==28){
          if(checkleapyear(*year)){
            *day=1;*month=3;
            i+=2;
            if(i==n+1){
              *day=29;*month=2;
            }
            continue;
          }
        }
      }
      if(*day==noofdays[*month-1]){
        *day=1;
        if(*month==12){
          *year+=1;*month=1;
        }
        else
          *month+=1;
        i++;continue;
      }
      else
        *day+=1;
      i++;
    }
  }
  else if(choice==2){
    while(i<n){
      if(*month==3){
        if(*day==1){
          if(checkleapyear(*year)){
            *day=29;*month=2;
            i++;
            continue;
          }
        }
      }
      if(*day==1){
        if(*month==1){
          *year-=1;*month=12;
        }
        else
          *month-=1;
        *day=noofdays[*month-1];
        i++;
        continue;
      }
      else
        *day-=1;
      i++;
    }
  }
  printf("The new date is %d/%d/%d",*day,*month,*year);
}
