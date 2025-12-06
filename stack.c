#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef Stack {
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *createStack(int capacity);
void destroyStack(Stack *stack);


int main() {
    
    return 0;
}