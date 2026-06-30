class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        vector<int> freq(26, 0);
        int m = s2.size();

        if (n > m)
            return false;

        for (int i = 0; i < n; i++)
        {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        if (freq == vector<int>(26, 0))
            return true;

        for (int i = n; i < m; i++)
        {
            freq[s2[i - n] - 'a']++;
            freq[s2[i] - 'a']--;
            if (freq == vector<int>(26, 0))
                return true;
        }
        return false;
    }
};

// Fully optimized code
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();

        if (n > m)
            return false;

        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
        {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        int mismatch = 0;
        for (int x : freq)
        {
            if (x != 0)
                mismatch++;
        }

        if (mismatch == 0)
            return true;

        for (int i = n; i < m; i++)
        {
            int out = s2[i - n] - 'a';
            int in = s2[i] - 'a';

            // Remove outgoing character
            if (freq[out] == 0)
                mismatch++;
            freq[out]++;
            if (freq[out] == 0)
                mismatch--;

            // Add incoming character
            if (freq[in] == 0)
                mismatch++;
            freq[in]--;
            if (freq[in] == 0)
                mismatch--;

            if (mismatch == 0)
                return true;
        }

        return false;
    }
};