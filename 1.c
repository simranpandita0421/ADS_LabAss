/*You are given a pointer to the root of a binary search tree and values to be inserted into the tree . Insert the values on the appropriate position in binary search tree and return the root of the updated binary tree 
Write a c code on given problem statement/*

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to print the inorder traversal of the binary search tree
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    // Example usage
    TreeNode* root = NULL;

    // Inserting values into the binary search tree
    int values[] = {5, 2, 8, 1, 3, 6, 9};
    int numValues = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < numValues; i++) {
        root = insert(root, values[i]);
    }

    // Printing the inorder traversal of the updated binary search tree
    inorderTraversal(root);

    return 0;
}
