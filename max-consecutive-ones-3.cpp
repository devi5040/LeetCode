class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxFreq = 0, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 1)
                maxFreq++;
            while (maxFreq + k < (right - left + 1))
            {
                if (nums[left] == 1)
                    maxFreq--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// Count zeroes method
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int zeros = 0;

        for (int right = 0; right < nums.size(); right++)
        {

            if (nums[right] == 0)
                zeros++;

            while (zeros > k)
            {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }
        }

        return nums.size() - left;
    }
};