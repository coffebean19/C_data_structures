#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

// Create a new node
struct Node * createNode(int value) {
    // Allocate space in memory using malloc, with the size of a struct Node, and explicitely cast to struct Node *.
    // Assign pointer to the allocated space.
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}

// List the entire linked list
void printLinkedList(struct Node * node) {
    int nodeNr = 1;
    struct Node * current = node;
    
    printf("---Linked list---\n\n");
    
    while (current != NULL){
        printf("Node #%d: %d\n", nodeNr++, current->data);
        current = current->next;
    }
    printf("\n--- END ---\n\n");
}

int main(void) {
    struct Node * top = createNode(3);
    struct Node * second = createNode(9);
    struct Node * third = createNode(21);
    struct Node * fourth = createNode(7);
    struct Node * fifth = createNode(17);

    top->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    printLinkedList(top);

    return 0;
}