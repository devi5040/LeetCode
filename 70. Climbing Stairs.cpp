class Solution
{
public:
    int climbStairs(int n)
    {
        int num1 = 0, num2 = 1, temp;
        while (n--)
        {
            temp = num1;
            num1 = num2;
            num2 += temp;
        }
        return num2;
    }
};