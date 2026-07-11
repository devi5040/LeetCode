class Solution
{
public:
    int count = 0;
    void expand(string &s, int left, int right)
    {
        while (left >= 0 && right <= s.size() && s[left] == s[right])
        {
            left--;
            right++;
            count++;
        }
    }
    int countSubstrings(string s)
    {
        int n = s.size();
        if (n <= 1)
            return n;
        for (int i = 0; i < s.size(); i++)
        {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return count;
    }
};