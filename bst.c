#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
int findHeight(struct node* root)
{
    int lefth, righth;
    if(root == NULL)
        return -1;
    lefth = findHeight(root->left);
    righth = findHeight(root->right);
    return (lefth > righth ? lefth : righth)+1;
}
struct node* insert(struct node* root,int data){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}

void preorder(struct node* tree){
    if(tree==NULL)
        return;
    printf("%d\t",tree->data);
    preorder(tree->left);
    preorder(tree->right);
}
void inorder(struct node *tree){
    if (tree == NULL)
        return;
    inorder(tree->left);
    printf("%d\t", tree->data);
    inorder(tree->right);   
}
void postorder(struct node *tree){
    if (tree == NULL)
       return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d\t",tree->data);
}
struct node* min(struct node* root)
{
    if(root == NULL)
    	return NULL;
    else if(root->left == NULL)
    	return root;
    else
    	return min(root->left);
}
struct node* delete(struct node* root, int x)
{
    struct node* temp;
    if(root == NULL)
        return NULL;
    else if(x < root->data)
        root->left = delete(root->left, x);
    else if(x > root->data)
        root->right = delete(root->right, x);
    else if(root->left && root->right)
    {
        temp = min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, root->data);
    }
    else
    {
        temp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        printf("Deleted item is:%d",temp->data);
        free(temp);
    }
    return root;
}
void main(){
    struct node* tree=NULL;
    int c,data,item;
    tree=insert(tree,20);
    tree=insert(tree,10);
    tree=insert(tree,30);
    tree=insert(tree,40);
    printf("%d",findHeight(tree));
   /* printf("\n..............................\n");
    printf("1.Insert Elements\n2.Preorder Sequence\n3.Inorder Sequence\n4.Postorder sequence\n5.Delete\n6.Exit");
    printf("\n................................\n");
    do{
        printf("\nEnter a choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("\nEnter element to be inserted in the tree: ");
                scanf("%d",&data);
                tree=insert(tree,data);
                break;
            case 2:
                printf("\nThe preorder sequence is:\n");
                preorder(tree);
                break;
            case 3:
                printf("\nThe inorder sequence is:\n");
                inorder(tree);
                break;
            case 4:
                printf("\nThe postorder sequence is:\n");
                postorder(tree);
                break;
            case 5:
                printf("Enter the item to be deleted: ");
                scanf("%d",&item);
                delete(tree,item);
                break;
            case 6:
                printf("\nExiting\n");
                break;
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }while(c!=6);*/
    
}