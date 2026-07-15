class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void makeCombination(int index, int target, vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        curr.push_back(candidates[index]);
        makeCombination(index, target - candidates[index], candidates);

        curr.pop_back();

        makeCombination(index + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        makeCombination(0, target, candidates);

        return ans;
    }
};