#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};

void insert(struct Node **node, int data){
    // this function will insert the element for a BST
    if (*node != NULL){
        if (data > (*node) -> data)
            insert(&((*node)->right), data);
        else if (data < (*node) -> data)
            insert(&((*node) -> left), data);
    }
    else{
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
        newNode -> data = data;
        newNode -> left = NULL;
        newNode -> right = NULL;
        *node = newNode;
    }
}

void traverse(struct Node *root){
    // this function will do in-order traversal recursively
    if (root != NULL){
        traverse(root -> left);
        printf("%d ", root -> data);
        traverse(root -> right);
    }
}

struct Node* createSet(char *setName, struct Node *root){
    int n, data;
    printf("\nCreate %s set\nEnter the size of the %s set: ", setName, setName);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter the %d no value: ", i + 1);
        scanf("%d", &data);
        insert(&root, data);
    }
    printf("Set created!\n");
    return root;
}

int main(){
    
    struct Node *set1_root = NULL, *set2_root = NULL;

    set1_root = createSet("first", set1_root);  // creating first set
    printf("\nThe first set is:\n");
    traverse(set1_root);

    set1_root = createSet("second", set2_root);  // creating second set
    printf("\nThe second set is:\n");
    traverse(set2_root);
    
    return 0;
}
