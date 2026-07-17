class Solution
{
public:
    int m, n;
    bool solve(vector<vector<char>> &board, string &word, int i, int j, int current, vector<vector<bool>> &visited)
    {
        if (current == word.size())
            return true;
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || current == word.size())
            return false;
        if (board[i][j] != word[current] || visited[i][j])
            return false;
        visited[i][j] = true;
        bool found = solve(board, word, i - 1, j, current + 1, visited) || solve(board, word, i + 1, j, current + 1, visited) || solve(board, word, i, j - 1, current + 1, visited) || solve(board, word, i, j + 1, current + 1, visited);
        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (solve(board, word, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }
};