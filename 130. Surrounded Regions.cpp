class Solution
{
public:
    int m, n;
    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1)
            return;
        if (board[i][j] == 'X' || visited[i][j])
            return;
        visited[i][j] = true;
        dfs(board, i - 1, j, visited);
        dfs(board, i + 1, j, visited);
        dfs(board, i, j - 1, visited);
        dfs(board, i, j + 1, visited);
    }
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0, visited);
            dfs(board, i, n - 1, visited);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(board, 0, j, visited);
            dfs(board, m - 1, j, visited);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
    }
};