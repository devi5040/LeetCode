class Solution
{
public:
    vector<vector<int>> result;
    vector<int> temp;
    void buildSubsets(vector<int> &nums, int index)
    {
        result.push_back(temp);

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            buildSubsets(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        buildSubsets(nums, 0);
        return result;
    }
};