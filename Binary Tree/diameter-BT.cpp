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

//diameter of Binary Tree
int diameterOfBinaryTree(TreeNode *root)    
{
    if (root == nullptr)
        return 0;

    int leftHeight = diameterOfBinaryTree(root->left);
    int rightHeight = diameterOfBinaryTree(root->right);

    int currentDiameter = leftHeight + rightHeight + 1;

    return max(currentDiameter, max(leftHeight, rightHeight));
}   
// Optimized version
int diameter = 0;           
int dfs(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = dfs(root->left);
    int rightHeight = dfs(root->right);

    diameter = max(diameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    dfs(root);
    return diameter;
}


// Optimized version with height calculation
pair<int, int> diameterHelper(TreeNode *root)   
{
    if (root == nullptr)
        return {0, 0}; // {height, diameter}

    auto left = diameterHelper(root->left);
    auto right = diameterHelper(root->right);

    int height = max(left.first, right.first) + 1;
    int currentDiameter = left.first + right.first;

    return {height, max(currentDiameter, max(left.second, right.second))};
}
int diameterOfBinaryTree(TreeNode *root)
{
    return diameterHelper(root).second;
}


// Optimized version with height calculation and diameter
int diameterOfBinaryTree(TreeNode *root)    
{
    if (root == nullptr)
        return 0;

    int leftHeight = diameterOfBinaryTree(root->left);
    int rightHeight = diameterOfBinaryTree(root->right);

    int currentDiameter = leftHeight + rightHeight + 1;

    return max(currentDiameter, max(leftHeight, rightHeight));
}

// Optimized version with height calculation and diameter
pair<int, int> diameterHelper(TreeNode *root)   
{
    if (root == nullptr)
        return {0, 0}; // {height, diameter}

    auto left = diameterHelper(root->left);
    auto right = diameterHelper(root->right);

    int height = max(left.first, right.first) + 1;
    int currentDiameter = left.first + right.first;

    return {height, max(currentDiameter, max(left.second, right.second))};
}