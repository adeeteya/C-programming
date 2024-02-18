#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkleapyear(int year){
    if(year%400==0)return 1;
    else if(year%100==0)return 0;
    else if(year%4==0)return 1;
    return 0;
}
char **leapyears(int arr[],int size){
    char **result=malloc(size*sizeof(char));
    int i;
    for(i=0;i<size;i++)result[i]=(char *)malloc(4*sizeof(char));
    for(i=0;i<size;i++){
        if(checkleapyear(arr[i])){
            result[i]="yes";
        }
        else{
            result[i]="no";
        }
    }
    return result;
}
int main(){
    int years[]={2012,2015,2016,2017,2018,2020,2019,3000,1900};//sample input
    int n=sizeof(years)/sizeof(int),i;
    char **result=leapyears(years,n);
    for(i=0;i<n;i++){
        printf("%d is %s leap year.\n",years[i],result[i]=="yes"?"a":"not a");
    }
    return 0;
}