#include <stdio.h>

void addTwo(int a);
void addTwoP(int* a);
void addTwoPD(int* a);

int main() {
    int number = 2;
    int* pointer_to_number = &number;

    addTwo(number);
    printf("%d\n", number);
    addTwoP(pointer_to_number);
    printf("%d\n", number);
    addTwoPD(pointer_to_number);
    printf("%d\n", number);


    return 0;
}

void addTwo(int a) {
    a += 2;
}

void addTwoP(int* a) {
    a += 2;
}

void addTwoPD(int* a) {
    *a += 2;
}