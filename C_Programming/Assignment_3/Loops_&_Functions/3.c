#include <stdio.h>

int main() {
    int length;
    printf("Enter The Length of the Array:\t");
    scanf("%d", &length);

    int array[length];
    for (int i = 0; i < length; ++i) {
        printf("Value of %d is:\t", i+1);
        scanf("%d", &array[i]);
    }

    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }

    printf("Sum of Array Elements is: %d", sum);
}