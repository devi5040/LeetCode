class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size();
        vector<long long> d(n);
        long long k = (long long)k1 + k2;
        long long total = 0, mx = 0;

        for (int i = 0; i < n; i++)
        {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
            mx = max(mx, d[i]);
        }

        if (total <= k)
            return 0;

        // smallest T such that cost(T) <= k
        long long lo = 0, hi = mx;
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            long long cost = 0;
            for (long long x : d)
                cost += max(0LL, x - mid);
            if (cost <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long T = lo;
        long long cost = 0;
        for (long long x : d)
            cost += max(0LL, x - T);
        long long rem = k - cost;

        long long res = 0;
        for (long long x : d)
        {
            if (x >= T)
            {
                if (rem > 0)
                {
                    res += (T - 1) * (T - 1);
                    rem--;
                }
                else
                {
                    res += T * T;
                }
            }
            else
            {
                res += x * x;
            }
        }
        return res;
    }
};