#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node* create(char data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

struct node* insert(char postfix[]) {
    struct node *stack[100];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        if (!isOperator(postfix[i])) {
            struct node *temp = create(postfix[i]);
            stack[++top] = temp;
        } else {
            struct node *temp = create(postfix[i]);
            temp->right = stack[top--];
            temp->left = stack[top--];
            stack[++top] = temp;
        }
    }

    return stack[top--];
}

void main() {
    char postfix[] = "ab+ef*g*-";
    struct node *root = insert(postfix);
    printf("Inorder traversal of expression tree: ");
    inorder(root);
}
