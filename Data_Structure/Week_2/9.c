#include <stdio.h>

int main()
{
    int row, col;
    printf("Enter The Number Row:\t");
    scanf("%d", &row);
    printf("Enter The Number Columns:\t");
    scanf("%d", &col);

    printf("Taking Input of The Marks: ===>\n");
    int matrix[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Value of Position (%d, %d) is:\t", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int transposed[col][row];
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }

    printf("After Transposing The Matrix is :===>\n");
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            printf("%d\t", transposed[i][j]);
        }
        printf("\n");
    }
}