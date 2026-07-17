class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal + 1);

        for (int x : nums)
            freq[x]++;

        vector<int> divisible(maxVal + 1);

        for (int i = 1; i <= maxVal; i++)
        {
            for (int j = i; j <= maxVal; j += i)
            {
                divisible[i] += freq[j];
            }
        }

        vector<long long> gcdCount(maxVal + 1);

        for (int i = maxVal; i >= 1; i--)
        {

            long long cnt = divisible[i];

            gcdCount[i] = cnt * (cnt - 1) / 2;

            for (int j = 2 * i; j <= maxVal; j += i)
            {
                gcdCount[i] -= gcdCount[j];
            }
        }

        vector<long long> prefix(maxVal + 1);

        for (int i = 1; i <= maxVal; i++)
        {
            prefix[i] = prefix[i - 1] + gcdCount[i];
        }

        vector<int> ans;

        for (long long q : queries)
        {

            int l = 1, r = maxVal;

            while (l < r)
            {

                int mid = (l + r) / 2;

                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans.push_back(l);
        }

        return ans;
    }
};