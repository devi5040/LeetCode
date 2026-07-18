// bitwise solution
class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

// normal math solution
class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n > 0)
        {
            int rem = n % 2;
            n /= 2;
            count += rem;
        }
        return count;
    }
};