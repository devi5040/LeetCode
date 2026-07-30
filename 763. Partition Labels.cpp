class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> freq(26);
        vector<int> ans;
        unordered_map<char, int> mp;
        int n = s.size();

        for (int i = 0; i < n; i++)
            mp[s[i]] = i;

        int maxIdx = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            maxIdx = max(maxIdx, mp[s[i]]);
            if (i == maxIdx)
            {
                ans.push_back(mp[s[i]] - start + 1);
                maxIdx = 0;
                start = i + 1;
            }
        }

        return ans;
    }
};