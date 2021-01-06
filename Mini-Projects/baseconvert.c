#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char binarydigits[][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char hexadigits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0'};

int menu();
int hexfind(char c){
  int i=0;
  for(i=0;i<16;i++)
    if(hexadigits[i]==c)
      return i;
  return -1;
}
int menu_choice(){
  int choice;
  printf("\nReturn to the main menu(1 for yes anything else to quit the program)? ");
  scanf("%d",&choice);
  if(choice==1)menu();
  else
    exit(0);
}

int decimalConvert(){
  system("cls");
  int i,j,n,decimal;
  printf("Enter the Decimal no: ");
  scanf("%d",&decimal);
  n=decimal;j=(int)((log(n*1.0)/log(2.0))+1);
  char binary[j];
  memset(binary,'0',sizeof(binary));
  binary[j]='\0';
  while(n>1){
    binary[--j]=n%2+'0';
    n/=2;
  }
  binary[0]=n+'0';
  printf("The Binary value is: %s\n",binary);
  n=decimal;j=(int)((log(n*1.0)/log(8.0))+1);
  char octal[j];
  memset(octal,'0',sizeof(octal));
  octal[j]='\0';
  while(n>7){
    octal[--j]=n%8+'0';
    n/=8;
  }
  octal[0]=n+'0';
  printf("The octal value is: %s\n",octal);
  n=decimal;j=(int)((log(n)/log(16))+1);
  char hexadecimal[j];
  memset(hexadecimal,'0',sizeof(hexadecimal));
  hexadecimal[sizeof(hexadecimal)]='\0';
  while(n>15){
    hexadecimal[--j]=hexadigits[n%16];
    n/=16;
  }
  hexadecimal[0]=hexadigits[n];
  printf("The hexadecimal value is: %s",hexadecimal);
  menu_choice();
}
int octalConvert(){
  system("cls");
  char *s,buffer[64];int i,j=0,decimal=0;
  s=(char *)malloc(64);
  printf("Enter the Octal no: ");
  scanf("%s",s);
  s=(char *)realloc(s,strlen(s)+1);
  char *binary;
  binary=(char *)malloc(strlen(s)*3+1);
  strcpy(binary,&binarydigits[s[0]-'0'][1]);
  for(i=1;i<strlen(s);i++){
    strcpy(buffer,&binarydigits[s[i]-'0'][1]);
    strcat(binary,buffer);
  }
  printf("Binary Value: %s\n",binary);
  for(i=strlen(s)-1;i>=0;i--){
    decimal+=(s[i]-'0')*pow(8,j);
    j++;
  }
  printf("Decimal Value: %d\n",decimal);
  strcpy(buffer,"");
  if(strlen(binary)%4==1)strcpy(buffer,"000");
  else if(strlen(binary)%4==2)strcpy(buffer,"00");
  else if(strlen(binary)%4==3)strcpy(buffer,"0");
  strcat(buffer,binary);
  strcpy(binary,buffer);
  char hexadecimal[strlen(binary)/4];
  memset(hexadecimal,'0',strlen(binary)/4);hexadecimal[strlen(binary)/4]='\0';
  j=strlen(hexadecimal)-1;
  for(i=strlen(binary)-1;i>0;i-=4){
    decimal=(binary[i]-'0')*1+(binary[i-1]-'0')*2+(binary[i-2]-'0')*4+(binary[i-3]-'0')*8;
    hexadecimal[j]=hexadigits[decimal];
    j--;
  }
  if(hexadecimal[0]=='0'){
    strcpy(buffer,hexadecimal+1);
    strcpy(hexadecimal,buffer);
  }
  printf("Hexa-Decimal value: %s",hexadecimal);
  free(s);free(binary);
  menu_choice();
}

int binaryConvert(){
  system("cls");
  int i,j=0,dig,decimal=0;
  char *s,buffer[64];
  s=(char *)malloc(64);
  printf("Enter the binary number: ");
  scanf("%s",s);
  s=(char *)realloc(s,strlen(s)+3);
  for(i=strlen(s)-1;i>=0;i--){
    dig=s[i]-'0';
    decimal+=dig*pow(2,j);
    j++;
  }
  printf("Decimal value: %d\n",decimal);
  strcpy(buffer,"");
  if(strlen(s)%3==1)strcpy(buffer,"00");
  else if(strlen(s)%3==2)strcpy(buffer,"0");
  strcat(buffer,s);
  strcpy(s,buffer);
  char octal[strlen(s)/3];
  memset(octal,'0',strlen(s)/3);octal[strlen(s)/3]='\0';
  j=(strlen(s)/3)-1;
  for(i=strlen(s)-1;i>0;i-=3){
    decimal=(s[i]-'0')*1+(s[i-1]-'0')*2+(s[i-2]-'0')*4;
    octal[j]=decimal+'0';
    j--;
  }
  printf("Octal value: %s\n",octal);
  strcpy(buffer,"");
  if(strlen(s)%4==1)strcpy(buffer,"000");
  else if(strlen(s)%4==2)strcpy(buffer,"00");
  else if(strlen(s)%4==3)strcpy(buffer,"0");
  strcat(buffer,s);
  strcpy(s,buffer);
  char hexadecimal[strlen(s)/4];
  memset(hexadecimal,'0',strlen(s)/4);hexadecimal[strlen(s)/4]='\0';
  j=strlen(hexadecimal)-1;
  for(i=strlen(s)-1;i>0;i-=4){
    decimal=(s[i]-'0')*1+(s[i-1]-'0')*2+(s[i-2]-'0')*4+(s[i-3]-'0')*8;
    hexadecimal[j]=hexadigits[decimal];
    j--;
  }
  if(hexadecimal[0]=='0'){
    strcpy(buffer,hexadecimal+1);
    strcpy(hexadecimal,buffer);
  }
  printf("Hexa-Decimal value: %s",hexadecimal);
  free(s);
  menu_choice();
}
int hexaDecimalConvert(){
  system("cls");
  char *s,buffer[64];int i,j=0,decimal=0;
  s=(char *)malloc(64);
  printf("Enter the Hexa-Decimal no: ");
  scanf("%s",s);
  s=(char *)realloc(s,strlen(s)+1);
  char *binary;
  binary=(char *)malloc(strlen(s)*4+1);
  strcpy(binary,&binarydigits[hexfind(s[0])][0]);
  for(i=1;i<strlen(s);i++){
    strcpy(buffer,&binarydigits[hexfind(s[i])][0]);
    strcat(binary,buffer);
  }
  while(*binary=='0')
    strcpy(binary,(binary+1));
  printf("Binary Value: %s\n",binary);
  for(i=strlen(s)-1;i>=0;i--){
    decimal+=hexfind(s[i])*pow(16,j);
    j++;
  }
  printf("Decimal Value: %d\n",decimal);
  strcpy(buffer,"");
  if(strlen(binary)%3==1)strcpy(buffer,"00");
  else if(strlen(binary)%3==2)strcpy(buffer,"0");
  strcat(buffer,binary);
  strcpy(binary,buffer);
  char octal[strlen(binary)/3];
  memset(octal,'0',strlen(binary)/3);octal[strlen(binary)/3]='\0';
  j=strlen(octal)-1;
  for(i=strlen(binary)-1;i>0;i-=3){
    decimal=(binary[i]-'0')*1+(binary[i-1]-'0')*2+(binary[i-2]-'0')*4;
    octal[j]=decimal+'0';
    j--;
  }
  printf("Octal value: %s",octal);
  free(s);free(binary);
  menu_choice();
}
int menu(){
  system("cls");
  int choice;
  printf("Enter your Input Choice\n");
  printf("1.Binary\n2.Octal\n3.Decimal\n4.Hexa-Decimal\n5.Exit\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:binaryConvert();break;
    case 2:octalConvert();break;
    case 3:decimalConvert();break;
    case 4:hexaDecimalConvert();break;
    case 5:exit(0);
    default:printf("Invalid Input try again");menu();
  }
}
int main(){
  menu();
}
