class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int answer = 1;
        for (int i = 1; i < n; i++)
        {
            for (int left = 0; left < i; left++)
            {
                if (nums[left] < nums[i])
                    if (dp[left] + 1 > dp[i])
                        dp[i] = dp[left] + 1;
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};

// O(nlogn)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> temp;
        temp.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return temp.size();
    }
};