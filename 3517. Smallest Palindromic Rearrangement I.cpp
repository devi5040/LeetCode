class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        int start = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;

            while (freq[i] > 1)
            {
                s[start] = 'a' + i;
                s[n - 1 - start] = 'a' + i;
                freq[i] -= 2;
                start++;
            }

            if (freq[i] == 1)
                s[n / 2] = 'a' + i;
        }

        return s;
    }
};