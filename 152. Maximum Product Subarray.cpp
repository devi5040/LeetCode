class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {

            int cur = nums[i];

            int tempMax = max({cur,
                               cur * maxProd,
                               cur * minProd});

            int tempMin = min({cur,
                               cur * maxProd,
                               cur * minProd});

            maxProd = tempMax;
            minProd = tempMin;

            ans = max(ans, maxProd);
        }

        return ans;
    }
};