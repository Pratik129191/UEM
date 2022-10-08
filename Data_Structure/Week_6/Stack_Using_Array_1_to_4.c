#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX], count = 0;

void push();
int pop();
int peep();
void display();

int main()
{
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
            printf("%d is Popped from Stack.\n", pop());
            break;
        case 3:
            printf("The Topmost Element of Stack is %d\n", peep());
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
    if (count >= MAX) {
        printf("Stack is Full.\nOverflow Occurs.");
        exit(0);
    }
    int item;
    printf("Enter The Item to Push into Stack:\t");
    scanf("%d", &item);
    stack[count++] = item;
}

int pop() {
    if (count <= 0) {
        printf("Stack is Empty.\nUnderflow Occurs.");
        exit(0);
    }
    return stack[--count];
}

int peep() {
    if (count - 1 <= 0) {
        printf("Stack is Empty.\nUnderflow Occurs.\n");
        exit(0);
    }
    return stack[count - 1];
}

void display() {
    printf("<==== Displaying The Stack ====>\n");
    for (int i = count-1; i >= 0; --i) {
        printf("\t\t|  %d  |\n", stack[i]);
        printf("\t\t|------|\n");
    }
    printf("\n");
}
