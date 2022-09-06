#include<stdio.h>

int main()
{
    int row, col;
    printf("Number of Rows in Matrix:\t");
    scanf("%d", &row);
    printf("Number of Columns in Matrix:\t");
    scanf("%d", &col);

    int matrix[row][col];
    printf("Taking Input of the Matrix:==>\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Value of Position (%d, %d) is:\t", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Printing the Matrix:\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
