#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack_node {
    char value;
    struct stack_node* next;
}node_char;


node_char* createStack();
void pushElement(char item, node_char** stack);
char popElement(node_char** stack);
char peekElement(node_char** stack);
bool isEmpty(node_char** stack);
void display(node_char** stack);


node_char* createStack() {
    node_char* stack = NULL;
    return stack;
}

void pushElement(char item, node_char** stack) {
    node_char* temp = (node_char*) malloc(sizeof(node_char));
    if (temp == NULL) {
        exit(0);
    } else {
        temp->value = item;
        temp->next = NULL;
    }

    if ((*stack) == NULL) {
        (*stack) = temp;
    } else {
        temp->next = (*stack);
        (*stack) = temp;
    }
}

void display(node_char** stack) {
    node_char* ptr = (*stack);
    printf("<==== Displaying The Stack ====>\n");
    if (isEmpty(&(*stack))) {
        printf("\t\t|      |\n");
        printf("\t\t|------|\n");
    } else {
        while (ptr != NULL) {
            printf("\t\t|  %d  |\n", ptr->value);
            printf("\t\t|------|\n");
            ptr = ptr->next;
        }
    }
    printf("\n");
}

char popElement(node_char **stack) {
    char value = CHAR_MIN;
    if (!isEmpty(&(*stack))) {
        node_char *ptr = (*stack);
        value = ptr->value;
        (*stack) = (*stack)->next;
        free(ptr);
    }
    return value;
}

char peekElement(node_char **stack) {
    char value = CHAR_MIN;
    if (!isEmpty(&(*stack))) {
        value = (*stack)->value;
    }
    return value;
}

bool isEmpty(node_char **stack) {
    return ((*stack) == NULL);
}


