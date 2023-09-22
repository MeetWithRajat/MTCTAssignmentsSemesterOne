#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* left;//pointer to left node
 struct node* right;//pointer to right node
};
void CreateBST(struct node**root,int data){

  struct node* node=(struct node*)malloc(sizeof(struct node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
  struct node* temp=*root;//pointer is used to traverse the tree
  /*Create head if first node*/
  if(*root==NULL){
  	*root=node;
	  return;
  }
  if(data<temp->data){
  	CreateBST(&(temp->left),data);//given data is lesser than root then traverse left child
  }
else if(data>temp->data){
	CreateBST(&(temp->right),data);//given data is greater than root then traverse right child
}

}
void traverse(struct node* root){
	if(root!=NULL){                //post order traversal to print the tree
		traverse(root->left);
		traverse(root->right);
		printf("%d\n",root->data);
	}
}

void traverse2(struct node* root4, struct node** unionroot){
	if(root4!=NULL){                
		traverse2(root4->left, unionroot);
		traverse2(root4->right, unionroot);
		CreateBST(&*unionroot,root4->data);
	}
}
struct node* Union(struct node* root3,struct node* root4){
 	struct node* unionroot=NULL;
	traverse2(root3, &unionroot);
	traverse2(root4, &unionroot);
    return unionroot;

}
/*void Intersection(struct node root,struct node* root1){

}*/
int main(){
 struct node* root=NULL;
 int n,i,data;
 printf("Enter the number of elements for set 1:");
 scanf("%d",&n);
 for(i=0;i<n;i++){
 	scanf("%d",&data);
 	
 	CreateBST(&root,data);
 }
 printf("\nset1\n");
 traverse(root);//pass the root pointer to traverse the tree
 struct node* root2=NULL;

 printf("Enter the number of elements for set 2:");
 scanf("%d",&n);
 for(i=0;i<n;i++){
 	scanf("%d",&data);
 	
 	CreateBST(&root2,data);
 }
 printf("\nset2\n");
 traverse(root2);//pass the root pointer to traverse the tree
struct node* unionroot=NULL;
unionroot = Union(root,root2);
printf("\nUnion\n");
traverse(unionroot);

 return 0;
}