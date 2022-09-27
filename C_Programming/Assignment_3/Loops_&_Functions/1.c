#include <stdio.h>

int main() {
    int number, expo, result = 1;
    printf("Enter The Number:\t");
    scanf("%d", &number);

    printf("Enter The Exponent:\t");
    scanf("%d", &expo);

    for (int i = 0; i < expo; ++i) {
        result *= number;
    }

    printf("The Result is: %d", result);
}