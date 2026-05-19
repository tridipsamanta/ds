#include <stdio.h> 
#include <stdlib.h> 
struct node { 
    int data; 
    struct node *left, *right; 
    int height; 
}; 
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
int height(struct node *n) { 
    return (n == NULL) ? 0 : n->height; 
} 
struct node* createNode(int data) { 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    node->height = 1; 
    return node; 
} 
struct node* rightRotate(struct node* y) { 
    struct node* x = y->left; 
    struct node* T2 = x->right; 
 
    x->right = y; 
    y->left = T2; 
    y->height = max(height(y->left), height(y->right)) + 1; 
    x->height = max(height(x->left), height(x->right)) + 1; 
 
    return x; 
} 
struct node* leftRotate(struct node* x)
{ 
    struct node* y = x->right; 
    struct node* T2 = y->left;
      y->left = x; 
    x->right = T2; 
 
    x->height = max(height(x->left), height(x->right)) + 1; 
    y->height = max(height(y->left), height(y->right)) + 1; 
 
    return y; 
} 
int getBalance(struct node* n)
{ 
    return (n == NULL) ? 0 : height(n->left) - height(n->right); 
} 
struct node* insert(struct node* node, int data)
{ 
    if (node == NULL) 
        return createNode(data); 
 
    if (data < node->data) 
        node->left = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 
    else 
        return node; 
 
    node->height = 1 + max(height(node->left), height(node->right)); 
    int balance = getBalance(node); 
    if (balance > 1 && data < node->left->data) 
        return rightRotate(node); 
 
    if (balance < -1 && data > node->right->data) 
        return leftRotate(node); 
 
    if (balance > 1 && data > node->left->data) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 
 
    if (balance < -1 && data < node->right->data) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
 
    return node; 
} 
struct node* minValueNode(struct node* node)
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current;
} 
struct node* deleteNode(struct node* root, int data)
{ 
    if (root == NULL) 
        return root; 
 
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
    else { 
        if ((root->left == NULL) || (root->right == NULL)) { 
            struct node* temp = root->left ? root->left : root->right; 
 
            if (temp == NULL) { 
                temp = root; 
                root = NULL; 
            } else 
                *root = *temp; 
 
            free(temp); 
        } else { 
            struct node* temp = minValueNode(root->right); 
            root->data = temp->data; 
            root->right = deleteNode(root->right, temp->data); 
        } 
    } 
 
    if (root == NULL) 
        return root; 
 
    root->height = 1 + max(height(root->left), height(root->right)); 
    int balance = getBalance(root); 
 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
 
    if (balance > 1 && getBalance(root->left) < 0) { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
 
    if (balance < -1 && getBalance(root->right) > 0) { 
        root->right = rightRotate(root->right); 
        return leftRotate(root);
         } 
 
    return root; 
} 
void inorder(struct node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
int main() { 
    struct node* root = NULL; 
 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 10); 
 
    printf("Inorder traversal after insertion:\n"); 
    inorder(root); 
 
    root = deleteNode(root, 20); 
 
    printf("\nInorder traversal after deletion:\n"); 
    inorder(root); 
 
    return 0; 
}