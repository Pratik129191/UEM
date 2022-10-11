#include <stdio.h>
#include <math.h>

double calculateSeries(int n);

int main() {
    int n;
    printf("Enter The Length of the Series:\t");
    scanf("%d", &n);
    printf("%lf", calculateSeries(3));
}

double calculateSeries(int n) {
    if (n == 1)
        return 1;
    return pow(n, n) + calculateSeries(n-1);
}
