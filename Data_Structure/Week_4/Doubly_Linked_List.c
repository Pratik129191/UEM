#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_linked_node {
    struct doubly_linked_node* previous;
    int value;
    struct doubly_linked_node* next;
}node;

node* head = NULL;

void createLinkedList(int length);
void displayLinkedListForward();
void displayLinkedListBackward();
void insertAtBeginning();
void insertAtEnd();
void insertBeforeAnyNode();
void insertAfterAnyNode();
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterAnyNode();
void deleteBeforeAnyNode();
void deleteEntireLinkedList();


int main()
{
    int length;
    printf("Enter The Length of the Linked List:\t");
    scanf("%d", &length);
    createLinkedList(length);

    label:
    printf("\n");
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t|        1 --> Insert At Beginning        |\n");
    printf("\t|        2 --> Insert At End              |\n");
    printf("\t|        3 --> Insert Before Any Node     |\n");
    printf("\t|        4 --> Insert After Any Node      |\n");
    printf("\t|        5 --> Delete From Beginning      |\n");
    printf("\t|        6 --> Delete From End            |\n");
    printf("\t|        7 --> Delete After Any Node      |\n");
    printf("\t|        8 --> Delete Before Any Node     |\n");
    printf("\t|        9 --> Delete Entire List         |\n");
    printf("\t|       10 --> Display in Forward Order   |\n");
    printf("\t|       11 --> Display in Backward Order  |\n");
    printf("\t|       12 --> Exit The Program           |\n");
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

    int choice;
    printf("\nEnter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertBeforeAnyNode();
            break;
        case 4:
            insertAfterAnyNode();
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            deleteAfterAnyNode();
            break;
        case 8:
            deleteBeforeAnyNode();
            break;
        case 9:
            deleteEntireLinkedList();
            break;
        case 10:
            displayLinkedListForward();
            break;
        case 11:
            displayLinkedListBackward();
            break;
        case 12:
            exit(0);
        default:
            printf("Wrong Choice.\nChoose Again\n");
            goto label;
    }
    goto label;
}

void createLinkedList(int length)
{
    node* temp = NULL;
    node* ptr = NULL;

    for (int i = 0; i < length; ++i) {
        // creating isolated node ....
        temp = (node*) malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory Can't be allocated.\nSystem Terminating\n");
            exit(0);
        } else {
            printf("Enter The Value for %d th Node:\t", i+1);
            scanf("%d", &temp->value);
            temp->previous = NULL;
            temp->next = NULL;
        }

        if (head == NULL) {
            head = temp;
        } else {
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->previous = ptr;
        }
    }
}

void displayLinkedListForward() {
    node* ptr = head;
    while (ptr != NULL) {
        printf("%d --> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL.\n");
}

void displayLinkedListBackward() {
    node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    printf("NULL");
    while (ptr != NULL) {
        printf(" <-- %d", ptr->value);
        ptr = ptr->previous;
    }
}

void insertAtBeginning() {
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't Be Allocated.\nSystem Terminating.\n");
        exit(0);
    } else {
        printf("Enter The Value to be Inserted at Beginning:\t");
        scanf("%d", &temp->value);
        temp->previous = NULL;
        temp->next = NULL;
    }

    head->previous = temp;
    temp->next = head;
    head = temp;
}

void insertAtEnd() {
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't be Allocated.\nSystem Terminating.\n");
        exit(0);
    } else {
        printf("Enter The Value to be Inserted At End:\t");
        scanf("%d", &temp->value);
        temp->previous = NULL;
        temp->next = NULL;
    }

    node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->previous = ptr;
}

void insertBeforeAnyNode() {
    int node_value;
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can;t be Allocated.\nSystem Terminating\n");
        exit(0);
    } else {
        printf("Before Which Node Value should be Inserted:\t");
        scanf("%d", &node_value);
        printf("Enter The Value:\t");
        scanf("%d", &temp->value);
        temp->previous = NULL;
        temp->next = NULL;
    }

    node* ptr = head;
    while (ptr->value != node_value) {
        ptr = ptr->next;
    }

    temp->previous = ptr->previous;
    temp->next = ptr;
    ptr->previous->next = temp;
    ptr->previous = temp;
}

void insertAfterAnyNode() {
    int node_value;
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can;t Be Allocated.\nSystem Terminating\n");
        exit(0);
    } else {
        printf("After Which Node Data Should Be Inserted:\t");
        scanf("%d", &node_value);
        printf("Enter The Value:\t");
        scanf("%d", &temp->value);
        temp->previous =  NULL;
        temp->next = NULL;
    }

    node* ptr = head;
    while (ptr->value != node_value) {
        ptr = ptr->next;
    }

    temp->previous = ptr;
    temp->next = ptr->next;
    ptr->next->previous = temp;
    ptr->next = temp;
}

void deleteFromBeginning() {
    node* ptr = head;
    head = head->next;
    head->previous = NULL;
    free(ptr);
}

void deleteFromEnd() {
    node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->previous->next = NULL;
    free(ptr);
}

void deleteAfterAnyNode() {
    int node_value;
    printf("After Which Node Data Should be Deleted:\t");
    scanf("%d", &node_value);

    node* ptr = head;
    while (ptr->value != node_value) {
        ptr = ptr->next;
    }
    ptr = ptr->next;

    ptr->previous->next = ptr->next;
    ptr->next->previous = ptr->previous;
    free(ptr);
}

void deleteBeforeAnyNode() {
    int node_value;
    printf("Before Which Node Data Should be Deleted:\t");
    scanf("%d", &node_value);

    node* ptr = head;
    while (ptr->value != node_value) {
        ptr = ptr->next;
    }
    ptr = ptr->previous;

    ptr->previous->next = ptr->next;
    ptr->next->previous = ptr->previous;
    free(ptr);
}

void deleteEntireLinkedList() {
    node* ptr = head;
    node* temp = NULL;
    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ptr);
}
