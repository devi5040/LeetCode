class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 4;
        int ans = 4;
        for (int i = 4; i <= n; i++)
            if (i == ans)
                ans *= 2;

        return ans;
    }
};