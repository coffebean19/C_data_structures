#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


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

// DEPRECATED
// Insert new node in middle of linked list
struct Node * insertNode(struct Node * node, int value) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    
    newNode->next = node->next;
    newNode->data = value;
    node->next = newNode;

    return newNode;
}

// List the entire linked list
// void printLinkedList(struct Node * node) {
//     int nodeNr = 1;
//     struct Node * current = node;
    
//     printf("---Linked list---\n\n");
    
//     while (current != NULL){
//         printf("Node #%d: %d\n", nodeNr++, current->data);
//         current = current->next;
//     }
//     printf("\n--- END ---\n\n");
// }



struct LinkedList * createList() {
    struct LinkedList * list = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    return list;
}

void addNode(struct LinkedList * self, int value) {
    if (self->top == NULL) {
        self->top = createNode(value);
        self->last = self->top;
        self->current = self->top;
    } else {
        if (self->last == self->top) {
            struct Node * nextNode = createNode(value);
            self->last = nextNode;
            self->top->next = nextNode;
        } else {
            struct Node * nextNode = createNode(value);
            struct Node * currentNode = self->last;
            currentNode->next = nextNode;
            self->last = nextNode;
        }
    }
}

void returnToListTop(struct LinkedList * self) {
    self->current = self->top;
}

void nextInList(struct LinkedList * self) {
    if (self->current != self->last) {
        self->current = self->current->next;
    }
}

void printCurrentNode(struct LinkedList * self) {
    printf("Current node: %d\n", self->current->data);
}

void freeList(struct LinkedList * self) {
    // Free allocated memory
    struct Node * current = self->top;
    struct Node * next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void printEntireList(struct LinkedList * self) {
    struct Node * current = self->top;
    int node_i = 1;
    printf("--- START LIST ---\n\n");
    while (current != NULL) {
        printf("Node #%d: %d\n", node_i++, current->data);
        current = current->next;
    }
    printf("\n--- END LIST ---\n");
}

// int main(void) {
//     struct LinkedList * list = createList();
//     addNode(list, 3);
//     addNode(list, 4);

//     printEntireList(list);

//     addNode(list, 21);
//     addNode(list, 1);
//     addNode(list, 7);

//     printCurrentNode(list);
//     nextInList(list);
//     nextInList(list);
//     printCurrentNode(list);

//     addNode(list, 17);
//     printEntireList(list);

//     freeList(list);

//     return 0;
// }