/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root || !root->left && !root->right)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *dummy = root->right, *cur;
        if (root->left)
        {
            root->right = root->left;
            root->left = nullptr;
            cur = root->right;
            while (cur->right)
                cur = cur->right;
            cur->right = dummy;
        }
    }
};