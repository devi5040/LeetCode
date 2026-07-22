class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int start1 = 0, start2 = 0;
        vector<vector<int>> res;
        while (start1 < firstList.size() && start2 < secondList.size())
        {
            int start = max(firstList[start1][0], secondList[start2][0]);
            int end = min(firstList[start1][1], secondList[start2][1]);
            if (start <= end)
                res.push_back({start, end});
            firstList[start1][1] < secondList[start2][1] ? start1++ : start2++;
        }
        return res;
    }
};