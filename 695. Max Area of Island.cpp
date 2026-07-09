class Solution
{
public:
    int max_area = 0;
    int m = 0, n = 0;
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] != 1)
            return 0;
        grid[i][j] = -1;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 1)
                    continue;
                count = dfs(grid, i, j);
                max_area = max(max_area, count);
            }

        return max_area;
    }
};