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
    int max_value = INT_MIN;
    int findRootSum(TreeNode *root)
    {
        int left = 0, right = 0;
        if (!root)
            return 0;
        left = max(findRootSum(root->left), 0);
        right = max(findRootSum(root->right), 0);
        max_value = max(max_value, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        findRootSum(root);
        return max_value;
    }
};