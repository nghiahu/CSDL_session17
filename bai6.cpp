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

int countNodesGreaterThanX(Node* root, int X) {
    if (root == NULL) {
        return 0; 
    }
    int count = 0;
    if (root->data > X) {
        count = 1; 
    }
    return count + countNodesGreaterThanX(root->left, X) + countNodesGreaterThanX(root->right, X);
}

int main() {
    Node* root = NULL;
    int n, value, X;
    printf("Nhap so luong nut can chen: ");
    scanf("%d", &n);
    printf("Nhap %d gia tri de chen vao cay:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    int count = countNodesGreaterThanX(root, X);
    printf("So nut co gia tri lon hon %d la: %d\n", X, count);

    return 0;
}
