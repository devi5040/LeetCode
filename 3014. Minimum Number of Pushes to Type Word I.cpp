class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.size();
        int numPushes = 0, level = 1;

        while (n > 0)
        {
            int current = n >= 8 ? 8 : n;
            numPushes += (current * level);
            n -= 8;
            level++;
        }

        return numPushes;
    }
};