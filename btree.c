#include <stdio.h>
#include <stdlib.h>

/*
    Great resource on b-trees
    https://thelinuxcode.com/binary-tree-c/
*/ 

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int value) {
    struct Node * newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

// My original insertNode functions
void insertNode(struct Node * parent, struct Node * child) {
    if (parent->left == NULL) {
        parent->left = child;
    } 
    else {
        parent->right = child;
    }
}

// A recursive insert given by Linux Code. Pretty neat.
void recursiveInsert(struct Node * root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return;
    }

    if (value <= root->data) {
        recursiveInsert(root->left, value);
    } 
    else {
        recursiveInsert(root->right, value);
    } 
}

void printInOrder(struct Node* root) {

  if (root == NULL) return;

  // left subtree
  printInOrder(root->left);     

  // root 
  printf("%d ", root->data);   

  // right subtree 
  printInOrder(root->right);  
}

int main() {
    struct Node * root = NULL;
    recursiveInsert(root, 1);
    recursiveInsert(root, 2);
    recursiveInsert(root, 3);
    recursiveInsert(root, 1);
    recursiveInsert(root, 5);
    recursiveInsert(root, 8);
    recursiveInsert(root, 4);


    printInOrder(root);
    // printf("%d\n", root->data);
    return 0;
}