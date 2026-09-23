class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int maxLength = INT_MIN, count = -1;
        int left = 0;
        int sum = 0, totalSum = 0;

        for (int num : nums)
            totalSum += num;

        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum > (totalSum - x))
            {
                sum -= nums[left];
                left++;
            }

            if (sum == totalSum - x)
            {
                count = nums.size() - (right - left + 1);
                break;
            }
        }

        return count;
    }
};