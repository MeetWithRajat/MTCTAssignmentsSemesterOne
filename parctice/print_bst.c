#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the BST in the desired format
void printBST(struct Node* root, int space) {
    if (root == NULL)
        return;

    // Increase the indentation for the right child
    space += 2;

    // Recursively print the right child
    printBST(root->right, space);

    // Print current node with proper indentation
    for (int i = 2; i < space; i++)
        printf(" ");
    printf("|-%d\n", root->data);

    // Recursively print the left child
    printBST(root->left, space);
}
void treePrint(struct Node *root, int level)
{
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
            printf(i == level - 1 ? "|-" : "  ");
        printf("%d\n", root->data);
        treePrint(root->left, level + 1);
        treePrint(root->right, level + 1);
}

// Function to print the tree in the desired format
void printTree(struct Node* root, int depth) {
    if (root == NULL)
        return;

    // Print proper indentation
    for (int i = 0; i < depth; i++)
        printf("|   ");

    // Print the node's name
    printf("|-- %d\n", root->data);

    // Recursively print the right and left subtrees with increased depth
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(9);
    root->left->left->right = createNode(2);

    printf("Binary Search Tree in the desired format:\n\n");
    printBST(root, 0);
    printf("\n");
    treePrint(root, 0);
    printf("\n");
    printTree(root, 0);

    return 0;
}
