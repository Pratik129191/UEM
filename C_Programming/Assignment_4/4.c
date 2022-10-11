#include <stdio.h>

void bubbleSort(int *array, int length);
void swap(int *p, int *q);

int main() {
    int length;
    printf("How Many Elements will be in the Array:\t");
    scanf("%d", &length);
    printf("Enter The Array Elements: ====>\n");
    int array[length];
    for (int i = 0; i < length; ++i) {
        printf("Enter Value No %d", i+1);
        scanf("%d", &array[i]);
    }
    bubbleSort(&array[0], length);
    printf("After Sorting: ====>\n");
    for (int i = 0; i < length; ++i) {
        printf("%d\t", array[i]);
    }
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int *array, int length) {
    for (int i = 0; i < length-1; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (array[j] < array[i])
            {
                swap(&(array[j]), &(array[i]));
            }
        }
    }
}
