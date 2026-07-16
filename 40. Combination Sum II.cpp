class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> result;
    void makeCombination(vector<int> &candidates, int target, int index)
    {
        if (target == 0)
            result.push_back(temp);

        if (target <= 0)
            return;

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            makeCombination(candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        makeCombination(candidates, target, 0);
        return result;
    }
};