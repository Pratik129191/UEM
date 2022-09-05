#include <stdio.h>

int main()
{
    int array[5];
    printf("Enter The Array Elements:\n ");
    for (int i = 0; i < 5; ++i) {
        printf("Value of %d", i+1);
        scanf("%d", &array[i]);
    }

    printf("Array Elements are:\t");
    for (int i = 0; i < 5; ++i) {
        printf("%d\t", array[i]);
    }
}