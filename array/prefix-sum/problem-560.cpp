// Subarray sum equals k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, runningPrefix = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            runningPrefix += nums[i];
            if(freq.count(runningPrefix - k)>0)
                count += freq[runningPrefix - k];
            freq[runningPrefix]++;
        }
        return count;
    }
};