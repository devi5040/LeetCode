// Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int runningSum = 0;
        unordered_map<int, int> freq;
        for(int i=0;i<nums.size();i++)
        {
            runningSum += nums[i];
            if(runningSum%k==0 && i>=1)
                return true;
            if(freq.count(runningSum%k))
            {
                if(i-freq[runningSum%k]>=2)
                    return true;
            } 
            else
                freq[runningSum%k]=i;
        }
        return false;
    }
};