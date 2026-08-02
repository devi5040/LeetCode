class Solution
{
public:
    int countRatioSubarrays(vector<int> &nums, int a, int b)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int even = 0, odd = 0;
            for (int j = i; j < n; j++)
            {
                nums[j] % 2 == 0 ? even++ : odd++;

                if (odd > 0 && (1LL * even * b <= 1LL * odd * a))
                    ans++;
            }
        }

        return ans;
    }
};