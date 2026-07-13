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