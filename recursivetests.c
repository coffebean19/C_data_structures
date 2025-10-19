#include <stdio.h>

int addTillTen(int value) {
    if (value == 10) { 
        printf("%d\n", value);
        return value;
    } else {
        addTillTen(++value);
    }
}

int main() {
    int number = 1;

    addTillTen(number);

    return 0;
}