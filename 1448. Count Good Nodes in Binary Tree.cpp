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
    int findGoodNode(TreeNode *root, int parentValue)
    {
        if (!root)
            return 0;
        int count = (root->val >= parentValue) ? 1 : 0;
        int newMax = max(parentValue, root->val);
        count += findGoodNode(root->left, newMax);
        count += findGoodNode(root->right, newMax);
        return count;
    }
    int goodNodes(TreeNode *root)
    {
        return findGoodNode(root, INT_MIN);
    }
};