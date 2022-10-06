#include <stdio.h>
#include <stdlib.h>

typedef struct circular_doubly_linked_node {
    struct circular_doubly_linked_node* previous;
    int value;
    struct circular_doubly_linked_node* next;
}node;

node* head = NULL;

void createCircularDoublyLinkedList(int length);
void displayCircularDoublyLinkedListInForward();
void displayCircularDoublyLinkedListInBackward();
void insertAtBeginningOfList();
void insertAtEndOfList();
void deleteFromBeginningOfList();
void deleteFromEndOfList();
void deleteAnyNode();
void deleteEntireList();

int main()
{
    int length;
    printf("Enter The Number of Nodes in List:\t");
    scanf("%d", &length);
    createCircularDoublyLinkedList(length);

    label:
    printf("\n");
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t|     1 --> Insert At Beginning          |\n");
    printf("\t|     2 --> Insert At End                |\n");
    printf("\t|     3 --> Delete From Beginning        |\n");
    printf("\t|     4 --> Delete From End              |\n");
    printf("\t|     5 --> Delete Entire List           |\n");
    printf("\t|     6 --> Display in Forward Order     |\n");
    printf("\t|     7 --> Display in Backward Order    |\n");
    printf("\t|     8 --> Exit The Program             |\n");
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

    int choice;
    printf("Enter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            insertAtBeginningOfList();
            break;
        case 2:
            insertAtEndOfList();
            break;
        case 3:
            deleteFromBeginningOfList();
            break;
        case 4:
            deleteFromEndOfList();
            break;
        case 5:
            deleteEntireList();
            break;
        case 6:
            displayCircularDoublyLinkedListInForward();
            break;
        case 7:
            displayCircularDoublyLinkedListInBackward();
            break;
        case 8:
            exit(0);
        default:
            printf("Wrong Choice.\nChoose Again\n");
            goto label;
    }
    goto label;
}

void createCircularDoublyLinkedList(int length)
{
    node* temp = NULL;
    node* ptr = NULL;

    for (int i = 0; i < length; ++i) {
        temp = (node*) malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory Can't be Allocated.\nSystem Terminating.");
            exit(0);
        } else {
            printf("Enter The Value for Node %d:\t", i+1);
            scanf("%d", &temp->value);
            temp->previous = NULL;
            temp->next = NULL;
        }

        if (head == NULL) {
            head = temp;
            head->previous = temp;
            temp->next = head;
        } else {
            ptr = head->next;
            while (ptr->next != head) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->previous = ptr;
            temp->next = head;
            head->previous = temp;
        }
    }
}

void displayCircularDoublyLinkedListInForward() {
    node* ptr = head;
    printf("@ --> ");
    do {
        printf("%d --> ", ptr->value);
        ptr = ptr->next;
    } while (ptr != head);
    printf("@");
}

void insertAtBeginningOfList() {
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't be Allocated.\nSystem Terminating.");
        exit(0);
    } else {
        printf("Enter The Value to Be Inserted At Beginning:\t");
        scanf("%d", &temp->value);
        temp->previous = NULL;
        temp->next = NULL;
    }

    temp->next = head;
    temp->previous = head->previous;
    head->previous->next = temp;
    head->previous = temp;
    head = temp;
}

void insertAtEndOfList() {
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't be Allocated.\nSystem Terminating.");
        exit(0);
    } else {
        printf("Enter The Value to Be Inserted At End:\t");
        scanf("%d", &temp->value);
        temp->previous = NULL;
        temp->next = NULL;
    }

    head->previous->next = temp;
    temp->previous = head->previous;
    temp->next = head;
    head->previous = temp;
}

void deleteFromBeginningOfList() {
    node* ptr = head;
    head->next->previous = head->previous;
    head->previous->next = head->next;
    head = head->next;
    free(ptr);
}

void deleteFromEndOfList() {
    node* tail = head->previous;

    tail->previous->next = head;
    head->previous = tail->previous;
    free(tail);
}

void deleteAnyNode() {
    int item;
    printf("Enter The Value to be Deleted:\t");
    scanf("%d", &item);

    node* loc = NULL;
    node* ptr = head->next;
    while (ptr != head) {
        if (ptr->value == item) {
            loc = ptr;
            break;
        }
        ptr = ptr->next;
    }

    if (loc == NULL) {
        printf("Item Not Found.\nSystem Terminating.");
        exit(0);
    } else {
        if (loc == head)
            deleteFromBeginningOfList();
        else if (loc == head->previous)
            deleteFromEndOfList();
        else {
            node* before = loc->previous;
            node* after = loc->next;
            before->next = after;
            after->previous = before;
            free(loc);
            printf("%d is Deleted From The List.", item);
        }
    }
}

void deleteEntireList() {
    node* ptr = head->next;
    while (ptr != head) {
         node* temp = ptr;
         ptr = ptr->next;
         free(temp);
    }
    free(ptr);
    printf("Entire List is Deleted.");
}

void displayCircularDoublyLinkedListInBackward() {
    node* ptr = head->previous;
    printf("@ <-- ");
    while (ptr != head) {
        printf("%d <-- ", ptr->value);
        ptr = ptr->previous;
    }
    printf("%d <-- @",ptr->value);
}
