#include<stdio.h>
#include<stdlib.h>

int partition(int* array, int low, int high);
void quick_sort(int* array, int low, int high);
void display_quick(int array[], int length);
void swap(int* x, int* y);

int main()
{
    int length;
    printf("How mnay elements will be in array:- ");
    scanf("%d", &length);

    int array[50];
    for (int i = 0; i < length; i++)
    {
        printf("Element No %d is:- ", i + 1);
        scanf("%d", &array[i]);
    }

    quick_sort(array, 0, length-1);
    display_quick(array,length);
}

int partition(int* array, int low, int high)
{
    // take last element always as pivot -----
    int pivot = array[high];
    int i = low;	// first index, from where the smaller elements than pivot will be kept.
    for (int j = 0; j < high; j++)
    {
        // if current element is smaller than the pivot -----
        if (array[j]<pivot)
        {
            swap(&array[i], &array[j]);
            i++;	// increment the index of smaller element to store next ----
        }
    }
    // get the pivot in its correct position -------
    swap(&array[i], &array[high]);
    return i;
}

void quick_sort(int* array, int low, int high)
{
    int pi=0;	// initialising the partition index variable ----
    if (low<high)
    {
        pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void display_quick(int array[], int length)
{
    printf("\nAfter sorting the array is ------\n\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}