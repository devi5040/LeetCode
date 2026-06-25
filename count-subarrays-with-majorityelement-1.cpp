class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);

        int count = 0;
        for (int i = 0; i < n + 1; i++)
            for (int j = i + 1; j < n + 1; j++)
                if (prefix[j] > prefix[i])
                    count++;

        return count;
    }
};