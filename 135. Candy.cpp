class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int value = 0;

        vector<int> res(n,1);

        for(int i=1; i<n; i++)
            if(ratings[i]>ratings[i-1])
                res[i] += res[i-1];

        for(int i=n-2; i>=0; i--)
            if(ratings[i]>ratings[i+1])
                res[i] = max(1+res[i+1], res[i]);

        for(int num:res)
            value += num;

        return value;
    }
};
