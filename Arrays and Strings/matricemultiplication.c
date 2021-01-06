#include <stdio.h>
//Program by Aditya.R
int main()
{
    int i,j,k,r1,c1,r2,c2;
    printf("Enter number of Rows of matrix a: ");
    scanf("%d",&r1);
    printf("Enter number of Cols of matrix a: ");
    scanf("%d",&c1);
    int a[r1][c1];
    printf("Enter elements of matrix a: \n");
    for(i=0;i<r1;i++)
      for(j=0;j<c1;j++)
        scanf("%d",&a[i][j]);
    printf("Enter number of Rows of matrix b: ");
    scanf("%d",&r2);
    printf("Enter number of Cols of matrix b: ");
    scanf("%d",&c2);
    int b[r2][c2];
    printf("Enter elements of matrix b: \n");
    for(i=0;i<r2;i++)
      for(j=0;j<c2;j++)
        scanf("%d",&b[i][j]);
    if(c1==r2)
    {
        int result[r1][c2];
        for(i=0;i<r1;i++){
          for(j=0;j<c2;j++){
            result[i][j]=0;
            for(k=0;k<r2;k++)
              result[i][j]+=(a[i][k]*b[k][j]);
            }
          }
        printf("Matrix after multiplying elements (result matrix):\n");
        for(i=0;i<r1;i++){
          for(j=0;j<c2;j++)
            printf("%d\t",result[i][j]);
          printf("\n");
          }
    }
    else
        printf("\nMultiplication can not be done.");
    return 0;
}
