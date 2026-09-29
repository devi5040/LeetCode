class Solution
{
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>> &grid, int r, int c, int balance)
    {
        if (balance < 0)
            return false;

        int remaining = (m - 1 - r) + (n - 1 - c);
        if (balance > remaining)
            return false;

        if (r == m - 1 && c == n - 1)
            return balance == 0;

        if (dp[r][c][balance] != -1)
            return dp[r][c][balance];

        bool right = false;
        if (c + 1 < n)
        {
            int newBalance = balance +
                             (grid[r][c + 1] == '(' ? 1 : -1);

            right = dfs(grid, r, c + 1, newBalance);
        }

        bool down = false;
        if (r + 1 < m)
        {
            int newBalance = balance +
                             (grid[r + 1][c] == '(' ? 1 : -1);

            down = dfs(grid, r + 1, c, newBalance);
        }

        return dp[r][c][balance] = (right || down);
    }

    bool hasValidPath(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;

        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n, -1)));

        return dfs(grid, 0, 0, 1);
    }
};