#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void InitializeStack(struct Stack * stack) {
    stack->top = -1;
}

int isFull(struct Stack * stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack * stack) {
    return stack->top == -1;
}

void push(struct Stack * stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full.\n");
        return;
    }
    stack->items[++stack->top] = value;
    printf("%d pushed to stack.\n", value);
}

int pop(struct Stack * stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[--stack->top];
}

int peek(struct Stack * stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top];
}

void display(struct Stack * stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    for (int i = 0; i <= stack->top; i++) {
        printf("%d  ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    InitializeStack(&stack);
    push(&stack, 6);
    push(&stack, 2);
    push(&stack, 9);
    push(&stack, 12);

    display(&stack);

    printf("Peek: %d\n", peek(&stack));

    push(&stack, 20);

    printf("Peek: %d\n", peek(&stack));

    push(&stack, 210);

    display(&stack);

    return 0;
}