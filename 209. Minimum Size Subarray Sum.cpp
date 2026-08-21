class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, min_length = INT_MAX;
        int running_sum = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++)
        {
            running_sum += nums[right];
            while (running_sum >= target)
            {
                min_length = min(min_length, right - left + 1);
                running_sum -= nums[left++];
            }
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};