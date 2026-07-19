class Solution
{
public:
    long long maximumValue(int n, int s, int m)
    {
        long long L = n - 1;
        if (L == 0)
            return s;
        long long pairsA = L / 2;
        long long maxA = s + pairsA * (m - 1LL);
        long long pairsB = (L - 1) / 2;
        long long maxB = s + m + pairsB * (m - 1LL);

        return max(maxA, maxB);
    }
};