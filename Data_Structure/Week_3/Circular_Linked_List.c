#include <stdio.h>
#include <stdlib.h>

typedef struct circular_list {
    int value;
    struct circular_list* next;
}node;

node* head = NULL;
node* tail = NULL;

void createCircularList(int length);
void displayCircularList();
void insertAtBeginning();
void insertAtEnd();
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterTheGivenNode();
void deleteEntireCircularList();

int main()
{
    int length;
    printf("Enter Length of The Linked List:\t");
    scanf("%d", &length);
    createCircularList(length);

    label:
    printf(" ____________________________________________\n");
    printf("|        1 --> Insert at Beginning           |\n");
    printf("|        2 --> Insert at End                 |\n");
    printf("|        3 --> Delete From Beginning         |\n");
    printf("|        4 --> Delete From End               |\n");
    printf("|        5 --> Delete After Given Node       |\n");
    printf("|        6 --> Delete Entire List            |\n");
    printf("|        7 --> Display Circular List         |\n");
    printf("|        8 --> Exit From Program             |\n");
    printf(" --------------------------------------------\n");
    
    int choice;
    printf("Enter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            deleteFromEnd();
            break;
        case 5:
            deleteAfterTheGivenNode();
            break;
        case 6:
            deleteEntireCircularList();
            break;
        case 7:
            displayCircularList();
            break;
        case 8:
            exit(0);
    }
    goto label;
}

void createCircularList(int length)
{
    node* temp = NULL;

    for (int i = 0; i < length; ++i) {
        temp = (node*) malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory Can't be Allocated.\nSystem Terminating.");
            exit(0);
        } else {
            printf("Value of %d is: ", i+1);
            scanf("%d", &temp->value);
        }

        if (head == NULL) {
            head = temp;
            tail = temp;
            temp->next = head;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
    }
}

void displayCircularList() {
    printf("<======= Displaying Circular Linked List ======>\n");
    if (head == NULL) {
        printf("List is Empty.\n");
    } else {
        node *ptr = head;
        if (head == NULL) {
            printf("List is Empty.");
        } else {
            do {
                printf("%d --> ", ptr->value);
                ptr = ptr->next;
            } while (ptr != head);
            printf("HEAD.\n");
        }
    }
}

void insertAtBeginning() {
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't be allocated./n System Terminating.\n");
        exit(0);
    } else {
        printf("Enter The Value to Insert:\t");
        scanf("%d", &temp->value);
    }
    temp->next = head;
    head = temp;
    tail->next = head;
}

void insertAtEnd() {
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't be allocated./n System Terminating.\n");
        exit(0);
    } else {
        printf("Enter The Value to Insert:\t");
        scanf("%d", &temp->value);
    }
    tail->next = temp;
    tail = temp;
    tail->next = head;
}

void deleteFromBeginning() {
    node* ptr = head;
    head = head->next;
    tail->next = head;
    free(ptr);
}

void deleteFromEnd() {
    node* ptr = head;
    while (ptr->next != tail) {
        ptr = ptr->next;
    }
    free(tail);
    tail = ptr;
    tail->next = head;
}

void deleteAfterTheGivenNode() {
    int data;
    printf("After Which Node Value Should be Deleted: ");
    scanf("%d", &data);

    node* ptr = head;
    while (ptr->value != data) {
        ptr = ptr->next;
    }

    node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

void deleteEntireCircularList() {
    node* ptr = head;
    node* temp = NULL;
    while (ptr != tail) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(tail);
}
