class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        int start = n;
        while (start)
        {
            string num = to_string(start);
            int product = 1;
            for (char ch : num)
                product *= ch - '0';
            if (product % t == 0)
                return start;
            start++;
        }
        return start;
    }
};