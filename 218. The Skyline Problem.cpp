class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {

        vector<tuple<int, int, int>> events;

        for (auto &b : buildings)
        {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], 0, 0});
        }

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> pq;
        pq.push({0, INT_MAX});

        vector<vector<int>> ans;

        for (auto &[x, negH, right] : events)
        {

            while (!pq.empty() && pq.top().second <= x)
                pq.pop();

            if (negH != 0)
                pq.push({-negH, right});

            int curHeight = pq.top().first;

            if (ans.empty() || ans.back()[1] != curHeight)
                ans.push_back({x, curHeight});
        }

        return ans;
    }
};