class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }

        if (fresh == 0)
            return 0;

        int minutes = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int sz = q.size();
            bool rottedThisRound = false;

            for (int k = 0; k < sz; k++)
            {
                auto [i, j] = q.front();
                q.pop();
                for (auto &d : dirs)
                {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != 1)
                        continue;
                    grid[ni][nj] = 2;
                    fresh--;
                    rottedThisRound = true;
                    q.push({ni, nj});
                }
            }
            if (rottedThisRound)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};