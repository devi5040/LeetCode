class Solution
{
public:
    bool solve(vector<int> &bloomDay, int m, int k, int currentDay)
    {
        int n = bloomDay.size();
        int currentFlowers = 0;
        int bouqueCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= currentDay)
            {
                currentFlowers++;
                if (currentFlowers == k)
                {
                    currentFlowers = 0;
                    bouqueCount++;
                }
            }
            else
                currentFlowers = 0;
        }

        return bouqueCount >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mini = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(bloomDay, m, k, mid))
            {
                mini = min(mini, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};