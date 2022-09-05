#include<stdio.h>
#include <stdlib.h>

int main()
{
    int length;
    printf("Enter The Length of the Array:\t");
    scanf("%d", &length);

    int array[length];
    for (int i = 0; i < length; ++i) {
        printf("Element %d is:\t", i+1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < length; ++i) {
        for (int j = i+1; j < length; ++j) {
            if (array[i] == array[j])
            {
                printf("This Array Contains duplicates of %d Element.", array[i]);
                exit(0);
            }
        }
    }
    printf("Didn't Contains Duplicates.");
}

