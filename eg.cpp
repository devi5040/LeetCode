#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool found_p = false, found_q = false;
    TreeNode *ans = nullptr;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        cout << "The current root is: " << root->val << endl;
        if (root->val == p->val)
            found_p = true;
        if (root->val == q->val)
            found_q = true;
        lowestCommonAncestor(root->left, p, q);
        lowestCommonAncestor(root->right, p, q);
        if (found_p && found_q && !ans)
        {
            cout << "The current root is: " << root->val << endl;
            ans = root;
        }
        return root;
    }
};

// Build tree from level order representation
TreeNode *buildTree(const vector<string> &nodes, unordered_map<int, TreeNode *> &mp)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    mp[root->val] = root;

    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            mp[curr->left->val] = curr->left;
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            mp[curr->right->val] = curr->right;
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main()
{
    vector<string> input = {
        "3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4"};

    unordered_map<int, TreeNode *> nodeMap;

    TreeNode *root = buildTree(input, nodeMap);

    TreeNode *p = nodeMap[5];
    TreeNode *q = nodeMap[4];

    Solution sol;
    TreeNode *ans = sol.lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "Returned Node: " << ans->val << endl;
    else
        cout << "Returned nullptr" << endl;

    return 0;
}