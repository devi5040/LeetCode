class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        vector<int> freq(26);
        int start = 0, maxLength = 0;

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            while (freq[s[i] - 'a'] > 2)
            {
                freq[s[start] - 'a']--;
                start++;
            }
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};