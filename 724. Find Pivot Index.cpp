// Find Pivot index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSums;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            prefixSums.push_back(sum);
        };
        for(int i=0;i<nums.size();i++)
        {
            int leftSum = 0;
            if(i!=0)
                leftSum = prefixSums[i-1];
            int rightSum = prefixSums[nums.size()-1] - prefixSums[i];
            if(leftSum==rightSum) return i;
        }
        return -1;
    }
};