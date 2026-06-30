// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// In this problem, we will be calculating the minimum price of the stock and the maximum profit that can be achieved by selling the stock at a later date. We will iterate through the list of prices, updating the minimum price and calculating the profit at each step. Finally, we will return the maximum profit.
// It is a greedy algorithm problem, where we make the locally optimal choice at each step (updating the minimum price and calculating the profit) in the hope that it will lead to a globally optimal solution (the maximum profit).

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minimum = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            minimum = min(minimum, prices[i]);
            profit = max(profit, prices[i] - minimum);
        }
        return profit;
    }
};