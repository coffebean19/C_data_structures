#include <stdio.h>
#include "linkedlist.h"

int main() {
    struct LinkedList * list = createList();

    addNode(list, 35);
    addNode(list, 12);
    addNode(list, 26);

    printEntireList(list);

    freeList(list);

    return 0;
}