class Solution
{
public:
    int countValidPrefixes(string s)
    {
        int n = s.size();
        int numZeros = 0, numOnes = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            s[i] == '0' ? numZeros++ : numOnes++;
            if (abs(numZeros - numOnes) <= 1)
                count++;
        }
        return count;
    }
};