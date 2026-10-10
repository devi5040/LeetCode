#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int count = 0;

    int average(TreeNode *root)
    {
        if (!root)
            return 0;

        cout << root->val << endl;

        if (!root->left && !root->right)
        {
            count++;
            return root->val;
        }

        int num = 1;

        int left = average(root->left);
        int right = average(root->right);
        cout << "For root->val: " << root->val << ", left: " << left << ", right: " << right << endl;
        if (left != 0)
            num++;
        if (right != 0)
            num++;

        int result = (root->val + left + right) / num;
        cout << "The result is: " << result << endl;

        if (result == root->val)
            count++;

        return result;
    }

    int averageOfSubtree(TreeNode *root)
    {
        average(root);
        return count;
    }
};

int main()
{
    /*
             4
            / \
           8   5
          / \   \
         0   1   6

        Expected output: 5
    */

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(3);

    Solution solution;

    cout << "Number of nodes matching subtree average: "
         << solution.averageOfSubtree(root) << endl;

    return 0;
}