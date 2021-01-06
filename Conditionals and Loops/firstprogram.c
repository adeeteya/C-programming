#include<stdio.h>
int strlength(char str[]){
  int count=0;
  while(str[count]!='\0')
  count++;
  return count;
}

int main()
{
  char a[50],b[50],c[50];
  printf("Enter string a\n");
  scanf("%[^\n]",a);
  printf("Enter string b\n");
  scanf("%[^\n]",b);
  printf("Enter string c\n");
  scanf("%[^\n]",c);
  int i,j;
  int count,count1;
  for (i = 0; i < strlength(a);)
    {
        j = 0;
        count = 0;
        while ((a[i] == b[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == strlength(b))
        {
            count1++;
            count = 0;
        }
        else
            i++;
    }
  print("No of occurences of b in a are %d\n",count1);
  for (i = 0; i < strlength(a);)
    {
        j = 0;
        count = 0;
        int startidx=i;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;
        }
        int endidx=i;int k=0;
        if (count == strlength(b))
        {
            while(startidx<=endidx){
              if(k<strlength(c)){
              a[startidx]=c[k];
              k+=1;
            }
            else
            a[startidx]='';
              startidx+=1;
            }
            count = 0;
        }
        else
            i++;
    }
  printf("%s %s %s",a,b,c);
}
