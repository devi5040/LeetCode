class Solution
{
public:
    string reorganizeString(string s)
    {
        string res = "";
        vector<pair<int, char>> freq(26, {0, '\0'});
        priority_queue<pair<int, char>> pq;
        float n = (float)s.size();
        if (n == 1)
            return s;
        for (char ch : s)
        {
            freq[ch - 'a'].first++;
            freq[ch - 'a'].second = ch;
        }
        int limit = ceil(n / 2);
        for (int i = 0; i < freq.size(); i++)
            if (freq[i].first > 0)
                pq.push(freq[i]);
        if (pq.top().first > limit)
            return res;
        while (!pq.empty())
        {
            res += pq.top().second;
            int first = pq.top().first - 1;
            char first_char = pq.top().second;
            pq.pop();
            if (!pq.empty())
            {
                int second = pq.top().first - 1;
                char second_char = pq.top().second;
                res += second_char;
                pq.pop();
                if (first != 0)
                    pq.push({first, first_char});
                if (second != 0)
                    pq.push({second, second_char});
            }
        }
        return res;
    }
};