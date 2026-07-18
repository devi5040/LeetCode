class Solution
{
public:
    int reverseBits(int n)
    {
        int cap = 32, count = 0;
        while (cap--)
        {
            count = count << 1;
            int rem = n % 2;
            count = count | rem;
            n = n >> 1;
        }
        return count;
    }
};