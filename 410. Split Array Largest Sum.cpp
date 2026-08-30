class Solution
{
public:
    bool solve(vector<int> &nums, int k, int x)
    {
        int sum = 0, splits = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (i == n - 1 || sum + nums[i + 1] > x)
            {
                splits++;
                sum = 0;
            }
        }

        return splits <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int sum = 0, ans = INT_MAX;

        for (int num : nums)
            sum += num;

        int low = *max_element(nums.begin(), nums.end()), high = sum;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(nums, k, mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};