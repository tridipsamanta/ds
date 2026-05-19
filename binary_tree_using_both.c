#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 50 
 
//------ Binary Tree Node -----
struct node { 
    int data; 
    struct node *left, *right; 
}; 
 
//----- Stack for Iterative Traversal -----  
struct node* stack[MAX]; 
int top = -1; 
 
void push(struct node* n) { 
    stack[++top] = n; 
} 
struct node* pop() { 
    return stack[top--]; 
} 
int isEmpty() { 
    return top == -1; 
}

//----- Create Node -----  
struct node* createNode(int data) { 
    struct node* newNode ;
    newNode= (struct node*)malloc(sizeof(struct node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
//----- Recursive Traversals ------  
void inorder(struct node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
 
void preorder(struct node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
 
void postorder(struct node* root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
//----- Iterative Inorder -----  
void inorderIterative(struct node* root) { 
    struct node* curr = root; 
    while (curr != NULL || !isEmpty()) { 
        while (curr != NULL) { 
            push(curr); 
            curr = curr->left; 
        } 
        curr = pop(); 
        printf("%d ", curr->data); 
        curr = curr->right; 
    } 
} 

//----- Iterative Preorder ---  
void preorderIterative(struct node* root) { 
    if (root == NULL) return; 
    push(root); 
    while (!isEmpty()) { 
        struct node* curr = pop(); 
        printf("%d ", curr->data); 
        if (curr->right) push(curr->right); 
        if (curr->left) push(curr->left); 
    } 
} 
 
//--Iterative Postorder (Two Stacks) -- 
void postorderIterative(struct node* root) { 
    if (root == NULL) return; 
 
    struct node* s1[MAX]; 
    struct node* s2[MAX]; 
    int t1 = -1, t2 = -1; 
 
    s1[++t1] = root; 
 
    while (t1 != -1) { 
        struct node* curr = s1[t1--]; 
        s2[++t2] = curr; 
 
        if (curr->left) s1[++t1] = curr->left; 
        if (curr->right) s1[++t1] = curr->right; 
    } 
 
    while (t2 != -1) { 
        printf("%d ", s2[t2--]->data); 
    } 
} 
 
//----- Main Function ----- 
int main() { 
    struct node* root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->left->right = createNode(5); 
    printf("Recursive Inorder: "); 
    inorder(root); 
    printf("\nRecursive Preorder: "); 
    preorder(root);
    printf("\nRecursive Postorder: "); 
    postorder(root); 
 
    printf("\n\nIterative Inorder: "); 
    inorderIterative(root); 
 
    printf("\nIterative Preorder: "); 
    preorderIterative(root); 
 
    printf("\nIterative Postorder: "); 
    postorderIterative(root); 
 
    return 0; 
}