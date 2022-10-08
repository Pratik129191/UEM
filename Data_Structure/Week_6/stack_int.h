#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack_node {
    int value;
    struct stack_node* next;
}node_int;


node_int* createStack();
void pushElement(int item, node_int** stack);
int popElement(node_int** stack);
int peekElement(node_int** stack);
bool isEmpty(node_int** stack);
void display(node_int** stack);


node_int* createStack() {
    node_int* stack = NULL;
    return stack;
}

void pushElement(int item, node_int** stack) {
    node_int* temp = (node_int*) malloc(sizeof(node_int));
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

void display(node_int** stack) {
    node_int* ptr = (*stack);
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

int popElement(node_int **stack) {
    int value = INT_MIN;
    if (!isEmpty(&(*stack))) {
        node_int *ptr = (*stack);
        value = ptr->value;
        (*stack) = (*stack)->next;
        free(ptr);
    }
    return value;
}

int peekElement(node_int **stack) {
    int value = INT_MIN;
    if (!isEmpty(&(*stack))) {
        value = (*stack)->value;
    }
    return value;
}

bool isEmpty(node_int **stack) {
    return ((*stack) == NULL);
}


