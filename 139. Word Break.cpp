class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (const string &w : wordDict)
            {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.compare(start, w.length(), w) == 0)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> freq;
        int n = s.size();

        for (string str : wordDict)
            freq[str] = 0;

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[j] && freq.find(s.substr(j, i - j)) != freq.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};