class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1, idx = n - 1;
        vector<int> array(n);

        while (left <= right)
        {
            if (abs(nums[left]) < abs(nums[right]))
            {
                array[idx] = nums[right] * nums[right];
                right--;
                idx--;
            }
            else
            {
                array[idx] = nums[left] * nums[left];
                left++;
                idx--;
            }
        }

        return array;
    }
};