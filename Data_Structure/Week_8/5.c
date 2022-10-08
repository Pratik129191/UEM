#include<stdio.h>
#include<stdlib.h>

void merge_sort(int* array, int lower, int upper);
void merge(int* array, int lower, int middle, int upper);
void display_merge(int array[], int length);
int main()
{
    int length;
    printf("Enter the length of the array:- ");
    scanf("%d", &length);

    int array[50];
    for (int i = 0; i < length; i++)
    {
        printf("Element No %d is:- ", i + 1);
        scanf("%d", &array[i]);
    }

    merge_sort(array, 0, length - 1);
    display_merge(array, length);
}

void merge_sort(int* array, int lower, int upper)
{
    int mid = 0;
    if (lower<upper)
    {
        mid = (lower + upper) / 2;

        // sort for first half -----
        merge_sort(array, lower, mid);
        // sort for second half -----
        merge_sort(array, mid + 1, upper);

        // merge above two halfs after sorting -------
        merge(array, lower, mid, upper);
    }
}

void merge(int* array, int lower, int middle, int upper)
{
    // getting the length of two sub-arrays -----
    int length1, length2;
    length1 = middle - lower + 1;
    length2 = upper - middle;

    // creating temp arrays ----
    int left[26];
    int right[25];

    // copying data from the array to the temp array -----
    for (int i = 0; i < length1; i++)
    {
        left[i] = array[lower + i];
    }
    for (int j = 0; j < length2; j++)
    {
        right[j] = array[middle + 1 + j];
    }

    // merge the temp arrays back into the main array -------
    int i = 0;	// initial index of left sub array.
    int j = 0;	// initial index of right sub array.
    int k = lower;	// initial index of merged sub array.
    while (i < length1 && j < length2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of left array if there are any ---------
    while (i < length1)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    // copy the remaining elements of right array if there are any ---------
    while (j < length2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void display_merge(int array[], int length)
{
    printf("\n After sorting the array is -----\n\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
}