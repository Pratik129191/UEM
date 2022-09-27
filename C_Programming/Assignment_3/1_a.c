#include <stdio.h>

int main()
{
    printf("Square Star Pattern\nPratik Mukherjee ...\n");
    int width, height;
    printf("Enter The Width of the Pattern: ");
    scanf("%d", &width);
    printf("Enter The Length of the Pattern: ");
    scanf("%d", &height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("* ");
        }
        printf("\n");
    }
}