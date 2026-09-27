class Solution
{
public:
    bool canTransform(vector<int> &source, vector<int> &target)
    {
        long long targetSum = 0;
        long long srcSum = 0;

        for (int s : source)
            srcSum += s;

        for (int t : target)
            targetSum += t;

        return srcSum == targetSum;
    }
};