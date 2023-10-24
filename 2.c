/* Write a c code for pre order traversal of threaded binary tree 

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a threaded binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int isThreaded;
} TreeNode;

// Function to create a new threaded binary tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0; // Initially, not threaded
    return newNode;
}

// Function to find the inorder successor of a node in a threaded binary tree
TreeNode* findInorderSuccessor(TreeNode* node) {
    if (node == NULL) return NULL;
    if (node->isThreaded) return node->right;
    return findInorderSuccessor(node->right);
}

// Function to perform a pre-order traversal of a threaded binary tree
void preOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->data);

    // Traverse left subtree
    preOrderTraversal(root->left);

    // Traverse right subtree
    if (!root->isThreaded) {
        preOrderTraversal(root->right);
    }
}

int main() {
    // Example usage
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Creating threads
    root->left->right = root;
    root->left->isThreaded = 1;
    root->right->left = root;
    root->right->isThreaded = 1;

    // Performing pre-order traversal
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}
