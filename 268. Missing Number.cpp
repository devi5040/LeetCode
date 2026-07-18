class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = (nums.size() * (nums.size() + 1)) / 2;
        int running_sum = 0;
        for (int n : nums)
            running_sum += n;
        return sum - running_sum;
    }
};

// Bit manipulation
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= i;
            ans ^= nums[i];
        }
        return ans;
    }
};