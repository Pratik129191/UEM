#include<stdio.h>

int main()
{
    int length;
    printf("Enter The Length of the Array:\t");
    scanf("%d", &length);

    int array[length], total = 0;
    printf("Enter The Array Elements:\n");
    for (int i = 0; i < length; ++i) {
        printf("Value of Element %d is:\t", i+1);
        scanf("%d", &array[i]);

        total += array[i];
    }

    printf("Sum of all Array Elements is: %d.", total);


}