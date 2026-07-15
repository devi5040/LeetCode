class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        int oddSum = n * n;
        int evenSum = ((n * 2) * (n + 1)) / 2;
        return gcd(oddSum, evenSum);
    }
};