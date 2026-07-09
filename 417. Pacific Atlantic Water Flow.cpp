class Solution
{
public:
    int m, n;
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j, int preHeight)
    {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1)
            return;
        if (visited[i][j])
            return;
        if (heights[i][j] < preHeight)
            return;
        visited[i][j] = true;
        dfs(heights, visited, i - 1, j, heights[i][j]);
        dfs(heights, visited, i + 1, j, heights[i][j]);
        dfs(heights, visited, i, j - 1, heights[i][j]);
        dfs(heights, visited, i, j + 1, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j, heights[0][j]);
        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0, heights[i][0]);
        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j, heights[m - 1][j]);
        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
        return result;
    }
};