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
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int dl = 1, dr = 1;
        dl += depth(root->left);
        dr += depth(root->right);

        return max(dl, dr);
    }

    bool isBalanced(TreeNode *root)
    {
        int dl = 1, dr = 1;
        if (!root || (!root->left && !root->right))
            return true;
        dl += depth(root->left);
        dr += depth(root->right);
        return (abs(dl - dr) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};