#include<stdio.h>

struct time{
  int hh;//hours
  int mm;//minutes
}arr[10];
int lessertime(struct time a,struct time b){
  if(a.hh<b.hh)
    return 1;
  else if(a.hh==b.hh){
    if(a.mm<b.mm)
      return 1;
    else
      return 0;
  }
  else
    return 0;
}
void swap(struct time *a,struct time *b){
  struct time temp;
  temp.hh=a->hh;temp.mm=a->mm;
  *a=*b;
  *b=temp;
}
void selectionSort(){
  int i,j,minidx;
  for(i=0;i<10;i++){
    minidx=i;
    for(j=i+1;j<10;j++)
      if(lessertime(arr[j],arr[minidx]))
        minidx=j;
    swap(&arr[i],&arr[minidx]);
  }
}

int partition(int start,int end){
  int i=start-1,j;
  struct time pivot=arr[end];
  for(j=start;j<=end-1;j++)
    if(lessertime(arr[j],pivot))
      swap(&arr[++i],&arr[j]);
  swap(&arr[i+1],&arr[end]);
  return i+1;
}
void quickSort(int start,int end){
  if(start<end){
    int pindex=partition(start,end);
    quickSort(start,pindex-1);
    quickSort(pindex+1,end);
  }
}

int main(){
  int i;
  printf("Enter the Slot timing in the 24hour format(hh:ss)\n");
  for(i=0;i<10;i++)
    scanf("%d:%d",&arr[i].hh,&arr[i].mm);
  //selectionSort();
  quickSort(0,10);
  printf("Sorted Slot Timings: \n");
  for(i=0;i<10;i++)
    printf("%d:%d\n",arr[i].hh,arr[i].mm);
  return 0;
}
