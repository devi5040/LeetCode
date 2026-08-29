class Solution
{
public:
    int solve(vector<int> &arr)
    {
        int n = arr.size();

        if (n < 2)
            return 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefix[i] = gcd(prefix[i - 1], arr[i]);

        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = gcd(suffix[i + 1], arr[i]);

        int score = 0;
        for (int i = 0; i < n - 1; i++)
            if (prefix[i] == suffix[i + 1])
                score++;

        return score;
    }
    int maxValidSplits(vector<int> &nums)
    {
        int n = nums.size();

        int ans = solve(nums);

        for (int i = 0; i < n; i++)
        {
            vector<int> arr;
            arr.reserve(n - 1);

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    arr.push_back(nums[j]);
            }
            ans = max(ans, solve(arr));
        }

        return ans;
    }
};