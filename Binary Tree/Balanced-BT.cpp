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

// Balanced Binary Tree

//method 1 
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}



// method 2
int dfsHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
        return -1;
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}