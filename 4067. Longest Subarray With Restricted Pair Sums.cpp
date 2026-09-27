class Solution
{
public:
    bool isInvalid(vector<int> &freq, int x)
    {
        for (int a = 1; a <= 500; a++)
        {
            if (freq[a] == 0)
                continue;
            int b = x - a;
            if (b < 1 || b > 500)
                continue;
            if (b == a)
            {
                if (freq[a] >= 2)
                    return true;
            }
            else
            {
                if (freq[b] > 0)
                    return true;
            }
        }

        for (int a = 1; a <= 500; a++)
        {
            if (freq[a] == 0)
                continue;
            int b = x + a;

            if (b > 500)
                continue;

            if (freq[b] > 0)
                return true;
        }

        return false;
    }
    int maxSubarray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> freq(501);

        int left = 0, ans = 0;
        for (int right = 0; right < n; right++)
        {
            int a = nums[right];

            while (isInvalid(freq, a))
            {
                freq[nums[left]]--;
                left++;
            }
            freq[a]++;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};