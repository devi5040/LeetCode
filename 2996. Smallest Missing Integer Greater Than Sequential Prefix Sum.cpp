class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] != nums[i - 1] + 1)
                break;
            sum += nums[i];
        }

        while (numSet.count(sum))
            sum++;
        return sum;
    }
};