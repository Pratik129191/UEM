#include <stdio.h>

int main() {
    printf("X star Pattern\nPratik Mukherjee\n");
    int n;
    printf("Enter The Size of the Pattern: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                printf("* ");
            else if (j == n - i + 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}