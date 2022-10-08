#include "stack_int.h"
#include <string.h>


int main() {
    int number;
    printf("Enter The Number:\t");
    scanf("%d", &number);

    node_int* stack = createStack();
    while (number != 0) {
        pushElement(number %10, &stack);
        number /= 10;
    }

    int reverse = 0, offset = 1;
    while (!isEmpty(&stack)) {
        reverse += popElement(&stack) * offset;
        offset *= 10;
    }

    printf("Reversed Number is:\t%d", reverse);
}
