#include<stdio.h>
#include<stdlib.h>

void selection_sort(int *array, int length);
void swap(int* x, int* y);
void display(int array[], int length);
int main()
{
    int length;
    printf("How many element will be in the array:- ");
    scanf("%d", &length);

    int array[50];
    for (int i = 0; i < length; i++)
    {
        printf("Element No %d is:- ",i+1);
        scanf("%d", &array[i]);
    }

    selection_sort(array, length);
    display(array, length);
}

void selection_sort(int *array, int length)
{
    int min = 0;
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        // finding small element in the sub-array-----
        min = array[i];
        index = i;
        for (int j = i; j < length; j++)
        {
            if (array[j]<min)
            {
                min = array[j];
                index = j;
            }
        }
        // inserting the small element at the first position of the sub-array ------
        swap(&array[i], &array[index]);
    }
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void display(int array[], int length)
{
    printf("\n After sorting the array is -----\n\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t",array[i]);
    }
}