#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value < (*root)->data) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

int height(Node* root) {
    if (root == NULL) {
        return -1; 
    } else {
        int leftHeight = height(root->left); 
        int rightHeight = height(root->right); 

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri can chen vao cay:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&root, value);
    }

    int treeHeight = height(root);
    printf("Chieu cao cua cay nhi phan la: %d\n", treeHeight);

    return 0;
}
