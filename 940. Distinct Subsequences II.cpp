class Solution
{
public:
    int distinctSubseqII(string s)
    {
        const int MOD = 1000000007;

        vector<long long> dp(26, 0);
        long long total = 0;

        for (char c : s)
        {
            int num = c - 'a';

            long long count = (total + 1) % MOD;
            total = (total + count - dp[num] + MOD) % MOD;
            dp[num] = count;
        }

        return (int)total;
    }
};