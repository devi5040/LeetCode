#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    void printTree(TreeNode *root, int level = 0)
    {
        if (root == nullptr)
            return;

        // Print right subtree first
        printTree(root->right, level + 1);

        // Print current node
        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << root->val << endl;

        // Print left subtree
        printTree(root->left, level + 1);
    }
    string res = "";
    string serialize(TreeNode *root)
    {
        if (!root)
            return res += "#@";
        res += "#" + to_string(root->val);
        serialize(root->left);
        serialize(root->right);
        return res;
    }
};

int main()
{
    // [3,9,20,null,null,15,7]

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    // root->left->left = new TreeNode(5);
    // root->left->right = new TreeNode(19);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;

    string result = sol.serialize(root);
    cout << result << endl;
    // cout << "Max Depth: " << sol.isBalanced(root) << endl;

    return 0;
}