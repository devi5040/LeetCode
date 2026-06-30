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
    int maxDepth(TreeNode *root)
    {
        int max_depth = 1, depth_l = 1, depth_r = 1;
        if (!root)
            return 0;
        if ((!root->left && !root->right))
            return 1;
        depth_l += maxDepth(root->left);
        depth_r += maxDepth(root->right);
        max_depth = max(depth_l, depth_r);
        return max_depth;
    }
};