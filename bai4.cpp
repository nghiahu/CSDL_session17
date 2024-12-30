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

int search(Node* root, int value) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == value) {
        return 1; 
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
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

    int valueToSearch;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &valueToSearch);

    if (search(root, valueToSearch)) {
        printf("Gia tri %d da duoc tim thay trong cay.\n", valueToSearch);
    } else {
        printf("Gia tri %d khong tim thay trong cay.\n", valueToSearch);
    }

    return 0;
}
