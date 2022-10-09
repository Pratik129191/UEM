#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = 0, count = 0;
int max_length;

int *createQueue(int length);
void enqueue(int item, int *queue);
int dequeue(int *queue);
int peekElement(int *queue);
void internal_display(int *queue);  // for testing purpose only ...
void display_queue(int *queue);
int reset(int index);


int main() {
    int choice, item;
    int *queue = NULL;
    label:
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t|   1 -> Create Queue.   |\n");
    printf("\t|   2 -> Enqueue.        |\n");
    printf("\t|   3 -> Dequeue.        |\n");
    printf("\t|   4 -> Peek Element.   |\n");
    printf("\t|   5 -> Display Queue.  |\n");
    printf("\t|   6 -> Exit Program.   |\n");
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\tEnter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter The Length of the Queue:\t");
            scanf("%d", &max_length);
            queue = createQueue(max_length);
            break;
        case 2:
            printf("Enter The Item:\t");
            scanf("%d", &item);
            enqueue(item, queue);
            break;
        case 3:
            printf("%d is Eliminated From Queue.\n", dequeue(queue));
            break;
        case 4:
            printf("%d is the Peek Element in Queue.\n", peekElement(queue));
            break;
        case 5:
            display_queue(queue);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong Choice.\nChoose Again.\n");
            goto label;
    }
    goto label;
}

int *createQueue(int length) {
    int *init = (int *) malloc(sizeof(int) * length);
    if (init == NULL) {
        printf("Memory Can't be Allocated.\nSystem Terminating.");
        exit(0);
    }
    return init;
}

void enqueue(int item, int *queue) {
    if (count == max_length) {
        printf("Queue is Full.\n");
        return;
    }
    queue[rear] = item;
    rear = reset(rear);
    count++;
}

int dequeue(int *queue) {
    int item = queue[front];
    queue[front] = 0;
    front = reset(front);
    count--;
    return item;
}

void internal_display(int *queue) {
    printf("[");
    for (int i = 0; i < max_length; ++i) {
        printf("%d, ", queue[i]);
    }
    printf("\b\b]");
}

int reset(int index) {
    return ((index + 1) % max_length);
}

void display_queue(int *queue) {
    printf("\t<=== Displaying The Queue ===>\n\t[");
    int i = front;
    do {
        printf("%d, ", queue[i]);
        i = reset(i);
    } while (i != rear);
    printf("\b\b]\n\n");
}

int peekElement(int *queue) {
    return queue[front];
}

