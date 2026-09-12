class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        int n = freq.size();
        vector<int> dp(n);
        vector<int> keys;

        for (auto [key, val] : freq)
            keys.push_back(key);

        sort(keys.begin(), keys.end());

        dp[0] = keys[0] * freq[keys[0]];
        if (n == 1)
            return dp[0];
        if (keys[1] == keys[0] + 1)
            dp[1] = max(dp[0], keys[1] * freq[keys[1]]);
        else
            dp[1] = dp[0] + keys[1] * freq[keys[1]];

        for (int i = 2; i < n; i++)
        {
            int current = keys[i] * freq[keys[i]];

            if (keys[i] == keys[i - 1] + 1)
                dp[i] = max(dp[i - 1], dp[i - 2] + current);
            else
                dp[i] = dp[i - 1] + current;
        }

        return max(dp[n - 1], dp[n - 2]);
    }
};