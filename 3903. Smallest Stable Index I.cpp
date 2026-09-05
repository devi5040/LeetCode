class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> maximum(n);
        vector<int> minimum(n);
        int maxi = INT_MIN, mini = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[n - i - 1]);
            maximum[i] = maxi;
            minimum[n - i - 1] = mini;
        }

        for (int i = 0; i < n; i++)
        {
            int diff = maximum[i] - minimum[i];
            if (diff <= k)
                return i;
        }

        return -1;
    }
};