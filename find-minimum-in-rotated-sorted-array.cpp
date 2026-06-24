class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1, minimum = INT_MAX;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (start == end)
                return nums[start];
            if (nums[mid] > nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        return 0;
    }
};