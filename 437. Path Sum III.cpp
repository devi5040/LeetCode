// 2 DFS
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
    void solve(TreeNode *root, long sum, int k, unordered_map<long, int> &prefixCount, int &count)
    {
        if (!root)
            return;

        sum += root->val;

        // If (sum - k) has occurred before, those prefixes mark valid path starts
        // ending at the current node
        if (prefixCount.count(sum - k))
        {
            count += prefixCount[sum - k];
        }

        prefixCount[sum]++; // record this path's running sum

        solve(root->left, sum, k, prefixCount, count);
        solve(root->right, sum, k, prefixCount, count);

        prefixCount[sum]--; // backtrack: remove before returning to parent
        if (prefixCount[sum] == 0)
        {
            prefixCount.erase(sum); // optional cleanup, not required for correctness
        }
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long, int> prefixCount;
        prefixCount[0] = 1; // base case: empty prefix, sum 0, seen once
        int count = 0;
        solve(root, 0, targetSum, prefixCount, count);
        return count;
    }
};

// Prefix sum approach
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
    void solve(TreeNode *root, long sum, int k, unordered_map<long, int> &prefixCount, int &count)
    {
        if (!root)
            return;

        sum += root->val;

        // If (sum - k) has occurred before, those prefixes mark valid path starts
        // ending at the current node
        if (prefixCount.count(sum - k))
        {
            count += prefixCount[sum - k];
        }

        prefixCount[sum]++; // record this path's running sum

        solve(root->left, sum, k, prefixCount, count);
        solve(root->right, sum, k, prefixCount, count);

        prefixCount[sum]--; // backtrack: remove before returning to parent
        if (prefixCount[sum] == 0)
        {
            prefixCount.erase(sum); // optional cleanup, not required for correctness
        }
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long, int> prefixCount;
        prefixCount[0] = 1; // base case: empty prefix, sum 0, seen once
        int count = 0;
        solve(root, 0, targetSum, prefixCount, count);
        return count;
    }
};