#include <stdio.h>

int main()
{
    int length;
    printf("Enter The Length of the array:\t");
    scanf("%d",&length);

    int array[length];
    printf("Enter The Array Elements:\n");
    for (int i = 0; i < length; ++i) {
        printf("Value of Element %d is:\t");
        scanf("%d", &array[i]);
    }

    printf("Printing The Array in Reverse Form:\n");
    for (int i = length - 1; i >= 0; --i) {
        printf("%d\t", array[i]);
    }
}