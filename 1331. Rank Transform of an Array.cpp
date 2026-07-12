class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> temp, result;
        temp = arr;
        sort(temp.begin(), temp.end());
        int rank = 1;
        unordered_map<int, int> mp;
        for (int t : temp)
        {
            if (mp.find(t) != mp.end())
                continue;
            mp[t] = rank;
            rank++;
        }
        for (int a : arr)
            result.push_back(mp[a]);
        return result;
    }
};