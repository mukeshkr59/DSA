#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// brute force approach
int countNodes(TreeNode *root){
    if(root == nullptr)
        return 0; // Base case: if the node is null, return 0
    return 1 + countNodes(root->left) + countNodes(root->right); // Count the current node and recursively count left and right subtrees    
}



// Function to count the number of nodes in a complete binary tree
int countNodes(TreeNode *root)  {
    if (root == nullptr)
        return 0; // Base case: if the node is null, return 0

    int leftHeight = 0;  // Height of the left subtree
    int rightHeight = 0; // Height of the right subtree

    TreeNode *leftNode = root;
    TreeNode *rightNode = root;

    // Calculate the height of the leftmost path
    while (leftNode) {
        leftHeight++;
        leftNode = leftNode->left;
    }

    // Calculate the height of the rightmost path
    while (rightNode) {
        rightHeight++;
        rightNode = rightNode->right;
    }

    // If the heights are equal, it's a perfect binary tree
    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1; // Number of nodes in a perfect binary tree
    }

    // If not, recursively count nodes in left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    // Example usage:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes in the complete binary tree: " << countNodes(root) << endl;

    return 0;
}