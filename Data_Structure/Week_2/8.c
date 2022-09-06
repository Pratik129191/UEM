#include <stdio.h>

int main()
{
    int row, col;
    printf("Enter The Number of Students:\t");
    scanf("%d", &row);
    printf("Enter The Number of Subjects:\t");
    scanf("%d", &col);

    printf("Taking Input of The Marks: ===>\n");
    int matrix[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Value of Position (%d, %d) is:\t", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int highest_marks[col], high;
    for (int i = 0; i < col; ++i) {
        high = 0;
        for (int j = 0; j < row; ++j) {
            if (matrix[j][i] > high) {
                high = matrix[j][i];
            }
        }
        highest_marks[i] = high;
    }

    printf("Highest Marks Are :===>\n");
    for (int i = 0; i < col; ++i) {
        printf("%d is Highest in (Subject %d).", highest_marks[i], i+1);
    }
}