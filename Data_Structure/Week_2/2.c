#include <stdio.h>

int main()
{
    int array[100] = {0};
    int value, loc, length, temp;

    printf("Enter The Number of Array Elements:\t");
    scanf("%d", &length);
    printf("Enter The Array Elements:\n");
    for (int i = 0; i < length; ++i) {
        printf("Value of Element %d is:\t", i+1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Value Should be Inserted:\t");
    scanf("%d", &value);
    printf("%d will be inserted at Location:\t", value);
    scanf("%d", &loc);

    if (loc >= length) {
        array[length] = value;
    } else {
        for (int i = length - 1; i >= loc; --i) {
            array[i + 1] = array[i];
        }
        array[loc] = value;
    }
    length++;


    printf("After Inserting The Array is:\t");
    for (int i = 0; i < length; ++i) {
        printf("%d\t", array[i]);
    }
}