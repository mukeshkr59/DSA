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

// Pre ordered Traversal
vector<int> ans;
void sol(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    ans.push_back(root->val);
    sol(root->left);
    sol(root->right);
}
vector<int> preorderTraversal(TreeNode *root)
{
    sol(root);
    return ans;
}

// postorder Traversal
vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);

    vector<int> ans;
    if (root == nullptr)
        return ans;
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        if (node->left)
        {
            st.push(node->left);
        }
        if (node->right)
        {
            st.push(node->right);
        }
        ans.push_back(node->val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// postorder Traversal
vector<int> ans;
void sol(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    sol(root->left);
    sol(root->right);
    ans.push_back(root->val);
}
vector<int> inorderTraversal(TreeNode *root)
{
    sol(root);
    return ans;
}

// Inorder Traversal
vector<int> ans;
void sol(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    sol(root->left);
    ans.push_back(root->val);
    sol(root->right);
}
vector<int> inorderTraversal(TreeNode *root)
{
    sol(root);
    return ans;
}

// Level Order Traversal
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> ans;
    vector<int> lev;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            ans.push_back(lev);
            lev.clear();
            if (q.empty())
                break;
            q.push(NULL);
        }
        else
        {
            lev.push_back(temp->val);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}