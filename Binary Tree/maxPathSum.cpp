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

//maxPathSum in Binary Tree
int maxPathSumUtil(TreeNode *root, int &maxSum) 
{
    if (root == nullptr)
        return 0;

    int leftMax = max(0, maxPathSumUtil(root->left, maxSum));
    int rightMax = max(0, maxPathSumUtil(root->right, maxSum));

    maxSum = max(maxSum, leftMax + rightMax + root->val);

    return max(leftMax, rightMax) + root->val;
}
int maxPathSum(TreeNode *root) 
{
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}


// Optimized version with height calculation
pair<int, int> maxPathSumHelper(TreeNode *root) 
{
    if (root == nullptr)
        return {0, INT_MIN}; // {max path sum from root, max path sum in subtree}

    auto left = maxPathSumHelper(root->left);
    auto right = maxPathSumHelper(root->right);

    int maxFromRoot = max(left.first, right.first) + root->val;
    int currentMax = max(left.second, right.second);
    currentMax = max(currentMax, left.first + right.first + root->val);

    return {max(maxFromRoot, 0), currentMax};
}
int maxPathSum(TreeNode *root) 
{
    return maxPathSumHelper(root).second;
}   


// Optimized version with height calculation and single traversal
int maxPathSum(TreeNode *root) 
{
    if (root == nullptr)
        return 0;

    int maxSum = INT_MIN;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) {
        if (node == nullptr)
            return 0;

        int leftMax = max(0, dfs(node->left));
        int rightMax = max(0, dfs(node->right));

        maxSum = max(maxSum, leftMax + rightMax + node->val);

        return max(leftMax, rightMax) + node->val;
    };

    dfs(root);
    return maxSum;
}