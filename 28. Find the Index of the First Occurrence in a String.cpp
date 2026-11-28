class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();

        if (n > m)
            return -1;

        for (int i = 0; i <= m - n; i++)
        {
            string sub = haystack.substr(i, n);
            if (sub == needle)
                return i;
        }

        return -1;
    }
};