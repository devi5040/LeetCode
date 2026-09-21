class Solution
{
public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        vector<long long> ans(k, 0);

        vector<long long> dp(k);

        for (int num : nums)
        {
            vector<long long> newDp(k);
            int x = num % k;

            newDp[x]++;

            for (int r = 0; r < k; r++)
            {
                int newR = (r * x) % k;
                newDp[newR] += dp[r];
            }

            for (int i = 0; i < k; i++)
                ans[i] += newDp[i];

            dp = newDp;
        }

        return ans;
    }
};