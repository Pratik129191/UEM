#include <stdio.h>

int main() {
    int length, temp;
    printf("Enter The Length of the Array:\t");
    scanf("%d", &length);

    int array[length];
    printf("Enter The Array Elements:==>\n");
    for (int i = 0; i < length; ++i) {
        printf("Value of Element %d is:\t", i + 1);
        scanf("%d", &array[i]);
    }

    int location;
    printf("Value of Which Location Should be Deleted:\t");
    scanf("%d", &location);

    if (location >= length) {
        array[location] = 0;
    } else {
        for (int i = location + 1; i < length; ++i) {
            array[i - 1] = array[i];
        }
    }
    length--;

    printf("After Deleting The Array is:\n");
    for (int i = 0; i < length; ++i) {
        printf("%d\t", array[i]);
    }
}