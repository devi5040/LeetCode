class Solution
{
public:
    vector<vector<int>> result;
    vector<int> temp;

    void solve(int num, int k, int n)
    {
        if (temp.size() == k)
        {
            result.push_back(temp);
            return;
        }

        for (int i = num; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, k, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        solve(1, k, n);
        return result;
    }
};