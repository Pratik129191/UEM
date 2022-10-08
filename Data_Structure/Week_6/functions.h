#include <stdbool.h>
#define LEFT_PARENTHESIS '('
#define RIGHT_PARENTHESIS ')'
#define STRING_TERMINATOR '\0'
#define SPACE ' '


int precedenceOf(char symbol);
int convertToInt(char ch);
char convertToChar(int i);
bool isOperand(char symbol);
bool isOperator(char symbol);
void reformatExpression(char *expr);
void reverseExpression(char *expr);

int precedenceOf(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

bool isOperand(char symbol) {
    return (symbol >= 'a' && symbol <= 'z')
           || (symbol >= 'A' && symbol <= 'Z');
}

void reformatExpression(char *expr) {
    int i, k;
    char str[strlen(expr)];
    str[0] = LEFT_PARENTHESIS;
    for (i = 0, k = 1; i < strlen(expr); ++i) {
        if (expr[i] != SPACE)
            str[k++] = expr[i];
    }
    str[k++] = RIGHT_PARENTHESIS;
    str[k] = STRING_TERMINATOR;
    strcpy(expr, str);
}

void reverseExpression(char *expr) {
    char *rev = strrev(expr);
    char str[strlen(rev)];
    int i, k;
    for (i = 0, k = 0; i < strlen(rev); ++i) {
        if (rev[i] == LEFT_PARENTHESIS)
            str[k++] = RIGHT_PARENTHESIS;
        else if (rev[i] == RIGHT_PARENTHESIS)
            str[k++] = LEFT_PARENTHESIS;
        else
            str[k++] = rev[i];
    }
    str[k] = STRING_TERMINATOR;
    strcpy(expr, str);
}

bool isOperator(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return true;
    }
    return false;
}

int convertToInt(char ch) {
    return ch - '0';
}

char convertToChar(int i) {
    return '0' + i;
}

