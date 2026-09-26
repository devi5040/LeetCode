class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        string res = "";
        unordered_map<string, string> freq;

        for (vector<string> v : knowledge)
            freq[v[0]] = v[1];

        int start = 0;
        int n = s.size();

        while (start < n)
        {
            if (s[start] != '(')
            {
                res += s[start];
                start++;
                continue;
            }
            start++;
            string temp = "";
            while (s[start] != ')')
            {
                temp += s[start];
                start++;
            }
            if (freq.find(temp) == freq.end())
                res += "?";
            else
                res += freq[temp];
            start++;
        }

        return res;
    }
};