#include <stdio.h>
#include <string.h>
#include "stack_char.h"
#include "functions.h"

char *infixToPostfix(char *expr);
char *infixToPrefix(char *expr);


int main() {
    char expr[50], expr_cpy[50];
    printf("Enter The Infix Expression:\t");
    gets(expr);
    strcpy(expr_cpy, expr);

    // exclude all spaces & enclose whole expression within a parenthesis.

    char *post = infixToPrefix(expr);
    printf("\n\n%s\n\n%s",post, expr_cpy);
}

char *infixToPostfix(char *expr) {
    int i, k;
    char *postfix = malloc(strlen(expr));
    reformatExpression(&expr[0]);
    node_char *stack = createStack();

    for (i = 0, k = -1; i < strlen(expr); ++i) {
        if (isOperand(expr[i])) {
            postfix[++k] = expr[i];
        } else if (expr[i] == LEFT_PARENTHESIS) {
            pushElement(expr[i], &stack);
        } else if (expr[i] == RIGHT_PARENTHESIS) {
            while (!isEmpty(&stack) && peekElement(&stack) != LEFT_PARENTHESIS)
                postfix[++k] = popElement(&stack);

            if (!isEmpty(&stack) && peekElement(&stack) != LEFT_PARENTHESIS) {
                printf("Inappropriate Expression Input.\nSystem, Terminating.");
                exit(0);
            } else {
                popElement(&stack);
            }
        } else {
            while (!isEmpty(&stack) && (precedenceOf(peekElement(&stack)) > precedenceOf(expr[i]))) {
                postfix[++k] = popElement(&stack);
            }
            pushElement(expr[i], &stack);
        }
    }

    while (!isEmpty(&stack)) {
        if (peekElement(&stack) == LEFT_PARENTHESIS) {
            popElement(&stack);
        } else {
            postfix[++k] = popElement(&stack);
        }
    }
    postfix[++k] = STRING_TERMINATOR;
    return postfix;
}

char *infixToPrefix(char *expr) {
    reformatExpression(&expr[0]);
    reverseExpression(&expr[0]);
    char *prefix = infixToPostfix(expr);
    strrev(prefix);
    return prefix;
}

