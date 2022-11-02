#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define __max(a, b) ((a > b) ? a : b)
#define __min(a, b) ((a < b) ? a : b)

typedef struct tree_node {
    int value;
    struct tree_node *leftChild;
    struct tree_node *rightChild;
}node;


node *root = NULL;


void normal_insert(int item);       // iterative insertion implemented
bool findElement(int item);
bool isLeafNode(node *current);
void traversePreOrderDFS(node *current);
void traverseInOrderDFS(node *current);
void traversePostOrderDFS(node *current);
void traverseLevelOrderBFS(node *current);
int height(node *current);
int minimumValue(node *tree);
int maximumValue(node *tree);
node *minValueNode(node *current);
node *getNode(int key);
int countTotalNumberOfNodes(node *current);
bool isBinarySearchTree(node *current, int min, int max);
void printNodesAtDistance(node *current, int distance);
node  *deleteNodeDriver(node *current, int key);
node  *deleteNode(int item);

int main() {
    int choice, item;
    label:
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t|    1 -> Insert an Element.     |\n");
    printf("\t|    2 -> Delete an Element.     |\n");
    printf("\t|    3 -> Pre Order Traversal.   |\n");
    printf("\t|    4 -> In Order Traversal.    |\n");
    printf("\t|    5 -> Post Order Traversal.  |\n");
    printf("\t|    6 -> Level Order Traversal. |\n");
    printf("\t|    7 -> Find Largest in BST.   |\n");
    printf("\t|    8 -> Find Smallest in BST.  |\n");
    printf("\t|    9 -> Count Total Elements.  |\n");
    printf("\t|   10 -> Height of BST.         |\n");
    printf("\t|   11 -> Exit The Program.      |\n");
    printf("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter The Value to Insert:\t");
            scanf("%d", &item);
            normal_insert(item);
            break;
        case 2:
            printf("Enter The Element to Delete:\t");
            scanf("%d", &item);
            deleteNode(item);
            break;
        case 3:
            printf("\nPre Order Traversal :===>\n");
            traversePreOrderDFS(root);
            break;
        case 4:
            printf("\nIn Order Traversal :====>\n");
            traverseInOrderDFS(root);
            break;
        case 5:
            printf("\nPost Order Traversal :====>\n");
            traverseInOrderDFS(root);
            break;
        case 6:
            printf("\nLevel Order Traversal :====>\n");
            traverseLevelOrderBFS(root);
            break;
        case 7:
            printf("Largest Value in The Tree is: %d", maximumValue(root));
            break;
        case 8:
            printf("Smallest Value in The Tree is: %d", minimumValue(root));
            break;
        case 9:
            printf("Total Number of Nodes in The Tree is: %d", countTotalNumberOfNodes(root));
            break;
        case 10:
            printf("Height of the Tree is: %d", height(root));
            break;
        case 11:
            exit(0);
        default:
            printf("Wrong Choice.\nChoose Again.\n");
            goto label;
    }
    goto label;
}

void normal_insert(int item) {
    node *temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory Can't Be Allocated.\nSystem Terminating.\n");
        exit(0);
    } else {
        temp->value = item;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
    }

    if (root == NULL) {
        root = temp;
    } else {
        node  *current = root;
        while (1) {
            if (item < current->value) {
                if (current->leftChild == NULL) {
                    current->leftChild = temp;
                    break;
                }
                current = current->leftChild;
            } else {
                if (current->rightChild == NULL) {
                    current->rightChild = temp;
                    break;
                }
                current = current->rightChild;
            }
        }
    }
}

bool findElement(int item) {
    node *current = root;
    while (current != NULL) {
        if (item < current->value)
            current = current->leftChild;
        else if (item > current->value)
            current = current->rightChild;
        else
            return true;
    }
    return false;
}

void traversePreOrderDFS(node *current) {
    if (current == NULL)
        return;
    printf("%d\t", current->value);
    traversePreOrderDFS(current->leftChild);
    traversePreOrderDFS(current->rightChild);
}

void traverseInOrderDFS(node *current) {
    if (current == NULL)
        return;
    traverseInOrderDFS(current->leftChild);
    printf("%d\t", current->value);
    traverseInOrderDFS(current->rightChild);
}

void traversePostOrderDFS(node *current) {
    if (current == NULL)
        return;
    traversePostOrderDFS(current->leftChild);
    traversePostOrderDFS(current->rightChild);
    printf("%d\t", current->value);
}

int height(node *current) {
    if (current == NULL)
        return -1;
    if (isLeafNode(current))
        return 0;
    return 1 + __max(height(current->leftChild), height(current->rightChild));
}

bool isLeafNode(node *current) {
    return (current->leftChild == NULL && current->rightChild == NULL);
}

int minimumValue(node *tree) {
    if (isLeafNode(tree))
        return tree->value;
    int left = minimumValue(tree->leftChild);
    int right = minimumValue(tree->rightChild);

    return __min(__min(left, right), tree->value);
}

int maximumValue(node *tree) {
    if (isLeafNode(tree))
        return tree->value;
    int left = maximumValue(tree->leftChild);
    int right = maximumValue(tree->rightChild);

    return __max(__max(left, right), tree->value);
}

node *getNode(int key) {
    node *current = root;
    while (current != NULL) {
        if (key < current->value)
            current = current->leftChild;
        else if (key > current->value)
            current = current->rightChild;
        else
            return current;
    }
    return NULL;
}

node *minValueNode(node *current) {
    return getNode(minimumValue(current));
}

bool isBinarySearchTree(node *current, int min, int max) {
    if (current == NULL)
        return true;
    if (current->value < min || current->value > max)
        return false;

    return
        isBinarySearchTree(current->leftChild, min, current->value - 1) &&
        isBinarySearchTree(current->rightChild, current->value + 1, max);
}

void printNodesAtDistance(node *current, int distance) {
    if (current == NULL) {
        return;
    }
    if (distance == 0) {
        printf("%d\t", current->value);
        return;
    }
    printNodesAtDistance(current->leftChild, distance - 1);
    printNodesAtDistance(current->rightChild, distance - 1);
}

void traverseLevelOrderBFS(node *current) {
    for (int i = 0; i <= height(current); ++i) {
        printNodesAtDistance(current, i);
        printf("\n");
    }
}

int countTotalNumberOfNodes(node *current) {
    static int count = 0;

    if (current == NULL)
        return count;
    count++;
    countTotalNumberOfNodes(current->leftChild);
    countTotalNumberOfNodes(current->rightChild);
    return count;
}


node *deleteNode(int item) {
    return deleteNodeDriver(root, item);
}

node *deleteNodeDriver(node *current, int key) {
    if (current == NULL)
        return current;

    if (key < current->value)
        current->leftChild = deleteNodeDriver(current->leftChild, key);
    else if (key > current->value)
        current->rightChild = deleteNodeDriver(current->rightChild, key);
    else {
        // node with only one child or no child.
        if (current->leftChild == NULL) {
            node *temp = current->rightChild;
            free(current);
            return temp;
        } else if (current->rightChild == NULL) {
            node *temp = current->leftChild;
            free(current);
            return temp;
        }

        // node with two children, traverse inorder & get smallest in right sub-tree.
        // copy inorder successor to this node.
        // delete the inorder successor.
        node *temp = minValueNode(current->rightChild);
        current->value = temp->value;
        current->rightChild = deleteNodeDriver(current->rightChild, temp->value);
    }
    return current;
}
