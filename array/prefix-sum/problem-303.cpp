// Range Sum Query - Immutable
class NumArray {
private: vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            prefix_sum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return prefix_sum[right];
        return prefix_sum[right]-prefix_sum[left-1];
    }
};