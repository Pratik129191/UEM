#include <stdio.h>

int main() {
    printf("Hollow Mirrored Right Triangle Star Pattern\nPratik Mukherjee\n");
    int n;
    printf("Enter The Size of the Pattern: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == (n - i + 1) || i == n || j == n)
            {
                printf("* ");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}