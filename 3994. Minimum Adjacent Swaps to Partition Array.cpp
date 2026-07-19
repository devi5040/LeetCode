class Solution
{
public:
    int minAdjacentSwaps(vector<int> &nums, int a, int b)
    {
        const long long MOD = 1000000007;

        long long count = 0, count1 = 0, count2 = 0;
        long long ans = 0;

        for (int n : nums)
        {
            int label = (n < a) ? 0 : (n <= b ? 1 : 2);
            if (label == 0)
                ans += count1 + count2;
            else if (label == 1)
                ans += count2;

            ans %= MOD;
            if (label == 0)
                count++;
            else if (label == 1)
                count1++;
            else
                count2++;
        }

        return (int)ans;
    }
};