class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> result;
        priority_queue<pair<double, vector<int>>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            double square_sum = (double)(points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({square_sum, points[i]});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};