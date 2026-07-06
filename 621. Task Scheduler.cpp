class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        int m = tasks.size();
        int maxFreq = 0, maxCount = 0;
        for (int i = 0; i < tasks.size(); i++)
            freq[tasks[i] - 'A']++;
        sort(freq.begin(), freq.end());
        maxFreq = freq[25];
        int start = 25;
        while (start >= 0 && freq[start] == maxFreq)
        {
            maxCount++;
            start--;
        }
        int skeleton = ((maxFreq - 1) * (n + 1)) + maxCount;
        int interval = max(skeleton, m);
        return interval;
    }
};