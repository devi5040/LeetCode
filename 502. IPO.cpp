// Using priority queue
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = capital.size();
        int total_capital = w;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cap;
        for (int i = 0; i < n; i++)
            cap.push({capital[i], profits[i]});
        priority_queue<int> pro;

        while (k--)
        {
            while (!cap.empty() && cap.top().first <= total_capital)
            {
                pro.push(cap.top().second);
                cap.pop();
            }

            if (pro.empty())
                break;

            total_capital += pro.top();
            pro.pop();
        }

        return total_capital;
    }
};

// Using vector
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
            v.push_back({capital[i], profits[i]});

        sort(v.begin(), v.end());

        priority_queue<int> pq;
        int i = 0;
        while (i < n)
        {
            if (w >= v[i].first)
            {
                pq.push(v[i].second);
                i++;
            }
            else if (pq.empty() || k == 0)
                break;
            else
            {
                if (k > 0)
                {
                    w += pq.top();
                    pq.pop();
                    k--;
                }
            }
        }

        while (!pq.empty() && k > 0)
        {
            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};