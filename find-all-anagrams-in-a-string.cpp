class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<int> required(26, 0);
        vector<int> freq(26, 0);
        int left = 0;
        vector<int> result;
        if (m < n)
            return result;
        for (int i = 0; i < n; i++)
        {
            required[p[i] - 'a']++;
            freq[s[i] - 'a']++;
        }
        if (required == freq)
            result.push_back(left);
        for (int right = n; right < m; right++)
        {
            freq[s[left] - 'a']--;
            left++;
            freq[s[right] - 'a']++;
            if (required == freq)
                result.push_back(left);
        }
        return result;
    }
};