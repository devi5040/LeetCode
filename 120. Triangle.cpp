class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));

        for (int i = 0; i < m; i++)
            dp[m - 1][i] = triangle[m - 1][i];

        for (int i = m - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);

        return dp[0][0];
    }
};