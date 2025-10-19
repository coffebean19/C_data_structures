#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int value) {
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insertNode(struct Node * parent, struct Node * child) {
    if (parent->left == NULL) {
        parent->left = child;
    } else {
        parent->right = child;
    }
}

int main() {
    struct Node * root = createNode(4);
    struct Node * node = createNode(5);
    struct Node * node_two = createNode(6);
    struct Node * node_three = createNode(12);
    struct Node * node_four = createNode(76);
    struct Node * node_five = createNode(2);
    struct Node * node_sixe = createNode(10);

    insertNode(root, node);
    insertNode(root, node_two);
    insertNode(node, node_three);
    insertNode(node, node_four);
    insertNode(node_two, node_five);
    insertNode(node_two, node_sixe);

    printf("       %d\n", root->data);
    printf("   %d      %d\n", root->left->data, root->right->data);
    printf("%d   %d   %d   %d\n", root->left->left->data,root->left->right->data,root->right->left->data,root->right->right->data);

    return 0;
}