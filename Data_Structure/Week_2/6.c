#include <stdio.h>

int smallest_index(int* array, int length);
int largest_index(int* array, int length);

int main()
{
    int length;
    printf("Enter The Length of the Array:\t");
    scanf("%d", &length);

    int array[length];
    for (int i = 0; i < length; ++i) {
        printf("Value of Element %d is:\t", i+1);
        scanf("%d", &array[i]);
    }

    int smallest = smallest_index(array, length);
    int largest = largest_index(array, length);

    int temp = array[smallest];
    array[smallest] = array[largest];
    array[largest] = temp;

    printf("After Rearranging the Array is:==>\n");
    for (int i = 0; i < length; ++i) {
        printf("%d\t", array[i]);
    }
}

int smallest_index(int* array, int length)
{
    int small = array[0], index = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] < small) {
            small = array[i];
            index = i;
        }
    }
    return index;
}

int largest_index(int* array, int length)
{
    int large = array[0], index = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] > large) {
            large = array[i];
            index = i;
        }
    }
    return index;
}