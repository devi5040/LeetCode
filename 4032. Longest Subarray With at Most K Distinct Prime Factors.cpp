class Solution
{
public:
    set<int> distinctFactors(int n)
    {
        set<int> fact;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                fact.insert(i);

                while (n % i == 0)
                    n /= i;
            }
        }

        if (n > 1)
            fact.insert(n);

        return fact;
    }
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        int start = 0, max_len = INT_MIN, dist = 0;

        for (int end = 0; end < n; end++)
        {
            set<int> f = distinctFactors(nums[end]);

            for (int prime : f)
            {
                if (freq[prime] == 0)
                    dist++;
                freq[prime]++;
            }

            while (dist > k)
            {
                set<int> factors;
                factors = distinctFactors(nums[start]);

                for (int prime : factors)
                {
                    freq[prime]--;
                    if (freq[prime] == 0)
                    {
                        freq.erase(prime);
                        dist--;
                    }
                }

                start++;
            }
            max_len = max(max_len, end - start + 1);
        }

        return max_len;
    }
};