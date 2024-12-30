#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int countLeaves(Node* root) {
    if (root == NULL) {
        return 0; 
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; 
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    int leafCount = countLeaves(root);
    printf("So luong la trong cay: %d\n", leafCount);

    return 0;
}
