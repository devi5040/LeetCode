class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int maxLength = 0, start = 0;
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
            while (freq[nums[i]] > k)
            {
                freq[nums[start]]--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};