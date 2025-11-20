// Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_length = 0;
        int running_sum = 0;
        unordered_map<int, int> index;
        index[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                running_sum+=-1;
            if(nums[i]==1)
                running_sum+=1;
            if(index.count(running_sum)){
                int length = i - index[running_sum];
                if(length > max_length)
                    max_length = length;
            }
            else
                index[running_sum] = i;
        }
        return max_length;
    }
};