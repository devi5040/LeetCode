class Solution
{
public:
    int atMostK(vector<int> &nums, int k)
    {
        if (k == 0)
            return 0;

        unordered_map<int, int> freq;
        int start = 0;
        int count = 0;

        for (int end = 0; end < nums.size(); end++)
        {
            freq[nums[end]]++;

            while (freq.size() > k)
            {
                freq[nums[start]]--;

                if (freq[nums[start]] == 0)
                    freq.erase(nums[start]);

                start++;
            }

            count += end - start + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};