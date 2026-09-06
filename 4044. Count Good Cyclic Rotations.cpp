class Solution
{
public:
    int countGoodRotations(vector<int> &nums)
    {
        int n = nums.size();

        long long sum = 0, total = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
            if (i < n / 2)
                sum += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (2LL * sum > total)
                count++;
            int num1 = nums[i];
            int num2 = nums[(i + n / 2) % n];

            sum -= num1;
            sum += num2;
        }

        return count;
    }
};