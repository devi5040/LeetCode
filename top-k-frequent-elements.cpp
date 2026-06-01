class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int max_val, max_index = 0;
        unordered_map<int, int> freq;
        vector<int> res;
        for(int num: nums)
            freq[num]++;
        for(int i=0; i<k;i++){
            max_val = 0, max_index = 0;
            for(auto it: freq){
                max_val = max(max_val, it.second);
                if(max_val == it.second)
                    max_index = it.first;
            }
            freq.erase(max_index);
            res.push_back(max_index);
        }
        return res;
    }
};
