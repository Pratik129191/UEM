#include <stdio.h>

int main() {
    int decimal;
    printf("Enter The Decimal Number:\t");
    scanf("%d", &decimal);

    int binary[20], count = 0;
    while (decimal != 0) {
        binary[count] = (decimal % 2);
        decimal /= 2;
        count++;
    }

    printf("The Binary Value is:\t");
    for (int i = count-1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}



