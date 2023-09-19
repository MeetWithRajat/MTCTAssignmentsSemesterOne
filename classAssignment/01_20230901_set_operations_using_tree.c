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

struct Node* createSet(char *setName, struct Node *root){
    // this function will create a set for n elements
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

void traverse(struct Node *node){
    // this function will do in-order traversal recursively
    if (node != NULL){
        traverse(node -> left);
        printf("%d ", node -> data);
        traverse(node -> right);
    }
}

struct Node unionOfTwoSets(struct Node *root1, struct Node *root2){
    struct Node *unionRoot = NULL;
    

}

int main(){
    
    struct Node *set1Root = NULL, *set2Root = NULL, *unionRoot = NULL, *intersectionRoot = NULL;

    set1Root = createSet("first", set1Root);  // creating first set

    set2Root = createSet("second", set2Root);  // creating second set
    
    printf("\nThe first set is:\n");
    traverse(set1Root);
    printf("\nThe second set is:\n");
    traverse(set2Root);
    
    return 0;
}
