#include<stdio.h>

int smallest_element(int* array, int length);

int main()
{
    int length;
    printf("Enter The length:\t");
    scanf("%d", &length);

    int array[length];
    printf("Enter The Array Elements :===>\n");
    for (int i = 0; i < length; ++i) {
        printf("%d th Element is:\t", i+1);
        scanf("%d", &array[i]);
    }

    int small = smallest_element(array, length);
    printf("The Smallest Element is %d", small);
}

int smallest_element(int* array, int length)
{
    int small = array[0], index = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] < small)
        {
            small = array[i];
            index = i;
        }
    }
    return small;
}