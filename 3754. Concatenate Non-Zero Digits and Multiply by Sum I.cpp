class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        string x = "";
        int num = n, rem;
        long long run_sum = 0;
        if (n == 0)
            return 0;
        while (num > 0)
        {
            rem = num % 10;
            num /= 10;
            if (rem != 0)
            {
                char ch = '0' + rem;
                x = ch + x;
                run_sum += (long long)rem;
            }
        }
        return stoi(x) * run_sum;
    }
};