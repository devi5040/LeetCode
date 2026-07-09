class Solution
{
public:
    const long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        vector<int> result;
        if (s.empty())
            return result;

        int n = s.size();
        string stripped;
        stripped.reserve(n);
        vector<int> lenPrefix(n + 1, 0);
        vector<long long> sumPrefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '0')
                stripped += s[i];
            lenPrefix[i + 1] = stripped.size();
            sumPrefix[i + 1] = sumPrefix[i] + (s[i] - '0');
        }

        int m = stripped.size();
        vector<long long> prefixMod(m + 1, 0);
        vector<long long> pow10(m + 1, 1);
        for (int i = 0; i < m; ++i)
        {
            prefixMod[i + 1] = (prefixMod[i] * 10 + (stripped[i] - '0')) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        result.reserve(queries.size());
        for (const auto &v : queries)
        {
            int l = v[0], r = v[1];
            int start = lenPrefix[l];
            int end = lenPrefix[r + 1];
            int len = end - start;
            long long digitSum = sumPrefix[r + 1] - sumPrefix[l];

            if (len == 0 || digitSum == 0)
            {
                result.push_back(0);
                continue;
            }

            long long val = ((prefixMod[end] - prefixMod[start] * pow10[len]) % MOD + MOD) % MOD;
            long long ans = (val * (digitSum % MOD)) % MOD;
            result.push_back((int)ans);
        }
        return result;
    }
};