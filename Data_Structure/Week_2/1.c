#include <stdio.h>

int main()
{
    int array[100] = {0};
    int value, loc, length;

    printf("Enter The Number of Array Elements:\t");
    scanf("%d", &length);
    printf("Enter The Array Elements:\n");
    for (int i = 0; i < length; ++i) {
        printf("Value of Element %d is:\t", i+1);
        scanf("%d", &array[i]);
    }

    printf("Value Should be Inserted:\t");
    scanf("%d", &value);
    printf("%d will be inserted at Location:\t", value);
    scanf("%d", &loc);

    if (loc < length) {
        for (int i = length - 1; i >= loc; --i) {
            array[i + 1] = array[i];
        }
        array[loc] = value;
    } else {
        array[length] = value;
    }
    length ++;

    printf("After Inserting The Array is:\t");
    for (int i = 0; i < length; ++i) {
        printf("%d\t", array[i]);
    }
}