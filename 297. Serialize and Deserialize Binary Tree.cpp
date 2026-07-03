/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    void serializeHelper(TreeNode *root, string &res)
    {
        if (!root)
        {
            res += "@,";
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        serializeHelper(root, res);
        return res;
    }

    TreeNode *build(vector<string> &vals, int &i)
    {
        if (vals[i] == "@")
        {
            i++;
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(vals[i]));
        i++;

        root->left = build(vals, i);
        root->right = build(vals, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> vals;
        string temp;
        for (char c : data)
        {
            if (c == ',')
            {
                vals.push_back(temp);
                temp.clear();
            }
            else
                temp += c;
        }
        int i = 0;
        return build(vals, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));