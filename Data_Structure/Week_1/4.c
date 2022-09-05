#include <stdio.h>

int main()
{
    int array[5], temp;
    printf("Enter The Array Elements:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Value of Element %d is:\t", i+1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5 - i -1; ++j) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("After Sorting The Array is:\t");
    for (int i = 0; i < 5; ++i) {
        printf("%d\t", array[i]);
    }
}