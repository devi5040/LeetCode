class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> freq(101);
        vector<int> result;

        for (int x : nums)
            freq[x]++;
        int n = nums.size();
        while (result.size() < n)
        {
            for (int i = 1; i <= 100; i++)
            {
                if (freq[i] > 0)
                {
                    result.push_back(i);
                    freq[i]--;
                }
            }
        }

        return result;
    }
};