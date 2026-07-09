class Solution
{
public:
    void markIslands(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1 || grid[i][j] != '1')
            return;
        grid[i][j] = '#';
        markIslands(grid, i - 1, j, m, n);
        markIslands(grid, i + 1, j, m, n);
        markIslands(grid, i, j - 1, m, n);
        markIslands(grid, i, j + 1, m, n);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '#' || grid[i][j] == '0')
                    continue;
                markIslands(grid, i, j, m, n);
                count++;
            }
        }
        return count;
    }
};