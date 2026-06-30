class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0;
        vector<int> freq(3, 0);
        int distinct = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right] - 'a']++;
            if (freq[s[right] - 'a'] == 1)
                distinct++;
            while (distinct == 3)
            {
                count += (s.size() - right);
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }
        }
        return count;
    }
};