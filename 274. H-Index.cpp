class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h_index = 0;

        sort(citations.begin(), citations.end());
        for(int i=n-1; i>=0; i--)
            if(citations[i]>=n-i)
                h_index = max(h_index, n-i);
        
        return h_index;
    }
};
