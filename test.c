#include <stdio.h>
#include <stdlib.h>

// void printPointerExample();
// void addTwo(int value);
// void addTwoP(int* value);

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value) {
    Node* result = malloc(sizeof(Node));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }

    return result;
}

void printTabs(int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
}

void printTreeRec(Node *root, int level) {
    if (root == NULL) {
        printTabs(level);
        printf("---<empty>---\n");
        return;
    }
    printTabs(level);
    printf("value = %d\n", root->value);
    
    printTabs(level);
    printf("left\n");
    printTreeRec(root->left, level+1);
    
    printTabs(level);
    printf("right\n");
    printTreeRec(root->right, level+1);

}

void printTree(Node *root) {
    printTreeRec(root, 0);
    printf("Done.\n");
}

void recursiveInsert(Node **root, int value) {
    if (value < (*root)->value && (*root)->left == NULL) {
        (*root)->left = createNode(value);
        printf("Left\n");
    } else if ((*root)->right == NULL) {
        (*root)->right = createNode(value);
        printf("Right\n");
    } else {
        printf("Move.\n");
        if (value < (*root)->value) {
            recursiveInsert(&(*root)->left, value);
        } else {
            recursiveInsert(&(*root)->right, value);
        }
    }
}

void freeTree(Node **root) {



    if (&(*root) == NULL) {
        printf("Empty\n");
        return;
    }
    if ((*root)->left == NULL) {
        return;
        // (*root)->left = createNode(value);
        // printf("Left\n");
    } else if ((*root)->right == NULL) {
        return;
        // (*root)->right = createNode(value);
        // printf("Right\n");
    } else {
        if ((*root)->left != NULL) {
            freeTree(&(*root)->left);
            free((*root)->left);
        } else if ((*root)-> right != NULL) {
            freeTree(&(*root)->right);
            free((*root)->right);
        }
    }
    printf("Memory cleared.\n");
}

int main() {
    Node *node1 = createNode(2);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(5);
    Node *node5 = createNode(6);
    Node *node6 = createNode(6);
    Node *node7 = createNode(6);

    Node **temp_node = &node1;
    // printf("Node1: %d\n", ((*temp_node)->value));
    (*temp_node)->left = node2;

    // node1->left = node2;
    node1->right = node3;
    node2->left = node6;
    node2->right = node7;
    node3->left = node4;
    node3->right = node5;

    recursiveInsert(temp_node, 12);
    recursiveInsert(temp_node, 4);
    recursiveInsert(temp_node, 7);
    recursiveInsert(temp_node, 1);
    printTree(node1);

    // free(node1);
    // free(node2);
    // free(node3);
    // free(node4);
    // free(node5);
    // freeTree(&node1);
    // printTree(node1);
    return 0;
}
