class Solution
{
public:
    bool canReach(vector<int> &start, vector<int> &target)
    {
        return ((target[1] - start[1]) + (target[0] - start[0])) % 2 == 0;
    }
};