#include <stdio.h>

int main()
{
    printf("Hollow Square Star Pattern With Diagonal\nPratik Mukherjee\n");
    int n;
    printf("Enter The Size of the Pattern: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n || j == i || j == (n - i + 1))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}