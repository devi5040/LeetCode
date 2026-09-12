class Solution
{
public:
    struct State
    {
        long long score;
        vector<int> indices;
    };

    bool better(const State &a, const State &b)
    {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        vector<array<int, 4>> a(n);

        for (int i = 0; i < n; i++)
        {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i};
        }

        sort(a.begin(), a.end());

        vector<int> nxt(n);

        for (int i = 0; i < n; i++)
        {
            int lo = i + 1;
            int hi = n;

            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        vector<vector<State>> dp(
            n + 1,
            vector<State>(5));

        for (int i = n - 1; i >= 0; i--)
        {

            for (int k = 1; k <= 4; k++)
            {

                State skip = dp[i + 1][k];

                State take;
                take.score = a[i][2] + dp[nxt[i]][k - 1].score;

                take.indices = dp[nxt[i]][k - 1].indices;
                take.indices.push_back(a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].indices;
    }
};