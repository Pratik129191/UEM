#include <stdio.h>

void swap(int *p, int *q);

int main() {
    int x, y;
    printf("Enter The Value of X:\t");
    scanf("%d", &x);
    printf("Enter The Value of Y:\t");
    scanf("%d", &y);
    swap(&x, &y);
    printf("After Swapping: ===>\n");
    printf("X = %d\nY = %d",x, y);

}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}