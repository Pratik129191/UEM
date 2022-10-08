#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int* array, int length);
void display_insertion(int array[], int length);
int main()
{
    int length;
    printf("How many array elements will be there:- ");
    scanf("%d", &length);

    int array[50];
    for (int i = 0; i < length; i++)
    {
        printf("Element No %d is:- ", i + 1);
        scanf("%d", &array[i]);
    }

    insertion_sort(array, length);
    display_insertion(array, length);
}

void insertion_sort(int* array, int length)
{
    int key = 0, j = 0;
    for (int i = 0; i < length; i++)
    {
        key = array[i];
        j = i - 1;
        /* moving elements of array[0...... i-1], that are
           greater than the key, to one position up from their
           current position. */
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void display_insertion(int array[], int length)
{
    printf("\n After sorting the array is -----\n\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
}