#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack_int.h"
#include "functions.h"

int evaluatePostfix(char *expr);
int evaluatePrefix(char *expr);

int main() {
    char expr[50];
    label:
    printf("\nEvaluate Post-Fix Expression ---> 1\n");
    printf("Evaluate Pre-Fix Expression ---> 2\n");
    printf("Exit The Program ---> 3\n");
    int choice;
    printf("Enter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter The Post-Fix Expression:\t");
            getchar();
            gets(expr);
            printf("Result of This Expression is:%d\t", evaluatePostfix(expr));
            break;
        case 2:
            printf("Enter The Pre-Fix Expression:\t");
            getchar();
            gets(expr);
            printf("Result of This Expression is:%d\t", evaluatePrefix(expr));
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong Choice.\nSystem Terminated.\n");
            goto label;
    }
    goto label;
}

int evaluatePostfix(char *expr) {
    int a, b;
    node_int* stack = createStack();
    for (int i = 0; i < strlen(expr); ++i) {
        if (isOperator(expr[i]) && !isEmpty(&stack)) {
            switch (expr[i]) {
                case '+':
                    a = popElement(&stack);
                    b = popElement(&stack);
                    pushElement((b + a), &stack);
                    break;
                case '-':
                    a = popElement(&stack);
                    b = popElement(&stack);
                    pushElement((b - a), &stack);
                    break;
                case '*':
                    a = popElement(&stack);
                    b = popElement(&stack);
                    pushElement((b * a), &stack);
                    break;
                case '/':
                    a = popElement(&stack);
                    b = popElement(&stack);
                    pushElement((b / a), &stack);
                    break;
                case '%':
                    a = popElement(&stack);
                    b = popElement(&stack);
                    pushElement((b % a), &stack);
                    break;
                case '^':
                    a = popElement(&stack);
                    b = popElement(&stack);
                    pushElement((int) pow(b, a), &stack);
                    break;
            }
        } else {
            pushElement(convertToInt(expr[i]), &stack);
        }
    }
    return popElement(&stack);
}

int evaluatePrefix(char *expr) {
    strrev(expr);
    return evaluatePostfix(expr);
}
