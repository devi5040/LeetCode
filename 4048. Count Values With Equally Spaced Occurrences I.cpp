class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_map<int, pair<int, vector<int>>> freq;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]].first++;
            freq[nums[i]].second.push_back(i);
        }

        int count = 0;
        for (auto [key, value] : freq)
        {
            if (value.first != 3)
                continue;
            vector<int> temp = value.second;
            if (temp[2] - temp[1] == temp[1] - temp[0])
                count++;
        }

        return count;
    }
};