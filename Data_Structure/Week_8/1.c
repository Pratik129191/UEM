#include<stdio.h>

void bubble_sort(int* array, int length);
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
        printf("Element No %d is:- ", i + 1);
        scanf("%d", &array[i]);
    }

    bubble_sort(array, length);
    display(array, length);
}

void bubble_sort(int* array, int length)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (array[j]<array[i])
            {
                swap(&array[j], &array[i]);
            }
        }
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
        printf("%d\t", array[i]);
    }
}