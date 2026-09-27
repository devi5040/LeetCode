class Solution
{
public:
    int maxEqualAdjacentPairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                ans++;
        }
        map<pair<int, int>, int> mp;
        for (int i = 1; i < n; i++)
        {
            int v1 = nums[i - 1];
            int v2 = nums[i];
            if (v1 == v2)
                continue;
            int n1 = min(v1, v2);
            int n2 = max(v1, v2);
            mp[{n1, n2}]++;
        }
        int extra = 0;
        for (auto p : mp)
        {
            extra = max(extra, p.second);
        }
        return ans + extra;
    }
};