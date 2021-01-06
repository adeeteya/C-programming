#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for(i=n;i>0;i--){
        for(j=n;j>i;j--)printf("%d ",j);
        for(j=1;j<i*2;j++)printf("%d ",i);
        for(j=i+1;j<=n;j++)printf("%d ",j);
        printf("\n");
    }
    //bottom half
    for(i=2;i<=n;i++){
        for(j=n;j>i;j--)printf("%d ",j);
        for(j=1;j<i*2;j++)printf("%d ",i);
        for(j=i+1;j<=n;j++)printf("%d ",j);
        printf("\n");
    }
    return 0;
}
