#include <stdio.h>

double findAverage(int *start, int *end);

int main() {
    int start, end;
    printf("Enter The Starting Range:\t");
    scanf("%d", &start);
    printf("Enter The Ending Range:\t");
    scanf("%d", &end);
    printf("Average of The Given Range is: %lf", findAverage(&start, &end));
}

double findAverage(int *start, int *end) {
    double count = 0, sum = 0;
    for (int i = *start; i <= *end; ++i) {
        sum += i;
        count++;
    }
    return sum / count;
}