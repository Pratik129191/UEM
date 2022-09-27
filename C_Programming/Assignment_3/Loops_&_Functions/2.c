#include <stdio.h>

int countDigits(int digit);

int countDigits(int digit) {
    static int count = 0;
    if (digit > 0) {
        count++;
        countDigits(digit / 10);
    }
    return count;
}

int main() {
    int digit;
    printf("Enter The Digit:\t");
    scanf("%d", &digit);

    printf("Number of Digits is: %d", countDigits(digit));
}
