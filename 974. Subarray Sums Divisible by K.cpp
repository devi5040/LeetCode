//  Subarray Sums Divisible by K
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        frequency[0] = 1; // remainder 0 seen once

        int running_sum = 0;
        int count = 0;

        for(int num : nums)
        {
            running_sum += num;
            int rem = running_sum % k;

            if(rem < 0)
                rem += k; // normalize negative remainder

            if(frequency.count(rem))
                count += frequency[rem];

            frequency[rem]++;
        }

        return count;
    }
};
