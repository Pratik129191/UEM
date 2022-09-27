#include <stdio.h>

int main() {
    printf("Left Arrow Star Pattern\nPratik Mukherjee\n");
    int n;
    printf("Enter The Size of the Pattern: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}