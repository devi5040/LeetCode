class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        int max_value = 0;
        vector<int> prefixGCD;
        for (int num : nums)
        {
            max_value = max(max_value, num);
            prefixGCD.push_back(gcd(max_value, num));
        }

        sort(prefixGCD.begin(), prefixGCD.end(), greater<int>());

        int start = 0, end = prefixGCD.size() - 1;
        long long sum = 0;
        while (start < end)
        {
            int gcd_val = gcd(prefixGCD[start], prefixGCD[end]);
            sum += gcd_val;
            start++;
            end--;
        }
        return sum;
    }
};