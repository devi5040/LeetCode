class Solution
{
public:
    long long maxValue(vector<int> &nums)
    {
        int n = nums.size();

        long long original = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                original += nums[i];
            else
                original -= nums[i];
        }

        vector<long long> b(n);

        for (int i = 0; i < n; i++)
            b[i] = (i % 2 == 0 ? nums[i] : -nums[i]);

        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + b[i];

        long long maxPrefix[2] = {0, LLONG_MIN};
        long long minEvenSum = LLONG_MAX;

        for (int i = 1; i <= n; i++)
        {
            int parity = i % 2;

            if (maxPrefix[parity] != LLONG_MIN)
            {
                minEvenSum = min(minEvenSum, prefix[i] - maxPrefix[parity]);
            }

            maxPrefix[parity] = max(maxPrefix[parity], prefix[i]);
        }

        if (minEvenSum == LLONG_MAX)
            return original;
        long long gain = -2 * minEvenSum;

        return original + max(0LL, gain);
    }
};