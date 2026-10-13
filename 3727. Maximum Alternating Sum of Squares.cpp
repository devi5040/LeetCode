class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
            if (nums[i] < 0)
                nums[i] = abs(nums[i]);

        sort(nums.rbegin(), nums.rend());

        int start = 0, end = n - 1;
        long long max_sum = 0;
        bool add = true;

        while (start <= end)
        {
            if (add)
            {
                max_sum += (long long)(nums[start] * nums[start]);
                start++;
                add = false;
            }
            else
            {
                max_sum -= (long long)(nums[end] * nums[end]);
                end--;
                add = true;
            }
        }

        return max_sum;
    }
};