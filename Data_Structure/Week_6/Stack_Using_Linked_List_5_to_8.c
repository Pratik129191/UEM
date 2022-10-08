#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int value;
    struct stack_node* next;
}node_char;

node_char* stack = NULL;

void push();
void pop();
void peep();
void display();

int main() {
    label:
    printf("\t|~~~~~~~~~~~~~~~~~|\n");
    printf("\t|     1. Push     |\n");
    printf("\t|     2. Pop      |\n");
    printf("\t|     3. Peep     |\n");
    printf("\t|     4. Display  |\n");
    printf("\t|     5. Exit     |\n");
    printf("\t|~~~~~~~~~~~~~~~~~|\n");
    int choice;
    printf("Enter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Choice.\n Choose Again.\n");
            goto label;
    }
    goto label;
}

void push() {
    node_char* temp = (node_char*) malloc(sizeof(node_char));
    if (temp == NULL) {
        printf("Memory Can't be Allocated.\nSystem Terminating.\n");
        exit(0);
    } else {
        printf("Enter The Item to Push Into Stack:\t");
        scanf("%d", &temp->value);
        temp->next = NULL;
    }

    if (stack == NULL) {
        stack = temp;
    } else {
        temp->next = stack;
        stack = temp;
    }
}

void pop() {
    if (stack == NULL) {
        printf("Stack is Empty.\nUnderFlow Occurred.\nTry To Push Into Stack.\n");
    } else {
        node_char *ptr = stack;
        stack = stack->next;
        printf("%d is Popped from Stack.\n", ptr->value);
        free(ptr);
    }
}

void peep() {
    if (stack == NULL) {
        printf("Stack is Empty.\nUnderFlow Occurred.\nTry To Push Into Stack.\n");
    } else {
        printf("The Topmost Element of Stack is %d\n", stack->value);
    }
}

void display() {
    node_char* ptr = stack;
    printf("<==== Displaying The Stack ====>\n");
    if (stack == NULL) {
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