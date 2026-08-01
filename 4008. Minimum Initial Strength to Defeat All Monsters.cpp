class Solution
{
public:
    long long minInitialStrength(vector<int> &monsters, vector<vector<int>> &boosts)
    {

        int n = monsters.size();

        vector<long long> diff(n + 1, 0);

        for (auto &b : boosts)
        {
            int l = b[0];
            int r = b[1];
            int val = b[2];

            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }
        vector<long long> bonus(n);
        long long curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += diff[i];
            bonus[i] = curr;
        }
        long long need = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            long long must = max(0LL, 1LL * monsters[i] - bonus[i]);

            if (need == 0)
                need = must;
            else
                need = max(1LL * monsters[i] + need, must);
        }
        return need;
    }
};