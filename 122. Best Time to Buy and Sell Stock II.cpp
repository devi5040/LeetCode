class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> hold(n);
        vector<int> cash(n);

        hold[0] = 0 - prices[0];
        cash[0] = 0;

        for (int i = 1; i < n; i++)
        {
            hold[i] = max(hold[i - 1], cash[i - 1] - prices[i]);
            cash[i] = max(cash[i - 1], hold[i - 1] + prices[i]);
        }

        return cash[n - 1];
    }
};