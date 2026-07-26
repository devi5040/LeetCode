class Solution
{
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>> &series1, vector<vector<int>> &series2)
    {
        int pointer1 = 0, pointer2 = 0;
        vector<vector<int>> result;
        vector<int> timestamp;
        int m = series1.size(), n = series2.size();
        while (pointer1 < m && pointer2 < n)
        {
            if (series1[pointer1][0] == series2[pointer2][0])
            {
                timestamp.push_back(series1[pointer1][0]);
                pointer1++;
                pointer2++;
            }
            else if (series1[pointer1][0] < series2[pointer2][0])
            {
                int t = series1[pointer1][0];
                timestamp.push_back(t);
                pointer1++;
            }
            else
            {
                int t = series2[pointer2][0];
                timestamp.push_back(t);
                pointer2++;
            }
        }
        while (pointer1 < m)
        {
            timestamp.push_back(series1[pointer1][0]);
            pointer1++;
        }
        while (pointer2 < n)
        {
            timestamp.push_back(series2[pointer2][0]);
            pointer2++;
        }

        int start1 = 0, start2 = 0;

        for (int t : timestamp)
        {
            while (start1 < m && series1[start1][0] < t)
                start1++;
            while (start2 < n && series2[start2][0] < t)
                start2++;

            long long s1 = (start1 < m) ? series1[start1][1] : 0;
            long long s2 = (start2 < n) ? series2[start2][1] : 0;

            result.push_back({t, (int)s1 + (int)s2});
        }

        return result;
    }
};