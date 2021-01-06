#include<stdio.h>

int main(){
  int sum=0,n,i=0;
  FILE *ptr=fopen("average.dat","r");
  if(ptr==NULL) printf("The File cannot be opened\n");
  else{
    FILE *ptrwrite=fopen("average.res","w");
    while(!feof(ptr)){
      fscanf(ptr,"%d ",&n);
      i++;
      sum+=n;
    }
    fprintf(ptrwrite,"%f",((float)(sum)/i));
    fclose(ptrwrite);
  }
  fclose(ptr);
}
