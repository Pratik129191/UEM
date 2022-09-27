#include <stdio.h>

int main()
{
    printf("Rhombous Star Pattern\nPratik Mukherjee\n");
    int n;
    printf("Enter The Size of the Pattern: ");
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j < n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}