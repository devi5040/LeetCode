class Solution
{
public:
    void expand(string &s, int left, int right,
                int &start, int &maxLen)
    {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right])
        {
            left--;
            right++;
        }

        int len = right - left - 1;

        if (len > maxLen)
        {
            maxLen = len;
            start = left + 1;
        }
    }

    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.size(); i++)
        {
            expand(s, i, i, start, maxLen);     // Odd length
            expand(s, i, i + 1, start, maxLen); // Even length
        }

        return s.substr(start, maxLen);
    }
};

// using dp
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        if (n == 1)
            return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1, start = 0;

        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // length 2
        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
            {
                maxLen = 2;
                dp[i][i + 1] = true;
                start = i;
            }

        // len 3
        for (int len = 3; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;

                    if (len > maxLen)
                    {
                        maxLen = len;
                        start = i;
                    }
                }
            }

        return s.substr(start, maxLen);
    }
};