class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        unordered_set<int> set;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            if (freq.count(num) && freq[num] != i - 1)
                set.insert(num);

            freq[num] = i;
        }

        unordered_set<int> distinct(nums.begin(), nums.end());

        return distinct.size() - set.size();
    }
};