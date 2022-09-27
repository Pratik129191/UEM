#include<stdio.h>

int main() {
    int row1, row2, column1, column2,i,j,k;
    printf("enter the number of row1=");
    scanf("%d",&row1);
    printf("enter the number of column1=");
    scanf("%d",&column1);
    row2 = column1;
    int first[row1][column1];
    printf("enter the first matrix element=\n");
    for(i=0; i < row1; i++)
    {
        for(j=0; j < column1; j++)
        {
            scanf("%d",&first[i][j]);
        }
    }
    printf("enter the column number for second matrix:\t");
    scanf("%d", &column2);
    int second[row2][column2];
    int mul[row1][column2];
    printf("enter the second matrix element=\n");
    for(i=0; i < row1; i++)
    {
        for(j=0; j < column1; j++)
        {
            scanf("%d",&second[i][j]);
        }
    }

    printf("multiply of the given matrices =\n");
    for(i=0; i < row1; i++)
    {
        for(j=0; j < column1; j++)
        {
            mul[i][j]=0;
            for(k=0; k < column1; k++)
            {
                mul[i][j]+= first[i][k] * second[k][j];
            }
        }
    }

    //for printing result
    for(i=0; i < row1; i++)
    {
        for(j=0; j < column1; j++)
        {
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}