class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int start = nums[0];

        for (int i = 0; i < n; i++)
        {
            while (nums[i] != start)
            {
                result.push_back(start);
                start++;
            }
            start++;
        }

        return result;
    }
};