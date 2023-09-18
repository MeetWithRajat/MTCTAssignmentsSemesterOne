#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *set1_root = NULL, *set2_root = NULL;

void createSet(struct Node *root, int data){
    if (root != NULL){
        if (data > root -> data)
            createSet(root->right, data);
        else if (data < root -> data)
            createSet(root -> left, data);
    }
    else{
        struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
        node -> data = data;
        node -> left = NULL;
        node -> right = NULL;
        root = node;
        if (set1_root == NULL)
            set1_root = root;
    }
}

void traverse(struct Node *root){
    if (root != NULL){
        traverse(root -> left);
        printf("%d ", root -> data);
        traverse(root -> right);
    }
}

int main(){
    int n, data;
    struct Node *ptr;
    printf("\nEnter the size of the set1: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Enter the %d no value: ", i + 1);
        scanf("%d", &data);
        ptr = set1_root;
        createSet(ptr, data);
    }
    printf("\nThe set 1 is:\n");
    traverse(set1_root);
    return 0;
}
