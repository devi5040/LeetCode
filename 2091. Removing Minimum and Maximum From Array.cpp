class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        int maxIndex = 0, minIndex = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
            if (nums[i] < nums[minIndex])
                minIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        return min({left + right - left + 1, n - 1 - right + left + 2, right - left + n - 1 - right + 1});
    }
};