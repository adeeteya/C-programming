#include <stdio.h>
#include <conio.h>
int main(){
  FILE *sourcefile,*destfile;
  char sourcefilename[15],destfilename[15],c;
  printf("Enter the Filename to be copied(with extension): ");
  scanf("%s",sourcefilename);
  printf("Enter the new Filename(with extension): ");
  scanf("%s",destfilename);
  sourcefile=fopen(sourcefilename,"r");
  destfile=fopen(destfilename,"w");
  if(sourcefile==NULL){
    printf("\aUnable to open the file\n");
    return -1;
  }
  while((c=fgetc(sourcefile))!=EOF)
    fputc(c,destfile);
  fclose(sourcefile);
  fclose(destfile);
  printf("File Copied Successfully");
}
