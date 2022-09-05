#include <stdio.h>

int main()
{
    int length;
    printf("How Many Fibonacci Numbers should be printed:\t");
    scanf("%d", &length);

    int a = 0, b = 1, c;
    printf("%d\t%d\t", a, b);
    for (int i = 0; i < length; ++i) {
        c = a + b;
        printf("%d\t", c);
        a = b;
        b = c;
    }
}