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

// minimum time to burn binary tree from a given node
int minTimeToBurn(TreeNode *root, int target, int &time)
{
    if (root == nullptr)
        return -1; // Base case: if the node is null, return -1

    if (root->val == target)
    {             // If the current node is the target
        time = 0; // Reset time to 0
        return 1; // Return 1 to indicate the target node is found
    }

    int leftTime = minTimeToBurn(root->left, target, time);   // Search in the left subtree
    int rightTime = minTimeToBurn(root->right, target, time); // Search in the right subtree

    if (leftTime != -1)
    {                               // If the target was found in the left subtree
        time = max(time, leftTime); // Update time with the maximum time from left subtree
        time++;                     // Increment time for burning this node
        return leftTime + 1;        // Return the distance from this node to the target
    }

    if (rightTime != -1)
    {                                // If the target was found in the right subtree
        time = max(time, rightTime); // Update time with the maximum time from right subtree
        time++;                      // Increment time for burning this node
        return rightTime + 1;        // Return the distance from this node to the target
    }

    return -1; // If the target was not found in either subtree, return -1
}

int minTimeToBurn(TreeNode *root, int target)
{
    int time = -1;                     // Initialize time to -1
    minTimeToBurn(root, target, time); // Call the helper function
    return time;                       // Return the total time taken to burn the tree from the target node
}
       