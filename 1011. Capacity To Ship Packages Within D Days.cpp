class Solution
{
public:
    bool check(int capacity, int requiredDays, vector<int> &weights)
    {
        int sum = 0, days = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (i == weights.size() - 1 || sum + weights[i + 1] > capacity)
            {
                days++;
                sum = 0;
            }
        }

        return days <= requiredDays;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int sum = 0;

        for (int weight : weights)
            sum += weight;

        int low = *max_element(weights.begin(), weights.end()), high = sum;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, days, weights))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};