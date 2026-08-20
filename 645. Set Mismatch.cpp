class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;

        while (i < n)
        {
            int correctIndex = nums[i] - 1;

            if (nums[i] != nums[correctIndex])
            {
                swap(nums[i], nums[correctIndex]);
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return {nums[i], i + 1};
            }
        }

        return {};
    }
};