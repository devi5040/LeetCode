class Solution
{
public:
    int largestInteger(int n, int s)
    {
        if (s == 0)
            return 0;
        if (s > n * 9)
            return -1;
        int digit = 9;
        string ans;
        while (n--)
        {
            int digit = min(9, s);
            ans += char('0' + digit);
            s -= digit;
        }
        return stoi(ans);
    }
};