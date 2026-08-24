class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int left = 0, right = 0, n = nums.size();
        int count = 0;

        for (int end = n - 1; end > 1; end--)
        {
            left = 0;
            right = end - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[end])
                {
                    count += right - left;
                    right--;
                }
                else
                    left++;
            }
        }

        return count;
    }
};