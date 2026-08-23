class Solution
{
public:
    vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower, int upper)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        long long prev = lower - 1;

        for (int num : nums)
        {
            if (num < lower)
                continue;
            if (num > upper)
                break;

            if (num > prev + 1)
                result.push_back({(int)prev + 1, num - 1});

            prev = num;
        }

        if (prev < upper)
            result.push_back({(int)prev + 1, upper});

        return result;
    }
};