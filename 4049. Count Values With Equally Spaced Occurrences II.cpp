class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_map<int, pair<int, pair<int, int>>> freq;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (freq.find(x) == freq.end())
                freq[x] = {1, {0, i}};
            else
            {
                int count = freq[x].first;
                int gap = freq[x].second.first;
                int prev = freq[x].second.second;

                int cur = i - prev;
                if (count == 1)
                    freq[x].second.first = cur;
                else if (gap != cur)
                    freq[x].second.first = -1;

                freq[x].first++;
                freq[x].second.second = i;
            }
        }

        int count = 0;

        for (auto [key, value] : freq)
        {
            int occurences = value.first;
            int gap = value.second.first;

            if (occurences >= 3 && gap != -1)
                count++;
        }

        return count;
    }
};