#include <stdio.h>

int main()
{
    int row, col;
    printf("Enter The Number Row:\t");
    scanf("%d", &row);
    printf("Enter The Number Columns:\t");
    scanf("%d", &col);

    printf("Taking Input of The First Matrix: ===>\n");
    int matrix1[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Value of Position (%d, %d) is:\t", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Taking Input of The Second Matrix: ===>\n");
    int matrix2[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Value of Position (%d, %d) is:\t", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    int total[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            total[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("After Summation The Matrix is:\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", total[i][j]);
        }
        printf("\n");
    }
}