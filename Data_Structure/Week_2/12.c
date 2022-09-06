#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* array;
    int length;
    printf("Enter The Length of the Array:\t");
    scanf("%d", &length);

    array = (int *) malloc(length * sizeof(int));
    if(array == NULL) {
        printf("Memory Not Allocated. System Terminating");
        exit(0);
    } else {
        for (int i = 0; i < length; ++i) {
            printf("Value of Element %d is:\t",i+1);
            scanf("%d", &array[i]);
        }

        int largest = array[0];
        for (int i = 0; i < length; ++i) {
            if (array[i] > largest) {
                largest = array[i];
            }
        }
        printf("Largest Number in the Array is %d.", largest);
    }
}