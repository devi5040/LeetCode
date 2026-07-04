struct TrieNode
{
    TrieNode *children[26] = {};
    bool isEnd = false;
    string word;
};

class Solution
{
public:
    vector<string> result;

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node)
    {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return;
        char ch = board[r][c];
        if (ch == '#')
            return;

        int i = ch - 'a';

        if (!node->children[i])
            return; // No word has this prefix

        TrieNode *next = node->children[i];
        if (next->isEnd)
        {
            result.push_back(next->word);
            next->isEnd = false; // prevents duplicate
        }

        board[r][c] = '#'; // mark visited
        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);
        board[r][c] = ch; // backtrack restore the cell;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (string word : words)
        {
            TrieNode *node = root;
            for (char ch : word)
            {
                int i = ch - 'a';
                if (!node->children[i])
                    node->children[i] = new TrieNode();
                node = node->children[i];
            }
            node->isEnd = true;
            node->word = word;
        }
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                dfs(board, r, c, root);

        return result;
    }
};