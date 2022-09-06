#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1, col1, row2, col2;
    printf("For First Matrix :===>\n");
    printf("Number of Rows:\t");
    scanf("%d", &row1);
    printf("Number of Columns:\t");
    scanf("%d", &col1);
    int matrix1[row1][col1];
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col1; ++j) {
            printf("Value of (%d, %d) Position is:\t", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("For Second Matrix :===>\n");
    printf("Number of Rows:\t");
    scanf("%d", &row2);
    printf("Number of Columns:\t");
    scanf("%d", &col2);
    int matrix2[row2][col2];
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < col2; ++j) {
            printf("Value of (%d, %d) Position is:\t", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (col1 != row2){
        printf("Multiplication of Matrices is Not Possible as Column of First Matrix & Row of Second Matrix is Not Same.");
        exit(0);
    } else {
        int multiplied[row1][col2];
        for (int i = 0; i < row1; ++i) {
            for (int j = 0; j < col2; ++j) {
                multiplied[i][j] = 0;
                for (int k = 0; k < row2; ++k) {
                    multiplied[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                printf("%d\t", multiplied[i][j]);
            }
            printf("\n");
        }

    }
}