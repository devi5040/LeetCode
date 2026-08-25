class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        int start = 0, end = n - 1;
        int score = 0;

        sort(tokens.begin(), tokens.end());

        while (start <= end)
        {
            if (tokens[start] <= power)
            {
                score++;
                power -= tokens[start++];
                continue;
            }
            if (score > 0 && end > start)
            {
                score--;
                power += tokens[end--];
            }
            else
                break;
        }

        return score;
    }
};