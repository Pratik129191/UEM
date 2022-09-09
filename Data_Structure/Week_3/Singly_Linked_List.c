#include <stdio.h>
#include <stdlib.h>

typedef struct linked_node {
    int data;
    struct linked_node* next;
}node;

node* createLinkedList(int length);
node* insertAtBeginning(node* head);
node* insertAtEnd(node* head);
node* insertBeforeAnyNode(node* head);
node* insertAfterAnyNode(node* head);
node* deleteFromTheBeginning(node* head);
node* deleteFromEnd(node* head);
node* deleteAfterAnyNode(node* head);
node* deleteAnyNode(node* head);
node* deleteEntireList(node* head);
void displayLinkedList(node* head);

int main()
{
    int length;
    printf("Enter How Nodes You Want Create:\t");
    scanf("%d", &length);

    node* head = NULL;
    head = createLinkedList(length);
    printf(" ____________________________________________\n");
    printf("|        1 --> Insert at Beginning           |\n");
    printf("|        2 --> Insert at End                 |\n");
    printf("|        3 --> Insert Before Any Node        |\n");
    printf("|        4 --> Insert After Any Node         |\n");
    printf("|        5 --> Delete From Beginning         |\n");
    printf("|        6 --> Delete From End               |\n");
    printf("|        7 --> Delete After Any Node         |\n");
    printf("|        8 --> Delete Any Node               |\n");
    printf("|        9 --> Delete Entire List            |\n");
    printf("|       10 --> Display Linked List           |\n");
    printf("|       11 --> Exit From Program             |\n");
    printf(" --------------------------------------------\n");
    int choice;
    label: printf("Enter Your Choice:\t");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = insertAtBeginning(head);
            break;
        case 2:
            head = insertAtEnd(head);
            break;
        case 3:
            head = insertBeforeAnyNode(head);
            break;
        case 4:
            head = insertAfterAnyNode(head);
            break;
        case 5:
            head = deleteFromTheBeginning(head);
            break;
        case 6:
            head = deleteFromEnd(head);
            break;
        case 7:
            head = deleteAfterAnyNode(head);
            break;
        case 8:
            head = deleteAnyNode(head);
            break;
        case 9:
            head = deleteEntireList(head);
            break;
        case 10:
            displayLinkedList(head);
            break;
        case 11:
            exit(0);
    }
    goto label;
}

node* createLinkedList(int length)
{
    node* head = NULL;
    node* temp = NULL;
    node* ptr = NULL;

    for (int i = 0; i < length; ++i) {
        // creating isolated node ...
        temp = (node *) malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory Can't be Allocated.\nSystem Terminating.");
            exit(0);
        } else {
            printf("Enter The Data For Node %d:\t", i + 1);
            scanf("%d", &temp->data);
            temp->next = NULL;
        }

        if (head == NULL) {        // assigning first node to Head ...
            head = temp;
        } else {        // appending rest nodes to list ...
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    return head;
}

void displayLinkedList(node *head) {
    node* ptr = head;
    printf("<======== Displaying The Linked List ========>\n\t\t");
    while (ptr != NULL) {
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n\n");
}

node* insertAtBeginning(node *head) {
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory NOt Allocated.\nSystem Terminating.");
        exit(0);
    } else {
        printf("Enter The Value to be Inserted:\t");
        scanf("%d", &temp->data);
    }

    temp->next = head;
    head = temp;
    return head;
}

node* insertAtEnd(node *head) {
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't be Allocated.\nSystem Terminating.");
        exit(0);
    } else {
        printf("Enter The Data To Be Inserted:\t");
        scanf("%d", &temp->data);
        temp->next = NULL;
    }
    node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

node *insertBeforeAnyNode(node *head) {
    int value;
    printf("Before Which Node Value Should Be Inserted:\t");
    scanf("%d", &value);
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't Be Allocated.\nSystem Terminating.");
    } else {
        printf("Enter The Value To Be Inserted:\t");
        scanf("%d", &temp->data);
        temp->next = NULL;
    }

    node* ptr = head;
    while (ptr->next->data != value) {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

node *insertAfterAnyNode(node *head) {
    int value;
    printf("After Which Node Value Should Be Inserted:\t");
    scanf("%d", &value);
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't Be Allocated.\nSystem Terminating.");
    } else {
        printf("Enter The Value To Be Inserted:\t");
        scanf("%d", &temp->data);
        temp->next = NULL;
    }

    node* ptr = head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

node *deleteFromTheBeginning(node *head) {
    node* ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}

node *deleteFromEnd(node *head) {
    node* ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

node *deleteAfterAnyNode(node *head) {
    int value;
    printf("After Which Node Value Should be Deleted:\t");
    scanf("%d", &value);

    node* ptr = head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    node* temp = ptr->next->next;
    free(ptr->next);
    ptr->next = temp;
    return head;
}

node *deleteAnyNode(node *head) {
    int value;
    printf("Enter Which NOde Should be Deleted:\t");
    scanf("%d", &value);

    node* ptr = head;

    if (ptr->data == value) {
        head = ptr->next;
        free(ptr);
    } else {
        while (ptr->next->data != value) {
            ptr = ptr->next;
        }

        node* temp = ptr->next->next;
        free(ptr->next);
        ptr->next = temp;
    }
    return head;
}

node *deleteEntireList(node *head) {
    node* ptr = head;
    node* temp;
    while (ptr != NULL) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    return head
}

