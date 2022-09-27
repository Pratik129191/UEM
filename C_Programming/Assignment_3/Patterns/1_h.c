#include <stdio.h>

int main() {
    printf("Plus Star Pattern\nPratik Mukherjee\n");
    int n;
    printf("Enter The Size of the Pattern: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == (n / 2) + 1 || i == (n / 2) + 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}
