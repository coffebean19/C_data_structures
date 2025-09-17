struct LinkedList {
    struct Node * top;
    struct Node * last;
    struct Node * current;
};

extern struct LinkedList * createList();
extern void addNode(struct LinkedList * self, int value);
extern void returnToListTop(struct LinkedList * self);
extern void nextInList(struct LinkedList * self);
extern void printCurrentNode(struct LinkedList * self);
extern void freeList(struct LinkedList * self);
extern void printEntireList(struct LinkedList * self);