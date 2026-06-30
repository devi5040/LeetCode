class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int max_value = *max_element(costs.begin(), costs.end());
        vector<int> freq(max_value + 1, 0);
        for (int i = 0; i < costs.size(); i++)
        {
            freq[costs[i]]++;
        }
        long long total_sum = 0;
        int count = 0;
        for (int cost = 1; cost <= max_value; cost++)
        {
            if (freq[cost] == 0)
                continue;

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;
        }
        return count;
    }
};