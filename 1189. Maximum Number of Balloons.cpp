class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int n = text.size();
        vector<int> target = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector<int> freq(26, 0);
        int count = INT_MAX;
        for (int i = 0; i < n; i++)
            freq[text[i] - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (target[i] == 0)
                continue;
            count = min(count, (freq[i] / target[i]));
        }
        return count;
    }
};

// Simplified solution
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> freq(26, 0);

        for (char c : text)
            freq[c - 'a']++;

        return min({freq['b' - 'a'],
                    freq['a' - 'a'],
                    freq['l' - 'a'] / 2,
                    freq['o' - 'a'] / 2,
                    freq['n' - 'a']});
    }
};