#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;  
  struct node *left;
  struct node *right;
};

// Function prototypes 
struct node* createNode(int value);  
void recursiveInsert(struct  node* root, int value);
void printInOrder(struct node* root);

int main() {

  struct node* root = NULL; // empty tree

  // insert nodes 
  recursiveInsert(root, 15); 
  recursiveInsert(root, 10);
  recursiveInsert(root, 8); 

  // print 
  printf("In order traversal: ");
  printInOrder(root);

  return 0;  
}

void printInOrder(struct node* root) {

  if (root == NULL) return;

  // left subtree
  printInOrder(root->left);     

  // root 
  printf("%d ", root->data);   

  // right subtree 
  printInOrder(root->right);  
}

void recursiveInsert(struct node* root, int value) {

  // base case  
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

struct node* createNode(int value) {

  struct node* newNode = malloc(sizeof(struct node));

  newNode->data = value; 
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode; 
}