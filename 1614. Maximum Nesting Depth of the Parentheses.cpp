class Solution
{
public:
    int maxDepth(string s)
    {
        int max_count = 0, count = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                count++;
                max_count = max(max_count, count);
            }
            if (ch == ')')
                count--;
        }

        return max_count;
    }
};