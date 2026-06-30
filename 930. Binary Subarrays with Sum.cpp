// Binary subarrays with sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int running_sum = 0, count = 0;
        unordered_map<int,int> frequency;
        frequency[0] = 1;
        for(int i=0;i<nums.size();i++){
            running_sum += nums[i];
            if(frequency.count(running_sum-goal)){
                count+=frequency[running_sum-goal];
            }
            frequency[running_sum]++;
        }
        return count;
    }
};