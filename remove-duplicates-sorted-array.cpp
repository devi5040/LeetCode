class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int current = nums[0], index = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > current)
            {
                current = nums[i];
                swap(nums[i], nums[index]);
                index++;
            }
        }

        return index;
    }
};