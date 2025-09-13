#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[50];
    int age;
    char degree[50];
    struct Date birthday;
};

int main (void) {

    struct Student classroom[3] = {
            {
            "Istvan",
            26,
            "Msc. Comp Sci",
            { 5, 5, 1999}
        },
        {
            "Johan",
            27,
            "Construction Man",
            { 22, 11, 1998 }
        },
        {
            "Rolande",
            21,
            "Bsc. Zoology",
            {14, 05, 2004}
        },
    };

    printf("Student classroom:\n");

    for (int i = 0; i < 3; i++) {
        printf("\tStudent name: %s\n", classroom[i].name);
        printf("\tStudent age: %d\n", classroom[i].age);
        printf("\tStudent degree: %s\n", classroom[i].degree);
        printf("\tStudent birthday: %d/%d/%d\n\n", classroom[i].birthday.day, classroom[i].birthday.month, classroom[i].birthday.year);
    }


    return 0;
}