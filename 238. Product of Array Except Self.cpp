class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix, res;
        int n = nums.size();
        vector<int> suffix(n);
        int pre_prod = 1, suf_prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            pre_prod *= nums[i];
            suf_prod *= nums[nums.size() - 1 - i];
            prefix.push_back(pre_prod);
            suffix[n - 1 - i] = suf_prod;
        }

        res.push_back(suffix[1]);
        for (int i = 0; i < nums.size() - 2; i++)
        {
            res.push_back(prefix[i] * suffix[i + 2]);
        }
        res.push_back(prefix[nums.size() - 2]);

        return res;
    }
};
