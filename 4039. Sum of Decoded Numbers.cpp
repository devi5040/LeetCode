class Solution
{
public:
    int sumDecoded(vector<long long> &nums)
    {
        int MOD = 1000000007;

        int sum = 0;
        for (long long num : nums)
        {
            long long n = num;

            long long width = n % 10;
            long long d = floor(n / 10);
            long long digits = 0;
            long long temp = d;

            while (temp)
            {
                digits++;
                temp /= 10;
            }

            int ydigits = (int)digits - (int)width;

            long long t = 1;
            for (int i = 0; i < ydigits; i++)
                t *= 10;

            long long x = d / t;
            long long y = d % t;

            long long ans = 1;
            while (y)
            {
                if (y & 1)
                    ans = ans * x % MOD;
                x = x * x % MOD;
                y >>= 1;
            }

            sum = (sum + ans) % MOD;
        }

        return sum;
    }
};