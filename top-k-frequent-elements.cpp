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


// Bucket sort (Optimal)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int max_val, max_index = 0;
        unordered_map<int, int> freq;
        vector<int> res;
        vector<vector<int>> bucket(nums.size()+1);
        for(int num: nums)
            freq[num]++;
        for(auto &it:freq)
            bucket[it.second].push_back(it.first);
        for(int i=nums.size(); i>=0 && res.size()<k; i--){
            for(int num: bucket[i]){
                res.push_back(num);
                if(res.size()==k)
                    return res;
            }
        }
        return res;
    }
};

// Heap technique (Priority queue)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int max_val, max_index = 0;
        unordered_map<int, int> freq;
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for(int num: nums)
            freq[num]++;
        for(auto &it:freq)
            pq.push({it.second, it.first});
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
