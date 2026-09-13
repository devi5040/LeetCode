class Solution
{
public:
    int minDays(int n)
    {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == INT_MAX)
                continue;

            for (int k = 1;; k++)
            {
                int points = k * (k + 1) / 2;

                if (i + points > n)
                    break;

                dp[i + points] = min(dp[i + points], dp[i] + k + 1);
            }
        }

        return dp[n] - 1;
    }
};