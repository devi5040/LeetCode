class Solution
{
public:
    bool canEat(vector<int> &piles, int hours, int mid)
    {
        long long total = 0;
        for (int num : piles)
            total += (num + mid - 1) / mid;
        ;
        return total <= hours;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int ans = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = ans;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid))
            {
                ans = mid;
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